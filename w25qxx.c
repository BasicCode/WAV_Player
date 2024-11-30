/**
 * A driver file for the W25Qxx series of NOR Flash from Winbond.
 * 
 * Designed to run on a PIC 18F26K42 using Microchip's MCC HAL.
 */
#include "mcc_generated_files/system/system.h"
#include "w25qxx.h"

/**
 * Internal private function definitions
 */
void w25qxx_WriteEnable();

/**
 * Initialisation sequence for the W25Q128 or other
 * Winbond chips.
 */
void w25qxx_Initialiase() {
    SPI1_Open(HOST_CONFIG);
    //SEt CS Pin HIGH
    SPI1_CS_SetHigh();
    //Wait for FLASH to warm up
    __delay_ms(5);
    
    //Do a soft reset
    SPI1_CS_SetLow();
    uint8_t bufferData[] = {RESET_ENABLE, W25QXX_RESET}; //Reset Enable, Reset command
    SPI1_BufferWrite(bufferData, 2);
    SPI1_Close();
    SPI1_CS_SetHigh();
    __delay_us(50); //Wait for reset to finish
    
    //Unblock all the memory areas (Locked on reset by default)
    /*
    w25qxx_WriteEnable();
    SPI1_CS_SetLow();
    SPI1_ByteWrite(GLOBAL_UNLOCK); // Global Sector Unlock
    SPI1_CS_SetHigh();
    */
    
    __delay_ms(1);
}

/**
 * Enables writing on the next command
 */
void w25qxx_WriteEnable() {
    SPI1_CS_SetLow();
    SPI1_ByteWrite(WRITE_ENABLE); // Send Write Enable command
    SPI1_CS_SetHigh();
    __delay_us(50);
}

/**
 * Erase a specified sector.
 * 
 * Does NOT check that the address aligns with a sector.
 * 
 * @param testAddr
 */
void w25qxx_SectorErase(uint32_t address) {
    SPI1_Open(HOST_CONFIG);
    
    w25qxx_WriteEnable(); // Enable writing

    SPI1_CS_SetLow();
    
    // Write data to a specified address
    uint8_t bufferData[] = {
        SECTOR_ERASE, 
        (address >> 16) & 0xFF,
        (address >> 8) & 0xFF,
        address & 0xFF
    };
    
    SPI1_BufferWrite(bufferData, 4);
    
    SPI1_Close();
    SPI1_CS_SetHigh();
    
    //tSE sector erase time is UP TO 400ms! according to datasheet
    __delay_ms(400);
}

void w25qxx_WriteData(uint32_t address, uint8_t data) {
    
    SPI1_Open(HOST_CONFIG);
    
    w25qxx_WriteEnable(); // Enable writing

    SPI1_CS_SetLow(); // Select the SPI flash
    
    // Write data to a specified address
    uint8_t bufferData[] = {
        WRITE_DATA, 
        (address >> 16) & 0xFF,
        (address >> 8) & 0xFF,
        address & 0xFF,
        data
    };
    
    SPI1_BufferWrite(bufferData, 5);
    
    SPI1_Close();
    SPI1_CS_SetHigh();
    
    //Page Program time (tpp in datasheet) is up to 3ms
    __delay_ms(3);
}

uint8_t w25qxx_ReadData(uint32_t address) {
    
    SPI1_CS_SetLow();
    SPI1_Open(HOST_CONFIG);
    
    //Command to read from an address
    uint8_t bufferData[] = {
        READ_DATA,
        (address >> 16) & 0xFF,
        (address >> 8) & 0xFF,
        address & 0xFF,
        0x00
    };
    
    SPI1_BufferExchange(bufferData, 5);
    
    //Wait for read to finish and close
    SPI1_Close();
    SPI1_CS_SetHigh();
    
    return bufferData[4];
}

/**
 * Performs a fastread function on the flash chip. This will use the global
 * read/write buffer
 * @param address
 */
void w25qxx_FastRead(uint32_t address, uint8_t *buffer, uint16_t bufferSize) {
    SPI1_CS_SetLow();
    SPI1_Open(HOST_CONFIG);
    
    /* 
     * Set up a fast-read command. The device with take start returning
     * data one byte after the address is sent, regardless of any junk
     * that we continue to send.
     * However after a 256byte page, the command must be re-sent.
     */
    buffer[0] = FAST_READ;
    buffer[1] = (address >> 16) & 0xFF;
    buffer[2] = (address >> 8) & 0xFF;
    buffer[3] = address & 0xFF;
    buffer[4] = 0x00;
    
    SPI1_BufferExchange(buffer, bufferSize - 5);
    
    //Wait for read to finish and close
    SPI1_Close();
    SPI1_CS_SetHigh();
}

/**
 * Will send the FastRead command and hold the CS line LOW. Using ReadByteOpen()
 * will then get a single byte without closing the channel. Finish the transfer
 * using FastReadClose().
 */
void w25qxx_FastReadOpen(uint32_t address) {
    SPI1_CS_SetLow();
    SPI1_Open(HOST_CONFIG);
    
    uint8_t buffer[5];
    buffer[0] = FAST_READ;
    buffer[1] = (address >> 16) & 0xFF;
    buffer[2] = (address >> 8) & 0xFF;
    buffer[3] = address & 0xFF;
    buffer[4] = 0x00;
    
    //Send the fast read command but don't close the connection
    SPI1_BufferExchange(buffer, 5);
}

void w25qxx_ReadByteOpen(uint8_t *buffer) {
    buffer[0] = 0x00;
    SPI1_BufferExchange(buffer, 1);
}

void w25qxx_FastReadClose() {
    SPI1_Close();
    SPI1_CS_SetHigh();
}

/**
 * Read the Flash chip ID
 * 
 * @return chipID
 */
uint8_t w25qxx_ReadID(uint32_t address) {
    
    SPI1_CS_SetLow();
    SPI1_Open(HOST_CONFIG);
    
    //Command to read from an address
    uint8_t bufferData[] = {
        0x9f,
        0x00,
        0x00,
        0x00
    };
    
    SPI1_BufferExchange(bufferData, 4); // Read data byte
    
    //Wait for read to finish and close
    SPI1_Close();
    SPI1_CS_SetHigh();
    
    return bufferData[0];
}

