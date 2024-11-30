
/**
 * Takes a buffer, or part of a WAV file and decodes header and raw
 * data.
 */
#include "mcc_generated_files/system/system.h"
#include "wavDecode.h"
#include "string.h"


/*
 * Decode the header data from the provided buffer and populate
 * the provided header struct..
 */
WAV_Header wav_getHeader(uint8_t *buffer, uint16_t bufferLength, uint32_t bufferOffset) {
    //New file header
    WAV_Header newFile;
    
    //First, find the beginning of the WAV file ("RIFF" string)
    char riff[] = "RIFF";
    uint16_t start = 0;
    
    
    for(int i = 0; i < bufferLength - 5; i++) {
        //A simple string search
        if(buffer[i] == riff[0] && 
                buffer[i + 1] == riff[1] &&
                buffer[i + 2] == riff[2] &&
                buffer[i + 3] == riff[3]) {
            //We found the string
            start = i;
            break;
        }
    }
    
    //Now start populating fields counting from the start, adding each
    //field size as we go.
    //All integers are little-endian bytes-ordered
    int byteCounter = start;
    
    //File type "RIFF" we have determined above
    newFile.FileTypeBlockID[0] = buffer[byteCounter];
    newFile.FileTypeBlockID[1] = buffer[byteCounter + 1];
    newFile.FileTypeBlockID[2] = buffer[byteCounter + 2];
    newFile.FileTypeBlockID[3] = buffer[byteCounter + 3];
    byteCounter += 4;
    
    //File size 4-bytes little-endian byte order
    newFile.FileSize = 
            ((uint32_t) buffer[byteCounter + 3] << 24) |
            ((uint32_t) buffer[byteCounter + 2] << 16) |
            ((uint32_t) buffer[byteCounter + 1] << 8 ) |
            ((uint32_t) buffer[byteCounter]);
    //Increment the counter to the next field
    byteCounter += 4;
    
    //File format ID "WAVE" string
    newFile.FileFormatID[0] = buffer[byteCounter];
    newFile.FileFormatID[1] = buffer[byteCounter + 1];
    newFile.FileFormatID[2] = buffer[byteCounter + 2];
    newFile.FileFormatID[3] = buffer[byteCounter + 3];
    byteCounter += 4;
    
    //Format Block ID "fmt_" 4-bytes
    newFile.FormatBlockID[0] = buffer[byteCounter];
    newFile.FormatBlockID[1] = buffer[byteCounter + 1];
    newFile.FormatBlockID[2] = buffer[byteCounter + 2];
    newFile.FormatBlockID[3] = buffer[byteCounter + 3];
    byteCounter += 4;
    
    //BlockSize 4-bytes
    newFile.BlockSize = 
            ((uint32_t) buffer[byteCounter + 3] << 24) |
            ((uint32_t) buffer[byteCounter + 2] << 16) |
            ((uint32_t) buffer[byteCounter + 1] << 8 ) |
            ((uint32_t) buffer[byteCounter]);
    //Increment the counter to the next field
    byteCounter += 4;
    
    //Audio format 2-bytes but only one is used
    newFile.AudioFormat = buffer[byteCounter];
    byteCounter += 2;
    
    //Number of channels 2-bytes but only one is used
    newFile.NumChannels = buffer[byteCounter];
    byteCounter += 2;
    
    //Frequency 4-bytes
    newFile.Frequency = 
            ((uint32_t) buffer[byteCounter + 3] << 24) |
            ((uint32_t) buffer[byteCounter + 2] << 16) |
            ((uint32_t) buffer[byteCounter + 1] << 8) |
            (uint32_t) (buffer[byteCounter]);
    byteCounter += 4;
    
    //Bytes per second 4-bytes
    newFile.BytePerSec = 
            ((uint32_t) buffer[byteCounter + 3] << 24) |
            ((uint32_t) buffer[byteCounter + 2] << 16) |
            ((uint32_t) buffer[byteCounter + 1] << 8) |
            ((uint32_t) buffer[byteCounter]);
    byteCounter += 4;
    
    //Bytes per block 2-bytes
    newFile.BytePerBlock = 
            ((uint32_t) buffer[byteCounter + 1] << 8) |
            ((uint32_t) buffer[byteCounter]);
    byteCounter += 2;
    
    //Bits per sample 2-bytes
    newFile.BitsPerSample = 
            ((uint32_t) buffer[byteCounter + 1] << 8) |
            ((uint32_t) buffer[byteCounter]);
    byteCounter += 2;
    
    //8-bytes for the chunk header
    byteCounter += 8;
    
    //Finally the location of the start of data
    //Add the offset of this buffer in RAM to get the absolute address in memory
    //Subtract 4-bytes because there's an empty 4-bytes (see SPI bufferExchange)
    
    newFile.DataBeginsAt = byteCounter + bufferOffset - 5;
    newFile.HeaderSize = byteCounter - 5;
    
    return newFile;
}