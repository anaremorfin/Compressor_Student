#include "binaryBuffer.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

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
  bbuffer32 newbuffer32 = malloc(sizeof(uint32_t))
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


