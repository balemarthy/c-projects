# ENC28J60 Ethernet Controller Driver Macros

This document provides an explanation of the significant macros used in the ENC28J60 Ethernet controller driver.

## Introduction

The ENC28J60 is a stand-alone Ethernet controller with an SPI interface. It is designed to serve as an Ethernet network interface for embedded systems. The ENC28J60 integrates a MAC and PHY, making it ideal for applications requiring Ethernet connectivity. This driver provides the core functionality required to interface with the ENC28J60, including initialization, register access, memory access, and handling of transmit and receive operations.

## Register Definitions

### Any Bank Registers
- `ENC28J60_REG_EIE` (0x1B): Ethernet Interrupt Enable.
- `ENC28J60_REG_EIR` (0x1C): Ethernet Interrupt Request.
- `ENC28J60_REG_ESTAT` (0x1D): Ethernet Status.
- `ENC28J60_REG_ECON2` (0x1E): Ethernet Control 2.
- `ENC28J60_REG_ECON1` (0x1F): Ethernet Control 1.

### Bank 0 Registers
- `ENC28J60_REG_ERDPTL` (0x0000): Read Pointer Low Byte.
- `ENC28J60_REG_ERDPTH` (0x0001): Read Pointer High Byte.
- `ENC28J60_REG_EWRPTL` (0x0002): Write Pointer Low Byte.
- `ENC28J60_REG_EWRPTH` (0x0003): Write Pointer High Byte.
- `ENC28J60_REG_ETXSTL` (0x0004): TX Start Low Byte.
- `ENC28J60_REG_ETXSTH` (0x0005): TX Start High Byte.
- `ENC28J60_REG_ETXNDL` (0x0006): TX End Low Byte.
- `ENC28J60_REG_ETXNDH` (0x0007): TX End High Byte.
- `ENC28J60_REG_ERXSTL` (0x0008): RX Start Low Byte.
- `ENC28J60_REG_ERXSTH` (0x0009): RX Start High Byte.
- `ENC28J60_REG_ERXNDL` (0x000A): RX End Low Byte.
- `ENC28J60_REG_ERXNDH` (0x000B): RX End High Byte.
- `ENC28J60_REG_ERXRDPTL` (0x000C): RX Read Pointer Low Byte.
- `ENC28J60_REG_ERXRDPTH` (0x000D): RX Read Pointer High Byte.
- `ENC28J60_REG_ERXWRPTL` (0x000E): RX Write Pointer Low Byte.
- `ENC28J60_REG_ERXWRPTH` (0x000F): RX Write Pointer High Byte.
- `ENC28J60_REG_EDMASTL` (0x0010): DMA Start Low Byte.
- `ENC28J60_REG_EDMASTH` (0x0011): DMA Start High Byte.
- `ENC28J60_REG_EDMANDL` (0x0012): DMA End Low Byte.
- `ENC28J60_REG_EDMANDH` (0x0013): DMA End High Byte.
- `ENC28J60_REG_EDMADSTL` (0x0014): DMA Destination Low Byte.
- `ENC28J60_REG_EDMADSTH` (0x0015): DMA Destination High Byte.
- `ENC28J60_REG_EDMACSL` (0x0016): DMA Checksum Low Byte.
- `ENC28J60_REG_EDMACSH` (0x0017): DMA Checksum High Byte.

