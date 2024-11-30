/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.1
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define PWR_LED_TRIS                 TRISAbits.TRISA0
#define PWR_LED_LAT                  LATAbits.LATA0
#define PWR_LED_PORT                 PORTAbits.RA0
#define PWR_LED_WPU                  WPUAbits.WPUA0
#define PWR_LED_OD                   ODCONAbits.ODCA0
#define PWR_LED_ANS                  ANSELAbits.ANSELA0
#define PWR_LED_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define PWR_LED_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define PWR_LED_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define PWR_LED_GetValue()           PORTAbits.RA0
#define PWR_LED_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define PWR_LED_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define PWR_LED_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define PWR_LED_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define PWR_LED_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define PWR_LED_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define PWR_LED_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define PWR_LED_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA2 aliases
#define IO_RA2_TRIS                 TRISAbits.TRISA2
#define IO_RA2_LAT                  LATAbits.LATA2
#define IO_RA2_PORT                 PORTAbits.RA2
#define IO_RA2_WPU                  WPUAbits.WPUA2
#define IO_RA2_OD                   ODCONAbits.ODCA2
#define IO_RA2_ANS                  ANSELAbits.ANSELA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_RA2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RC2 aliases
#define SPI1_CS_TRIS                 TRISCbits.TRISC2
#define SPI1_CS_LAT                  LATCbits.LATC2
#define SPI1_CS_PORT                 PORTCbits.RC2
#define SPI1_CS_WPU                  WPUCbits.WPUC2
#define SPI1_CS_OD                   ODCONCbits.ODCC2
#define SPI1_CS_ANS                  ANSELCbits.ANSELC2
#define SPI1_CS_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SPI1_CS_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SPI1_CS_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SPI1_CS_GetValue()           PORTCbits.RC2
#define SPI1_CS_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SPI1_CS_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SPI1_CS_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define SPI1_CS_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define SPI1_CS_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define SPI1_CS_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define SPI1_CS_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define SPI1_CS_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 aliases
#define SCK_TRIS                 TRISCbits.TRISC3
#define SCK_LAT                  LATCbits.LATC3
#define SCK_PORT                 PORTCbits.RC3
#define SCK_WPU                  WPUCbits.WPUC3
#define SCK_OD                   ODCONCbits.ODCC3
#define SCK_ANS                  ANSELCbits.ANSELC3
#define SCK_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCK_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCK_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCK_GetValue()           PORTCbits.RC3
#define SCK_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCK_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SCK_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SCK_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCK_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SCK_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define SCK_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 aliases
#define SDI_TRIS                 TRISCbits.TRISC4
#define SDI_LAT                  LATCbits.LATC4
#define SDI_PORT                 PORTCbits.RC4
#define SDI_WPU                  WPUCbits.WPUC4
#define SDI_OD                   ODCONCbits.ODCC4
#define SDI_ANS                  ANSELCbits.ANSELC4
#define SDI_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDI_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDI_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDI_GetValue()           PORTCbits.RC4
#define SDI_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDI_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDI_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SDI_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SDI_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SDI_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SDI_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define SDI_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 aliases
#define SDO_TRIS                 TRISCbits.TRISC5
#define SDO_LAT                  LATCbits.LATC5
#define SDO_PORT                 PORTCbits.RC5
#define SDO_WPU                  WPUCbits.WPUC5
#define SDO_OD                   ODCONCbits.ODCC5
#define SDO_ANS                  ANSELCbits.ANSELC5
#define SDO_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SDO_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SDO_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SDO_GetValue()           PORTCbits.RC5
#define SDO_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SDO_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SDO_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SDO_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SDO_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SDO_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SDO_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define SDO_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/