# WAV File Player
Just some spagetti code at the moment to test playing a WAV file with a PIC18F26K42.
  
## Introduction
This is just some test code, it isn't a complete project. In it's current state it will find the start of a WAV file located at 0x000100 on the flash chip. It reads the RIFF header in to a struct and then starts playing from the start of the first data chunk.
 * Uses the MPLAB HAL for this chip and their own code generator to configure the pins.
 * Currently only plays a single WAV file.
 * Has some weird hiss which looks to be digital noise coming from the DAC or my code.
 * Does NOT write to flash.
