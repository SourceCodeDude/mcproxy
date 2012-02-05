#!/bin/bash

g++ *.cpp packets/*.cpp misc/linux.cpp utils/*.cpp -I./ -I../cppsockets `../cppsockets/Sockets-config` ../cppsockets/libSockets.a -lcurl -lpthread -o mcproxy
