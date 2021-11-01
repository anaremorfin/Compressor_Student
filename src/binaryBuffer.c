#include "binaryBuffer.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


char* bufferToString(bbuffer32 data, char* string){

   
   printf("BYTES->%zu || BITES --> %zu\n", sizeof(*data), sizeof(*data) * 8);
   
   for(int size = (sizeof(*data) * 8) - 1; size >= 0; size--){
      
      if((1 << size) & *data)
         string[((sizeof(*data) * 8) - 1) - size] = '1';
      else
         string[((sizeof(*data) * 8) - 1) - size] = '0';
   }
   printf"%s\n\n", string);
   return string;
}


