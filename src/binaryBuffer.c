#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/binaryBuffer.h"

bbuffer32 setBuffer32(bbuffer32 data, uint32_t buffer)
{
    *data = 0b00000000000000000000000000000000 | buffer;

    return data;
}

uint32_t getContentBuffer32(bbuffer32 data)
{
    return *data;
}

bbuffer32 newbuffer32(int init_value)
{
  bbuffer32 newbuffer32 = malloc(sizeof(uint32_t));
  *newbuffer32 = init_value;
  return newbuffer32;
}

bbuffer32 freeBuffer(bbuffer32 toFree)
{
    if(toFree != NULL)
    {
        free(toFree);
        toFree = NULL;
    }
    return toFree;
}


char* bufferToString(bbuffer32 data, char* string){

   for(int size = (sizeof(*data) * 8) - 1; size >= 0; size--){

      if((1 << size) & *data)
         string[((sizeof(*data) * 8) - 1) - size] = '1';
      else
         string[((sizeof(*data) * 8) - 1) - size] = '0';
   }
   printf"%s\n\n", string);
   return string;
}

uint8_t getbitn(bbuffer32 data, uint8_t bit_position){
    uint8_t BIT_ZERO = 0b00000001;
    uint8_t bit;
    bit = (( BIT_ZERO << bit_position) & data) >> bit_position;
    return bit;
}

uint16_t sizeInBits(size_t data_size){
    uint16_t size_bits = 0b0000000000000000;
    size_bits = (uint16_t) data_size;
    return size_bits;
}