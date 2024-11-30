 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/
#include "mcc_generated_files/system/system.h"
#include "w25qxx.h"
#include "wavDecode.h"

#define BUFFER_SIZE     256

// Global data buffer for reading from flash
uint8_t dataBuffer[BUFFER_SIZE];


/*
 * 
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();
    SPI1_Close();
    w25qxx_Initialiase();
    uint8_t flashID = w25qxx_ReadID();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    //INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    //Initialisation complete. Turn on Power LED
    PWR_LED_SetHigh();
    
    //Working block address because the Flash, and buffer fill in 256-byte blocks
    //Start at 0x100 for arbitrary reasons
    uint32_t currentMemoryBlockAddress = 0x000100;
    
    __delay_ms(10);

    //Read the start of the chip and find a WAV file
    w25qxx_FastRead(currentMemoryBlockAddress, dataBuffer, BUFFER_SIZE);
    
    //Retrieve the (only) file header data
    WAV_Header file1 = wav_getHeader(dataBuffer, BUFFER_SIZE, currentMemoryBlockAddress);
    
    //Return the DAC to zero
    DAC1_SetOutput(0x40);
    
    while(1)
    {
        
    
        //Get the DAC working
        //Point to the start of the file to begin reading
        uint32_t currentMemoryAddress = file1.DataBeginsAt;

        //Play the file up to the end of file
        //Set open a fast read channel and keep it open
        w25qxx_FastReadOpen(currentMemoryAddress);
        //Read each byte directly from the flash and put it on the DAC
        while(currentMemoryAddress < file1.FileSize - file1.HeaderSize + file1.DataBeginsAt - 0x200) {
            w25qxx_ReadByteOpen(dataBuffer);
            DAC1_SetOutput(dataBuffer[0] >> 3);
            currentMemoryAddress++;

            __delay_us(40);
        }

        w25qxx_FastReadClose();
        
        DAC1_SetOutput(0x40);
        
        //End
        __delay_ms(1000);
    };
}