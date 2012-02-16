#include "convert.h"
#include <errno.h>
#include <stdlib.h>

int grow(char** output, size_t* outlen, char** outbuf, size_t* outbufsz) {
  size_t newlen;
  char *newptr;

  newlen = *outlen ? (*outlen * 2) : 16;
  if ((newptr = (char*) realloc(*output, newlen))) {
    *outbufsz = newlen - *outlen;
    *outbuf = newptr + (*outbuf - *output);

    *outlen = newlen;
    *output = newptr;

    return 1;
  }

  return 0;
}

/**
 * This function will clobber `output` and `outlen` on both success and error.
 */
int convert(iconv_t iv, char* input, size_t inlen, char** output, size_t* outlen) {
  char* inbuf;
  char* outbuf;
  size_t outbufsz;
  size_t inbufsz;
  size_t rv;

  inbufsz = inlen;
  inbuf = input;

  *outlen = outbufsz = 0;
  *output = outbuf = 0;

  // reset to initial state
  iconv(iv, 0, 0, 0, 0);

  // convert input
  do {
    if (grow(output, outlen, &outbuf, &outbufsz)) {
      rv = iconv(iv, (const char **) &inbuf, &inbufsz, &outbuf, &outbufsz);
    }
    else {
      goto error;
    }
  }
  while (rv == (size_t) -1 && errno == E2BIG);

  if (rv == (size_t) -1) {
    goto error;
  }

  // write out shift sequence
  rv = iconv(iv, 0, 0, &outbuf, &outbufsz);

  if (rv == (size_t) -1) {
    if (errno != E2BIG) {
      goto error;
    }
    if (!grow(output, outlen, &outbuf, &outbufsz)) {
      goto error;
    }
    if (iconv(iv, 0, 0, &outbuf, &outbufsz) == (size_t) -1) {
      goto error;
    }
  }

  // store length
  *outlen = outbuf - *output;

  // release unused trailing memory; this can't conceivably fail
  // because newlen <= oldlen but let's take the safe route anyway
  //
  // realloc() may free the memory and return NULL if *outlen == 0
  // but that's not an error, the caller should (and does) handle it
  // graciously
  //
  if ((outbuf = (char*) realloc(*output, *outlen)) || *outlen == 0) {
    *output = outbuf;
  }

  return 1;

error:
  free(*output);
  *output = 0;
  *outlen = 0;
  return 0;
}
