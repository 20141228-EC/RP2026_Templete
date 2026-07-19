#ifndef __VT13_RC_CTRL_H
#define __VT13_RC_CTRL_H

#include "stm32f4xx_hal.h"
#include "rc_sensor.h"

/* Exported macro ------------------------------------------------------------*/
#define VT13_FRAME_LEN          21

/* Exported functions --------------------------------------------------------*/
void VT13_to_rc(uint8_t *VT13_buf, rc_sensor_info_t *rc_info);

#endif
