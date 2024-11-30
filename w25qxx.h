/* 
 * File:   m25qxx.h
 * Author: tommy
 *
 * Created on October 31, 2024, 3:52 PM
 */

#ifndef M25QXX_H
#define	M25QXX_H

#ifdef	__cplusplus
extern "C" {
#endif

// Command definitions
#define     FAST_READ       0x0B
#define     READ_DATA       0x03
#define     WRITE_DATA      0x02
#define     SECTOR_ERASE    0x20
#define     RESET_ENABLE    0x66
#define     W25QXX_RESET    0x99
#define     WRITE_ENABLE    0x06
#define     GLOBAL_UNLOCK  0x98


void w25qxx_Initialiase();
void w25qxx_SectorErase(uint32_t address);
void w25qxx_WriteData(uint32_t address, uint8_t data);
uint8_t w25qxx_ReadData(uint32_t address);
void w25qxx_FastRead(uint32_t address, uint8_t *buffer, uint16_t bufferSize);
void w25qxx_FastReadOpen(uint32_t address);
void w25qxx_ReadByteOpen(uint8_t *buffer);
void w25qxx_FastReadClose();
uint8_t w25qxx_ReadID();
    
#ifdef	__cplusplus
}
#endif

#endif	/* M25QXX_H */