### Bank 1 Registers
- `ENC28J60_REG_EHT0` (0x0100): Hash Table Byte 0.
- `ENC28J60_REG_EHT1` (0x0101): Hash Table Byte 1.
- `ENC28J60_REG_EHT2` (0x0102): Hash Table Byte 2.
- `ENC28J60_REG_EHT3` (0x0103): Hash Table Byte 3.
- `ENC28J60_REG_EHT4` (0x0104): Hash Table Byte 4.
- `ENC28J60_REG_EHT5` (0x0105): Hash Table Byte 5.
- `ENC28J60_REG_EHT6` (0x0106): Hash Table Byte 6.
- `ENC28J60_REG_EHT7` (0x0107): Hash Table Byte 7.
- `ENC28J60_REG_EPMM0` (0x0108): Pattern Match Mask Byte 0.
- `ENC28J60_REG_EPMM1` (0x0109): Pattern Match Mask Byte 1.
- `ENC28J60_REG_EPMM2` (0x010A): Pattern Match Mask Byte 2.
- `ENC28J60_REG_EPMM3` (0x010B): Pattern Match Mask Byte 3.
- `ENC28J60_REG_EPMM4` (0x010C): Pattern Match Mask Byte 4.
- `ENC28J60_REG_EPMM5` (0x010D): Pattern Match Mask Byte 5.
- `ENC28J60_REG_EPMM6` (0x010E): Pattern Match Mask Byte 6.
- `ENC28J60_REG_EPMM7` (0x010F): Pattern Match Mask Byte 7.
- `ENC28J60_REG_EPMCSL` (0x0110): Pattern Match Checksum Low Byte.
- `ENC28J60_REG_EPMCSH` (0x0111): Pattern Match Checksum High Byte.
- `ENC28J60_REG_EPMOL` (0x0114): Pattern Match Offset Low Byte.
- `ENC28J60_REG_EPMOH` (0x0115): Pattern Match Offset High Byte.
- `ENC28J60_REG_EWOLIE` (0x0116): Wake-on-LAN Interrupt Enable.
- `ENC28J60_REG_EWOLIR` (0x0117): Wake-on-LAN Interrupt Request.
- `ENC28J60_REG_ERXFCON` (0x0118): Receive Filter Control.
- `ENC28J60_REG_EPKTCNT` (0x0119): Packet Count.

### Bank 2 Registers
- `ENC28J60_REG_MACON1` (0x1200): MAC Control 1.
- `ENC28J60_REG_MACON3` (0x1202): MAC Control 3.
- `ENC28J60_REG_MACON4` (0x1203): MAC Control 4.
- `ENC28J60_REG_MABBIPG` (0x1204): Back-to-Back Inter-Packet Gap.
- `ENC28J60_REG_MAIPGL` (0x1206): Non-Back-to-Back Inter-Packet Gap Low Byte.
- `ENC28J60_REG_MAIPGH` (0x1207): Non-Back-to-Back Inter-Packet Gap High Byte.
- `ENC28J60_REG_MACLCON1` (0x1208): Collision Control 1.
- `ENC28J60_REG_MACLCON2` (0x1209): Collision Control 2.
- `ENC28J60_REG_MAMXFLL` (0x120A): Maximum Frame Length Low Byte.
- `ENC28J60_REG_MAMXFLH` (0x120B): Maximum Frame Length High Byte.
- `ENC28J60_REG_MAPHSUP` (0x120C): PHY Support.
- `ENC28J60_REG_MICON` (0x2211): MII Control.
- `ENC28J60_REG_MICMD` (0x2212): MII Command.
- `ENC28J60_REG_MIREGADR` (0x2214): MII Register Address.
- `ENC28J60_REG_MIWRL` (0x2216): MII Write Data Low Byte.
- `ENC28J60_REG_MIWRH` (0x2217): MII Write Data High Byte.
- `ENC28J60_REG_MIRDL` (0x2218): MII Read Data Low Byte.
- `ENC28J60_REG_MIRDH` (0x2219): MII Read Data High Byte.

