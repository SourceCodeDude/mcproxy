#include "StdInc.h"
#include "Packets.h"
#include "Packet.h"
#include <string.h>

Packets::pfnPacket_t Packets::m_packetFactory[256];

void Packets::init()
{
	memset(m_packetFactory, 0, sizeof(pfnPacket_t) * 256);

	m_packetFactory[0x00] = CreatePacket_Ping;
	m_packetFactory[0x01] = CreatePacket_Packet01;
	m_packetFactory[0x02] = CreatePacket_Packet02;
	m_packetFactory[0x03] = CreatePacket_Chat;
	m_packetFactory[0x04] = CreatePacket_TimeUpdate;
	m_packetFactory[0x05] = CreatePacket_Equipment;
	m_packetFactory[0x06] = CreatePacket_SpawnPosition;
	m_packetFactory[0x07] = CreatePacket_UseEntity;
	m_packetFactory[0x08] = CreatePacket_HealthUpdate;
	m_packetFactory[0x09] = CreatePacket_Respawn;
	m_packetFactory[0x0A] = CreatePacket_Player;
	m_packetFactory[0x0B] = CreatePacket_PlayerPosition;
	m_packetFactory[0x0C] = CreatePacket_PlayerLook;
	m_packetFactory[0x0D] = CreatePacket_PlayerPositionLook;
	m_packetFactory[0x0E] = CreatePacket_PlayerDigging;
	m_packetFactory[0x0F] = CreatePacket_PlayerBlockPlacement;
	m_packetFactory[0x10] = CreatePacket_HoldingChange;
	m_packetFactory[0x11] = CreatePacket_UseBed;
	m_packetFactory[0x12] = CreatePacket_Animation;
	m_packetFactory[0x13] = CreatePacket_EntityAction;
	m_packetFactory[0x14] = CreatePacket_NamedEntitySpawn;
	m_packetFactory[0x15] = CreatePacket_PickupSpawn;
	m_packetFactory[0x16] = CreatePacket_CollectItem;
	m_packetFactory[0x17] = CreatePacket_AddObjectVehicle;
	m_packetFactory[0x18] = CreatePacket_MobSpawn;
	m_packetFactory[0x19] = CreatePacket_Painting;
	m_packetFactory[0x1A] = CreatePacket_ExperienceOrb;
	m_packetFactory[0x1C] = CreatePacket_EntityVelocity;
	m_packetFactory[0x1D] = CreatePacket_DestroyEntity;
	m_packetFactory[0x1E] = CreatePacket_Entity;
	m_packetFactory[0x1F] = CreatePacket_EntityRelativeMove;
	m_packetFactory[0x20] = CreatePacket_EntityLook;
	m_packetFactory[0x21] = CreatePacket_EntityLookRelativeMove;
	m_packetFactory[0x22] = CreatePacket_EntityTeleport;
	m_packetFactory[0x26] = CreatePacket_EntityStatus;
	m_packetFactory[0x27] = CreatePacket_AttachEntity;
	m_packetFactory[0x28] = CreatePacket_EntityMetadata;
	m_packetFactory[0x29] = CreatePacket_EntityEffect;
	m_packetFactory[0x2A] = CreatePacket_RemoveEntityEffect;
	m_packetFactory[0x2B] = CreatePacket_Experience;
	m_packetFactory[0x32] = CreatePacket_PreChunk;
	m_packetFactory[0x33] = CreatePacket_MapChunk;
	m_packetFactory[0x34] = CreatePacket_MultiBlockChange;
	m_packetFactory[0x35] = CreatePacket_BlockChange;
	m_packetFactory[0x36] = CreatePacket_BlockAction;
	m_packetFactory[0x3C] = CreatePacket_Explosion;
	m_packetFactory[0x3D] = CreatePacket_SoundEffect;
	m_packetFactory[0x46] = CreatePacket_NewInvalidState;
	m_packetFactory[0x47] = CreatePacket_Thunderbolt;
	m_packetFactory[0x64] = CreatePacket_OpenWindow;
	m_packetFactory[0x65] = CreatePacket_WindowClose;
	m_packetFactory[0x66] = CreatePacket_WindowClick;
	m_packetFactory[0x67] = CreatePacket_WindowSlot;
	m_packetFactory[0x68] = CreatePacket_WindowItems;
	m_packetFactory[0x69] = CreatePacket_WindowProperty;
	m_packetFactory[0x6A] = CreatePacket_Transaction;
	m_packetFactory[0x6B] = CreatePacket_CreativeInventoryAction;
	m_packetFactory[0x6C] = CreatePacket_EnchantItem;
	m_packetFactory[0x82] = CreatePacket_UpdateSign;
	m_packetFactory[0x83] = CreatePacket_ItemData;
	m_packetFactory[0xC8] = CreatePacket_IncrementStatistic;
	m_packetFactory[0xC9] = CreatePacket_PlayerListItem;
	m_packetFactory[0xFA] = CreatePacket_PluginMessage;
	m_packetFactory[0xFE] = CreatePacket_ServerListPing;
	m_packetFactory[0xFF] = CreatePacket_Kick;
}

Packet *Packets::createPacket(int iID)
{
	if (iID < 0 || iID >= 256 || m_packetFactory[iID] == NULL)
	{
		return NULL;
	}

	return m_packetFactory[iID]();
}
