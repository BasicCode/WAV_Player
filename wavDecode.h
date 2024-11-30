/* 
 * File:   wavDecode.h
 * Author: tommy
 *
 * Created on October 31, 2024, 4:52 PM
 */

#ifndef WAVDECODE_H
#define	WAVDECODE_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct {
        char        FileTypeBlockID[4]; //"RIFF"
        uint32_t    FileSize; //File size in bytes
        char        FormatBlockID[4]; //"fmt_"
        char        FileFormatID[4]; //"WAVE"
        uint32_t    BlockSize;
        uint16_t    AudioFormat; //1 = PCM; 3 = IEEE float
        uint16_t    NumChannels;
        uint32_t    Frequency; //Sample rate (Hz)
        uint32_t    BytePerSec; //Bytes per second
        uint16_t    BytePerBlock;
        uint16_t    BitsPerSample;
        uint32_t    DataBeginsAt; //Location of the start of data for this file
        uint16_t    HeaderSize; //Size of all the header and metadata
    } WAV_Header;

WAV_Header wav_getHeader(uint8_t *buffer, uint16_t bufferLength, uint32_t bufferOffset);

#ifdef	__cplusplus
}
#endif

#endif	/* WAVDECODE_H */

