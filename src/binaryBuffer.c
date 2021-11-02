#include <stdint.h>
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