### Bank 3 Registers
- `ENC28J60_REG_MAADR5` (0x1300): MAC Address Byte 5.
- `ENC28J60_REG_MAADR6` (0x1301): MAC Address Byte 6.
- `ENC28J60_REG_MAADR3` (0x1302): MAC Address Byte 3.
- `ENC28J60_REG_MAADR4` (0x1303): MAC Address Byte 4.
- `ENC28J60_REG_MAADR1` (0x1304): MAC Address Byte 1.
- `ENC28J60_REG_MAADR2` (0x1305): MAC Address Byte 2.
- `ENC28J60_REG_EBSTSD` (0x0306): Built-in Self-Test Start Delay.
- `ENC28J60_REG_EBSTCON` (0x0307): Built-in Self-Test Control.
- `ENC28J60_REG_EBSTCSL` (0x0308): Built-in Self-Test Checksum Low Byte.
- `ENC28J60_REG_EBSTCSH` (0x0309): Built-in Self-Test Checksum High Byte.
- `ENC28J60_REG_MISTAT` (0x230A): MII Status.
- `ENC28J60_REG_EREVID` (0x0312): Ethernet Revision ID.
- `ENC28J60_REG_ECOCON` (0x0315): Clock Output Control.
- `ENC28J60_REG_EFLOCON` (0x0317): Flow Control.
- `ENC28J60_REG_EPAUSL` (0x0318): Pause Timer Value Low Byte.
- `ENC28J60_REG_EPAUSH` (0x0319): Pause Timer Value High Byte.

## PHY Registers
- `ENC28J60_PHY_PHCON1` (0x00): PHY Control 1.
- `ENC28J60_PHY_PHSTAT1` (0x01): PHY Status 1.
- `ENC28J60_PHY_PHID1` (0x02): PHY Identifier 1.
- `ENC28J60_PHY_PHID2` (0x03): PHY Identifier 2.
- `ENC28J60_PHY_PHCON2` (0x10): PHY Control 2.
- `ENC28J60_PHY_PHSTAT2` (0x11): PHY Status 2.
- `ENC28J60_PHY_PHIE` (0x12): PHY Interrupt Enable.
- `ENC28J60_PHY_PHIR` (0x13): PHY Interrupt Request.
- `ENC28J60_PHY_PHLCON` (0x14): PHY LED Control.

## SPI Instruction Opcodes
- `ENC28J60_SPI_RCR` (0x0): Read Control Register.
- `ENC28J60_SPI_RBM` (0x3A): Read Buffer Memory.
- `ENC28J60_SPI_WCR` (0x2 << 5): Write Control Register.
- `ENC28J60_SPI_WBM` (0x7A): Write Buffer Memory.
- `ENC28J60_SPI_BFS` (0x4 << 5): Bit Field Set.
- `ENC28J60_SPI_BFC` (0x5 << 5): Bit Field Clear.
- `ENC28J60_SPI_SC` (0xFF): System Command (Soft Reset).

