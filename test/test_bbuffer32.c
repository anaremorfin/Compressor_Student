#include <stdio.h>
#include <stdlib.h>

#include "binaryBuffer.h"
#include "unity.h"

bbuffer32 myBuffer = NULL;

void setUp(void){
    myBuffer = newbuffer32(0);


}
void tearDown(void){
    
}

void test_newBuffer(void){
    puts("TESTING BUFFER CREATION VIA CONSTRUCTOR");
    myBuffer = newbuffer32(0);
    TEST_ASSERT_NOT_NULL(myBuffer);
    freeBuffer(myBuffer);
}

void test_setNewBuffer(void){
    puts("TESTING BUFFER SET VALUE");
    uint32_t set = 1;
    myBuffer = newbuffer32(set);
    TEST_ASSERT_EQUAL(set, getContentBuffer32(myBuffer));
    freeBuffer(myBuffer);
}

void test_getbitN(void){
    puts("TESTING GET Bit n STATE");
    uint32_t set = 0b00100;
    uint8_t test_bit[] = {0,0,1,0};
    uint8_t gottenBit = 0;
    bbuffer32 myBuffer=NULL;
    myBuffer = newbuffer32(set);

    for(uint8_t bit=0;bit<sizeof(test_bit); bit++)
    TEST_ASSERT_EQUAL(test_bit[bit],getbitn(myBuffer, bit));

    freeBuffer(myBuffer);
}

void test_getBufferContent(void){
    puts("TESTING GET BUFFER CONTENT");
    uint32_t set = 0xEEFF4400;
    bbuffer32 myBuffer=NULL;
    myBuffer = newbuffer32(set);
    TEST_ASSERT_EQUAL_HEX32(set, getContentBuffer32(myBuffer));
    freeBuffer(myBuffer);
}

void test_getStringBufferContent(void){
    puts("TESTING FULL 32 BUFFER CONTENT AS STRING");
    char* stringBuffer = calloc((sizeof(uint32_t)+1)*8, sizeof(char));
    uint32_t set = 0xEEFF4400;
    bbuffer32 myBuffer=NULL;
    myBuffer = newbuffer32(set);

    stringBuffer = bufferToString(myBuffer, stringBuffer);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(stringBuffer, "11101110111111110100010000000000", 32);
    freeBuffer(myBuffer);
}

int main (void){
    UNITY_BEGIN();
    puts("STARTING BIT HANDLER UNIT TESTING");
    RUN_TEST(test_newBuffer, __LINE__);
    RUN_TEST(test_setNewBuffer, __LINE__);
    RUN_TEST(test_getbitN, __LINE__);
    RUN_TEST(test_getBufferContent, __LINE__);
    RUN_TEST(test_getStringBufferContent,__LINE__);

    return UNITY_END();

}