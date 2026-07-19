
#include "config_uart.h"
#include "rc_sensor.h"
#include "rc_protocol.h"
#include "usart.h"

void USART3_rxDataHandler(uint8_t *rxBuf)
{
	if (rc_sensor.driver != NULL && rc_sensor.driver->huart == &huart3)
	{
		#if (RC_TYPE == 0)
		rc_sensor.update(&rc_sensor, rxBuf);
		#elif (RC_TYPE == 1)
		VT13_to_rc(rxBuf, &rc_sensor_info);
		#endif
		rc_sensor.check(&rc_sensor);
	}
}

void USART6_rxDataHandler(uint8_t *rxBuf)
{
	if (rc_sensor.driver != NULL && rc_sensor.driver->huart == &huart6)
	{
		#if (RC_TYPE == 0)
		rc_sensor.update(&rc_sensor, rxBuf);
		#elif (RC_TYPE == 1)
		VT13_to_rc(rxBuf, &rc_sensor_info);
		#endif
		rc_sensor.check(&rc_sensor);
	}
}
