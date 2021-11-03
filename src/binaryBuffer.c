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
