#include "board_protocol.h"
/*------------------------板间通信测试代码---------------*/
extern UART_HandleTypeDef huart10;

board_test_t board_tx;
board_test_t board_rx;

uint8_t tx_info_buff[12];
bool is_pass_crc;

//测试结构体内容初始化，置于drever.c
void board_test_init()
{
	uint8_t *p_data = (uint8_t*)&board_tx;
		
	board_tx.test_1 = 0xA5;
    for(uint8_t i = 1; i < 12; i++)
    {
        p_data[i] = i + 1;  
    }
}

void board_send()
{	
	board_test_t *p_data = &board_tx ;
	p_data->test_2 ++;
	memcpy (tx_info_buff ,p_data ,sizeof (board_test_t ));
	Append_CRC8_Check_Sum (tx_info_buff ,3);
	Append_CRC16_Check_Sum (tx_info_buff ,12);
	
	HAL_UART_Transmit(&huart10, tx_info_buff , sizeof(tx_info_buff ),20);
}

bool board_recieve(uint8_t *rxBuf)
{
	if (rxBuf == NULL) {
        return false;
    }
	if(Verify_CRC8_Check_Sum (rxBuf ,3) == true
		&&Verify_CRC16_Check_Sum (rxBuf ,12) == true)
		{
			memcpy (&board_rx ,rxBuf ,12);
			return true;
		}
	else return false;
}


void USART1_rxDataHandler(uint8_t *rxBuf)
{
	is_pass_crc=board_recieve (rxBuf);
}
