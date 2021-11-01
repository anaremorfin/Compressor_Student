#ifndef binaryBuffer_H
#define binaryBuffer_H

#include <stdio.h>


typedef uint32_t* bbuffer32; 

uint8_t getbitn(bbuffer32 data, uint8_t bit_position);

uint16_t sizeInBits(size_t data_size);

bbuffer32 newbuffer32(int init_value);

bbuffer32 freeBuffer(bbuffer32 toFree);

bbuffer32 setBuffer32(uint32_t data);

uint32_t getContentBuffer32(bbuffer32 data);

char* bufferToString(bbuffer32 data, char* string);

#endif