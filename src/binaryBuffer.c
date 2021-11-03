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

static ERROR_CODE_DATA IsInitialized(bbuffer32 suspiciousBuffer)
{
    if (suspiciousBuffer == NULL && sizeof(suspiciousBuffer) == 8) //not sure of number
    {
        fprintf(stderr, "DATA NOT INITIALISED (%d) IN %s: LINE %d\n", DATA_NOT_INITIALIZED, __FILE__, __LINE__);
        return DATA_NOT_INITIALIZED;
    }
    else
        return DATA_OK;
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