## Significant Bits
- `ENC28J60_BIT_MICMD_MIIRD` (0x01): MII Read Enable.
- `ENC28J60_BIT_MISTAT_BUSY` (0x01): MII Status Busy.
- `ENC28J60_BIT_ESTAT_CLKRDY` (0x01): Clock Ready.
- `ENC28J60_BIT_MACON1_RXPAUS` (0x04): MAC Control 1 Receive Pause.
- `ENC28J60_BIT_MACON1_TXPAUS` (0x08): MAC Control 1 Transmit Pause.
- `ENC28J60_BIT_MACON1_MARXEN` (0x01): MAC Control 1 MAC Receive Enable.
- `ENC28J60_BIT_MACON2_MARST` (0x80): MAC Control 2 MAC Reset.
- `ENC28J60_BIT_MACON3_FULDPX` (0x01): MAC Control 3 Full Duplex.
- `ENC28J60_BIT_ECON1_TXRST` (0x80): Ethernet Control 1 Transmit Reset.
- `ENC28J60_BIT_ECON1_TXRTS` (0x08): Ethernet Control 1 Transmit Request to Send.
- `ENC28J60_BIT_ECON1_RXEN` (0x04): Ethernet Control 1 Receive Enable.
- `ENC28J60_BIT_ECON2_PKTDEC` (0x40): Ethernet Control 2 Packet Decrement.
- `ENC28J60_BIT_EIE_TXIE` (0x08): Ethernet Interrupt Enable Transmit Interrupt Enable.
- `ENC28J60_BIT_EIE_PKTIE` (0x40): Ethernet Interrupt Enable Packet Interrupt Enable.
- `ENC28J60_BIT_EIE_LINKIE` (0x10): Ethernet Interrupt Enable Link Change Interrupt Enable.
- `ENC28J60_BIT_EIE_INTIE` (0x80): Ethernet Interrupt Enable Global Interrupt Enable.
- `ENC28J60_BIT_EIR_PKTIF` (0x40): Ethernet Interrupt Request Packet Interrupt Flag.
- `ENC28J60_BIT_EIR_DMAIF` (0x20): Ethernet Interrupt Request DMA Interrupt Flag.
- `ENC28J60_BIT_EIR_LINKIF` (0x10): Ethernet Interrupt Request Link Change Interrupt Flag.
- `ENC28J60_BIT_EIR_TXIF` (0x08): Ethernet Interrupt Request Transmit Interrupt Flag.
- `ENC28J60_BIT_EIR_WOLIF` (0x04): Ethernet Interrupt Request Wake-on-LAN Interrupt Flag.
- `ENC28J60_BIT_EIR_TXERIF` (0x02): Ethernet Interrupt Request Transmit Error Interrupt Flag.
- `ENC28J60_BIT_EIR_RXERIF` (0x01): Ethernet Interrupt Request Receive Error Interrupt Flag.
- `ENC28J60_BIT_ESTAT_TXABRT` (0x02): Ethernet Status Transmit Abort.
- `ENC28J60_BIT_ESTAT_LATECOL` (0x10): Ethernet Status Late Collision.
- `ENC28J60_BIT_PHCON1_PDPXMD` (0x0100): PHY Control 1 Full Duplex Mode.
- `ENC28J60_BIT_PHCON2_HDLDIS` (0x0100): PHY Control 2 Half-Duplex Disable.
- `ENC28J60_BIT_PHSTAT2_LSTAT` (0x0400): PHY Status 2 Link Status.
- `ENC28J60_BIT_PHIE_PGEIE` (0x0002): PHY Interrupt Enable Page Received.
- `ENC28J60_BIT_PHIE_PLNKIE` (0x0010): PHY Interrupt Enable Link Change.

## Driver Static Configuration
- `ENC28J60_RECEIVE_FILTERS` (0xA3): Default receive filters enabled (Unicast, Multicast, Broadcast, CRC Check).
- `ENC28J60_MAC_CONFIG` (0x32): MAC configuration for automatic padding, CRC, and frame length checking.
- `ENC28J60_MAC_BBIPG_HD` (0x12): Back-to-Back Inter-Packet Gap for half-duplex.
- `ENC28J60_MAC_BBIPG_FD` (0x15): Back-to-Back Inter-Packet Gap for full-duplex.
- `ENC28J60_MAC_NBBIPGL` (0x12): Non-Back-to-Back Inter-Packet Gap Low Byte.
- `ENC28J60_MAC_NBBIPGH` (0x0C): Non-Back-to-Back Inter-Packet Gap High Byte.
- `ENC28J60_PHY_LEDCONF` (0x3422): PHY LED Configuration.
- `ENC28J60_SV_SIZE` (8): Status Vector size plus per packet control byte.
- `ENC28J60_PPCTL_BYTE` (0x0): Per Packet Control Byte configured to follow MACON3 configuration.

## Buffer Definitions
- `ENC28J60_RXSTART` (0x0000): Start of RX buffer (must be zero, Rev. B4 Errata point 5).
- `ENC28J60_RXEND` (0x0BFF): End of RX buffer, room for 2 packets.
- `ENC28J60_TXSTART` (0x0C00): Start of TX buffer, room for 1 packet.
- `ENC28J60_TXEND` (0x11FF): End of TX buffer.

## Miscellaneous
- `MICROCHIP_OUI_B0` (0x00): Microchip OUI Byte 0.
- `MICROCHIP_OUI_B1` (0x04): Microchip OUI Byte 1.
- `MICROCHIP_OUI_B2` (0xA3): Microchip OUI Byte 2.
- `MAX_BUFFER_LENGTH` (128): Maximum buffer length.
- `TSV_SIZE` (7): Transmit Status Vector size.
- `RSV_SIZE` (4): Receive Status Vector size.
```

