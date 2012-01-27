class PacketHandlerHelper;

#ifndef _PACKETHANDLERHELPER_H
#define _PACKETHANDLERHELPER_H

#include "IPacketHandler.h"
#include "PacketParser.h"

class PacketHandlerHelper : public IPacketHandler
{
public:
	PacketHandlerHelper(PacketParser *pPacketParser);

	void onAddObjectVehicle(int iEntity, unsigned char ucType, int iX, int iY, int iZ, int iUnk1, short unk2, short unk3, short unk4);
	void onAnimation(int iEntity, unsigned char ucAnimation);
	void onAttachEntity(int iEntity, int iVehicle);
	void onBlockAction(int iX, short y, int iZ, unsigned char ucType, unsigned char ucPitch);
	void onBlockChange(int iX, char cY, int iZ, unsigned char ucType, unsigned char ucMeta);
	void onChat(const std::wstring &wstrMessage);
	void onCollectItem(int iCollected, int iCollector);
	void onCreativeInventoryAction(short iSlot, short iItem, unsigned char ucQty, short iUses);
	void onDestroyEntity(int iEntity);
	void onEntity(int iEntity);
	void onEntityAction(int iEntity, unsigned char ucAction);
	void onEntityEffect(int iEntity, unsigned char ucEffect, unsigned char ucAmplifier, short iDuration);
	void onEntityLook(int iEntity, char cYaw, char cPitch);
	void onEntityLookRelativeMove(int iEntity, char cX, char cY, char cZ, char cYaw, char cPitch);
	void onEntityMetadata(int iEntity);
	void onEntityRelativeMove(int iEntity, char cX, char cY, char cZ);
	void onEntityStatus(int iEntity, unsigned char ucStatus);
	void onEntityTeleport(int iEntity, int iX, int iY, int iZ, char cYaw, char cPitch);
	void onEntityVelocity(int iEntity, short iVelX, short iVelY, short iVelZ);
	void onEquipment(int iEntity, short iSlot, short iItem, short iUnk);
	void onExperience(float fBar, short iLevel, short iTotal);
	void onExperienceOrb(int iEntity, int iX, int iY, int iZ, short iCount);
	void onExplosion(double dX, double dY, double dZ, float fRadius, int iCount);
	void onHealthUpdate(short iHealth, short iFood, float fSaturation);
	void onHoldingChange(short iSlot);
	void onIncrementStatistic(int iStatistic, unsigned char ucAmount);
	void onItemData(short iType, short iID, unsigned char ucLength);
	void onPluginMessage(const std::wstring &wstrChannel, short iLength);
	void onKick(const std::wstring &wstrMessage);
	void onMapChunk(int iX, short y, int iZ, char cSX, char cSY, char cSZ, int iSize);
	void onMobSpawn(int iEntity, unsigned char ucType, int iX, int iY, int iZ, char cYaw, char cPitch);
	void onMultiBlockChange(int iX, int iZ, short iSize);
	void onNamedEntitySpawn(int iEntity, const std::wstring &wstrName, int iX, int iY, int iZ, char cRot, char cPitch, short iItem);
	void onNewInvalidState(unsigned char ucReason, unsigned char ucGamemode);
	void onOpenWindow(unsigned char ucWindow, unsigned char ucType, const std::wstring &wstrTitle, unsigned char ucNumSlots);
	void onPacket01(int iEntity, const std::wstring &wstrUnused, __int64 iSeed, const std::wstring &wstrLevelType, int iMode, unsigned char ucDimension, unsigned char ucDifficulty, unsigned char ucHeight, unsigned char ucMaxPlayers);
	void onHandshake(const std::wstring &wstrHash);
	void onPainting(int iEntity, const std::wstring &wstrTitle, int iX, int iY, int iZ, int iDirection);
	void onPickupSpawn(int iEntity, short iItem, unsigned char ucCount, short iDamage, int iX, int iY, int iZ, char cRot, char cPitch, char cRoll);
	void onKeepAlive(int iRandom);
	void onPlayerBlockPlacement(int iX, char cY, int iZ, unsigned char ucDirection, short iBlockItem, unsigned char ucQty, short iDamage);
	void onPlayerDigging(unsigned char ucStatus, int iX, char cY, int iZ, unsigned char ucFace);
	void onPlayerListItem(const std::wstring &wstrName, bool bOnline, short iPing);
	void onPlayerPositionLook(double dX, double dStance, double dY, double dZ, float fYaw, float fPitch, bool bGround);
	void onPreChunk(int iX, int iZ, bool bInit);
	void onRemoveEntityEffect(int iEntity, unsigned char ucEffect);
	void onRespawn(unsigned char ucDimension, unsigned char ucDifficulty, bool bCreative, short iMaxHeight, __int64 iSeed, const std::wstring &wstrLevelType);
	void onSoundEffect(int iEffect, int iX, char cY, int iZ, int iData);
	void onSpawnPosition(int iX, int iY, int iZ);
	void onThunderbolt(int iEntity, bool bUnk, int iX, int iY, int iZ);
	void onTimeUpdate(__int64 iTime);
	void onTransaction(unsigned char ucWindow, short iActionNumber, bool bAccepted);
	void onUpdateSign(int iX, short iY, int iZ, const std::wstring &wstrLine1, const std::wstring &wstrLine2, const std::wstring &wstrLine3, const std::wstring &wstrLine4);
	void onUseBed(int iEntity, bool bInBed, int iX, char cY, int iZ);
	void onUseEntity(int iUser, int iTarget, bool bLeftClick);
	void onWindowClose(unsigned char ucWindow);
	void onWindowItems(unsigned char ucWindow, short iCount);
	void onWindowProperty(unsigned char ucWindow, short iProperty, short iValue);
	void onWindowSlot(unsigned char ucWindow, short iSlot, short iItem, unsigned char ucQty, short iUses);

private:
	PacketParser *m_pPacketParser;
};

#endif
