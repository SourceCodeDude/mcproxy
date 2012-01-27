class Packets;

#ifndef _PACKETS_H
#define _PACKETS_H

#include "Packet.h"
#include <map>

#include "packets/Packet01.h"
#include "packets/Packet02.h"
#include "packets/Ping.h"
#include "packets/TimeUpdate.h"
#include "packets/Equipment.h"
#include "packets/Chat.h"
#include "packets/SpawnPosition.h"
#include "packets/UseEntity.h"
#include "packets/HealthUpdate.h"
#include "packets/Respawn.h"
#include "packets/PlayerPositionLook.h"
#include "packets/PlayerDigging.h"
#include "packets/PlayerBlockPlacement.h"
#include "packets/HoldingChange.h"
#include "packets/UseBed.h"
#include "packets/Animation.h"
#include "packets/EntityAction.h"
#include "packets/NamedEntitySpawn.h"
#include "packets/PickupSpawn.h"
#include "packets/CollectItem.h"
#include "packets/AddObjectVehicle.h"
#include "packets/MobSpawn.h"
#include "packets/Painting.h"
#include "packets/ExperienceOrb.h"
#include "packets/EntityVelocity.h"
#include "packets/DestroyEntity.h"
#include "packets/Entity.h"
#include "packets/EntityRelativeMove.h"
#include "packets/EntityLook.h"
#include "packets/EntityLookRelativeMove.h"
#include "packets/EntityTeleport.h"
#include "packets/EntityStatus.h"
#include "packets/AttachEntity.h"
#include "packets/EntityMetadata.h"
#include "packets/EntityEffect.h"
#include "packets/RemoveEntityEffect.h"
#include "packets/Experience.h"
#include "packets/PreChunk.h"
#include "packets/MapChunk.h"
#include "packets/MultiBlockChange.h"
#include "packets/BlockChange.h"
#include "packets/BlockAction.h"
#include "packets/Explosion.h"
#include "packets/SoundEffect.h"
#include "packets/NewInvalidState.h"
#include "packets/Thunderbolt.h"
#include "packets/OpenWindow.h"
#include "packets/WindowClose.h"
#include "packets/WindowSlot.h"
#include "packets/WindowItems.h"
#include "packets/WindowProperty.h"
#include "packets/Transaction.h"
#include "packets/CreativeInventoryAction.h"
#include "packets/UpdateSign.h"
#include "packets/ItemData.h"
#include "packets/IncrementStatistic.h"
#include "packets/PlayerListItem.h"
#include "packets/PluginMessage.h"
#include "packets/Kick.h"

class Packets
{
private:
	Packets();

public:
	static void init();
	static Packet *createPacket(int iID);

private:
	typedef Packet *(* pfnPacket_t)();
	static pfnPacket_t m_packetFactory[256];
};

#endif
