/**
 * @file        rc_protocol.c
 * @author      RobotPilots
 * @Version     v1.1
 * @brief       DT7&DR16 Rc Protocol.
 * @update
 *              v1.0(9-September-2020)
 *              v1.1(24-October-2021)
 *                  1.ï¿½Þ¸ï¿½rc_potocol.c/.h->rc_protocol.c/.h 
 */
 
#ifndef __RC_PROTOCOL_H
#define __RC_PROTOCOL_H

/* Includes ------------------------------------------------------------------*/
#include "rp_config.h"
#include "rc_sensor.h"
#include "VT13_rc_ctrl.h"

/* Exported macro ------------------------------------------------------------*/
#define RC_TYPE 0   // 0: ¾ÉÒ£¿ØÆ÷, 1: VT13Ò£¿ØÆ÷

/* Exported types ------------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void keyboard_update(rc_sensor_info_t *info);
void rc_interrupt_update(rc_sensor_t *rc_sen);
void rc_sensor_init(rc_sensor_t *rc_sen);
void VT13_to_rc(uint8_t *VT13_buf, rc_sensor_info_t *rc_info);

#endif
