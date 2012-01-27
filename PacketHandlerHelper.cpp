#include "StdInc.h"
#include "PacketHandlerHelper.h"

#define MASS_EVENT(method, ...) \
	for (std::list<IPacketHandler *>::iterator i = m_pPacketParser->m_lstPacketHandlers.begin(); i != m_pPacketParser->m_lstPacketHandlers.end(); ++i) \
	{ \
		if (*i != NULL) \
			(*i)->method(__VA_ARGS__); \
	}

PacketHandlerHelper::PacketHandlerHelper(PacketParser *pPacketParser)
	: m_pPacketParser(pPacketParser)
{
}

void PacketHandlerHelper::onAddObjectVehicle(int iEntity, unsigned char ucType, int iX, int iY, int iZ, int iUnk1, short unk2, short unk3, short unk4) { MASS_EVENT(onAddObjectVehicle, iEntity, ucType, iX, iY, iZ, iUnk1, unk2, unk3, unk4) }
void PacketHandlerHelper::onAnimation(int iEntity, unsigned char ucAnimation) { MASS_EVENT(onAnimation, iEntity, ucAnimation) }
void PacketHandlerHelper::onAttachEntity(int iEntity, int iVehicle) { MASS_EVENT(onAttachEntity, iEntity, iVehicle) }
void PacketHandlerHelper::onBlockAction(int iX, short y, int iZ, unsigned char ucType, unsigned char ucPitch) { MASS_EVENT(onBlockAction, iX, y, iZ, ucType, ucPitch) }
void PacketHandlerHelper::onBlockChange(int iX, char cY, int iZ, unsigned char ucType, unsigned char ucMeta) { MASS_EVENT(onBlockChange, iX, cY, iZ, ucType, ucMeta) }
void PacketHandlerHelper::onChat(const std::wstring &wstrMessage) { MASS_EVENT(onChat, wstrMessage) }
void PacketHandlerHelper::onCollectItem(int iCollected, int iCollector) { MASS_EVENT(onCollectItem, iCollected, iCollector) }
void PacketHandlerHelper::onCreativeInventoryAction(short iSlot, short iItem, unsigned char ucQty, short iUses) { MASS_EVENT(onCreativeInventoryAction, iSlot, iItem, ucQty, iUses) }
void PacketHandlerHelper::onDestroyEntity(int iEntity) { MASS_EVENT(onDestroyEntity, iEntity) }
void PacketHandlerHelper::onEntity(int iEntity) { MASS_EVENT(onEntity, iEntity) }
void PacketHandlerHelper::onEntityAction(int iEntity, unsigned char ucAction) { MASS_EVENT(onEntityAction, iEntity, ucAction) }
void PacketHandlerHelper::onEntityEffect(int iEntity, unsigned char ucEffect, unsigned char ucAmplifier, short iDuration) { MASS_EVENT(onEntityEffect, iEntity, ucEffect, ucAmplifier, iDuration) }
void PacketHandlerHelper::onEntityLook(int iEntity, char cYaw, char cPitch) { MASS_EVENT(onEntityLook, iEntity, cYaw, cPitch) }
void PacketHandlerHelper::onEntityLookRelativeMove(int iEntity, char cX, char cY, char cZ, char cYaw, char cPitch) { MASS_EVENT(onEntityLookRelativeMove, iEntity, cX, cY, cZ, cYaw, cPitch) }
void PacketHandlerHelper::onEntityMetadata(int iEntity) { MASS_EVENT(onEntityMetadata, iEntity) }
void PacketHandlerHelper::onEntityRelativeMove(int iEntity, char cX, char cY, char cZ) { MASS_EVENT(onEntityRelativeMove, iEntity, cX, cY, cZ) }
void PacketHandlerHelper::onEntityStatus(int iEntity, unsigned char ucStatus) { MASS_EVENT(onEntityStatus, iEntity, ucStatus) }
void PacketHandlerHelper::onEntityTeleport(int iEntity, int iX, int iY, int iZ, char cYaw, char cPitch) { MASS_EVENT(onEntityTeleport, iEntity, iX, iY, iZ, cYaw, cPitch) }
void PacketHandlerHelper::onEntityVelocity(int iEntity, short iVelX, short iVelY, short iVelZ) { MASS_EVENT(onEntityVelocity, iEntity, iVelX, iVelY, iVelZ) }
void PacketHandlerHelper::onEquipment(int iEntity, short iSlot, short iItem, short iUnk) { MASS_EVENT(onEquipment, iEntity, iSlot, iItem, iUnk) }
void PacketHandlerHelper::onExperience(float fBar, short iLevel, short iTotal) { MASS_EVENT(onExperience, fBar, iLevel, iTotal) }
void PacketHandlerHelper::onExperienceOrb(int iEntity, int iX, int iY, int iZ, short iCount) { MASS_EVENT(onExperienceOrb, iEntity, iX, iY, iZ, iCount) }
void PacketHandlerHelper::onExplosion(double dX, double dY, double dZ, float fRadius, int iCount) { MASS_EVENT(onExplosion, dX, dY, dZ, fRadius, iCount) }
void PacketHandlerHelper::onHealthUpdate(short iHealth, short iFood, float fSaturation) { MASS_EVENT(onHealthUpdate, iHealth, iFood, fSaturation) }
void PacketHandlerHelper::onHoldingChange(short iSlot) { MASS_EVENT(onHoldingChange, iSlot) }
void PacketHandlerHelper::onIncrementStatistic(int iStatistic, unsigned char ucAmount) { MASS_EVENT(onIncrementStatistic, iStatistic, ucAmount) }
void PacketHandlerHelper::onItemData(short iType, short iID, unsigned char ucLength) { MASS_EVENT(onItemData, iType, iID, ucLength) }
void PacketHandlerHelper::onPluginMessage(const std::wstring &wstrChannel, short iLength) { MASS_EVENT(onPluginMessage, wstrChannel, iLength) }
void PacketHandlerHelper::onKick(const std::wstring &wstrMessage) { MASS_EVENT(onKick, wstrMessage) }
void PacketHandlerHelper::onMapChunk(int iX, short y, int iZ, char cSX, char cSY, char cSZ, int iSize) { MASS_EVENT(onMapChunk, iX, y, iZ, cSX, cSY, cSZ, iSize) }
void PacketHandlerHelper::onMobSpawn(int iEntity, unsigned char ucType, int iX, int iY, int iZ, char cYaw, char cPitch) { MASS_EVENT(onMobSpawn, iEntity, ucType, iX, iY, iZ, cYaw, cPitch) }
void PacketHandlerHelper::onMultiBlockChange(int iX, int iZ, short iSize) { MASS_EVENT(onMultiBlockChange, iX, iZ, iSize) }
void PacketHandlerHelper::onNamedEntitySpawn(int iEntity, const std::wstring &wstrName, int iX, int iY, int iZ, char cRot, char cPitch, short iItem) { MASS_EVENT(onNamedEntitySpawn, iEntity, wstrName, iX, iY, iZ, cRot, cPitch, iItem) }
void PacketHandlerHelper::onNewInvalidState(unsigned char ucReason, unsigned char ucGamemode) { MASS_EVENT(onNewInvalidState, ucReason, ucGamemode) }
void PacketHandlerHelper::onOpenWindow(unsigned char ucWindow, unsigned char ucType, const std::wstring &wstrTitle, unsigned char ucNumSlots) { MASS_EVENT(onOpenWindow, ucWindow, ucType, wstrTitle, ucNumSlots) }
void PacketHandlerHelper::onPacket01(int iEntity, const std::wstring &wstrUnused, __int64 iSeed, const std::wstring &wstrLevelType, int iMode, unsigned char ucDimension, unsigned char ucDifficulty, unsigned char ucHeight, unsigned char ucMaxPlayers) { MASS_EVENT(onPacket01, iEntity, wstrUnused, iSeed, wstrLevelType, iMode, ucDimension, ucDifficulty, ucHeight, ucMaxPlayers) }
void PacketHandlerHelper::onHandshake(const std::wstring &wstrHashOrUsername) { MASS_EVENT(onHandshake, wstrHashOrUsername) }
void PacketHandlerHelper::onPainting(int iEntity, const std::wstring &wstrTitle, int iX, int iY, int iZ, int iDirection) { MASS_EVENT(onPainting, iEntity, wstrTitle, iX, iY, iZ, iDirection) }
void PacketHandlerHelper::onPickupSpawn(int iEntity, short iItem, unsigned char ucCount, short iDamage, int iX, int iY, int iZ, char cRot, char cPitch, char cRoll) { MASS_EVENT(onPickupSpawn, iEntity, iItem, ucCount, iDamage, iX, iY, iZ, cRot, cPitch, cRoll) }
void PacketHandlerHelper::onKeepAlive(int iRandom) { MASS_EVENT(onKeepAlive, iRandom) }
void PacketHandlerHelper::onPlayerBlockPlacement(int iX, char cY, int iZ, unsigned char ucDirection, short iBlockItem, unsigned char ucQty, short iDamage) { MASS_EVENT(onPlayerBlockPlacement, iX, cY, iZ, ucDirection, iBlockItem, ucQty, iDamage) }
void PacketHandlerHelper::onPlayerDigging(unsigned char ucStatus, int iX, char cY, int iZ, unsigned char ucFace) { MASS_EVENT(onPlayerDigging, ucStatus, iX, cY, iZ, ucFace) }
void PacketHandlerHelper::onPlayerListItem(const std::wstring &wstrName, bool bOnline, short iPing) { MASS_EVENT(onPlayerListItem, wstrName, bOnline, iPing) }
void PacketHandlerHelper::onPlayerPositionLook(double dX, double dStance, double dY, double dZ, float fYaw, float fPitch, bool bGround) { MASS_EVENT(onPlayerPositionLook, dX, dStance, dY, dZ, fYaw, fPitch, bGround) }
void PacketHandlerHelper::onPreChunk(int iX, int iZ, bool bInit) { MASS_EVENT(onPreChunk, iX, iZ, bInit) }
void PacketHandlerHelper::onRemoveEntityEffect(int iEntity, unsigned char ucEffect) { MASS_EVENT(onRemoveEntityEffect, iEntity, ucEffect) }
void PacketHandlerHelper::onRespawn(unsigned char ucDimension, unsigned char ucDifficulty, bool bCreative, short iMaxHeight, __int64 iSeed, const std::wstring &wstrLevelType) { MASS_EVENT(onRespawn, ucDimension, ucDifficulty, bCreative, iMaxHeight, iSeed, wstrLevelType) }
void PacketHandlerHelper::onSoundEffect(int iEffect, int iX, char cY, int iZ, int iData) { MASS_EVENT(onSoundEffect, iEffect, iX, cY, iZ, iData) }
void PacketHandlerHelper::onSpawnPosition(int iX, int iY, int iZ) { MASS_EVENT(onSpawnPosition, iX, iY, iZ) }
void PacketHandlerHelper::onThunderbolt(int iEntity, bool bUnk, int iX, int iY, int iZ) { MASS_EVENT(onThunderbolt, iEntity, bUnk, iX, iY, iZ) }
void PacketHandlerHelper::onTimeUpdate(__int64 iTime) { MASS_EVENT(onTimeUpdate, iTime) }
void PacketHandlerHelper::onTransaction(unsigned char ucWindow, short iActionNumber, bool bAccepted) { MASS_EVENT(onTransaction, ucWindow, iActionNumber, bAccepted) }
void PacketHandlerHelper::onUpdateSign(int iX, short iY, int iZ, const std::wstring &wstrLine1, const std::wstring &wstrLine2, const std::wstring &wstrLine3, const std::wstring &wstrLine4) { MASS_EVENT(onUpdateSign, iX, iY, iZ, wstrLine1, wstrLine2, wstrLine3, wstrLine4) }
void PacketHandlerHelper::onUseBed(int iEntity, bool bInBed, int iX, char cY, int iZ) { MASS_EVENT(onUseBed, iEntity, bInBed, iX, cY, iZ) }
void PacketHandlerHelper::onUseEntity(int iUser, int iTarget, bool bLeftClick) { MASS_EVENT(onUseEntity, iUser, iTarget, bLeftClick) }
void PacketHandlerHelper::onWindowClose(unsigned char ucWindow) { MASS_EVENT(onWindowClose, ucWindow) }
void PacketHandlerHelper::onWindowItems(unsigned char ucWindow, short iCount) { MASS_EVENT(onWindowItems, ucWindow, iCount) }
void PacketHandlerHelper::onWindowProperty(unsigned char ucWindow, short iProperty, short iValue) { MASS_EVENT(onWindowProperty, ucWindow, iProperty, iValue) }
void PacketHandlerHelper::onWindowSlot(unsigned char ucWindow, short iSlot, short iItem, unsigned char ucQty, short iUses) { MASS_EVENT(onWindowSlot, ucWindow, iSlot, iItem, ucQty, iUses) }
void PacketHandlerHelper::onWindowClick(unsigned char ucWindow, short iSlot, bool bRightClick, short iAction, bool bShift) { MASS_EVENT(onWindowClick, ucWindow, iSlot, bRightClick, iAction, bShift) }
void PacketHandlerHelper::onEnchantItem(unsigned char ucWindow, unsigned char ucEnchantment) { MASS_EVENT(onEnchantItem, ucWindow, ucEnchantment) }
void PacketHandlerHelper::onPlayer(bool bOnGround) { MASS_EVENT(onPlayer, bOnGround) }
void PacketHandlerHelper::onServerListPing() { MASS_EVENT(onServerListPing) }
void PacketHandlerHelper::onPlayerPosition(double dX, double dY, double dStance, double dZ, bool bGround) { MASS_EVENT(onPlayerPosition, dX, dY, dStance, dZ, bGround) }
void PacketHandlerHelper::onPlayerLook(float fYaw, float fPitch, bool bOnGround) { MASS_EVENT(onPlayerLook, fYaw, fPitch, bOnGround) }
