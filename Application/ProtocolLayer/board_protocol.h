#ifndef __BOARD_PROTOCOL_H
#define __BOARD_PROTOCOL_H

#include "stm32h7xx.h"
#include "stdbool.h"
#include "crc.h"
#include "string.h"
//∞Âº‰Õ®–≈≤‚ ‘
typedef struct
{
	uint8_t  test_1;
	uint8_t  test_2;
	uint8_t  test_3;   
    uint8_t  test_4;
    uint8_t  test_5;
    uint8_t  test_6;
    uint8_t  test_7;
    uint8_t  test_8;
    uint8_t  test_9;
    uint8_t  test_10;
    uint8_t  test_11;
    uint8_t  test_12;
}board_test_t;

bool board_recieve(uint8_t *rxBuf);
void board_test_init(void);
void board_send(void);

#endif
