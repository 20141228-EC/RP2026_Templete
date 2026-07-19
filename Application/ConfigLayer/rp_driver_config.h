#ifndef __RP_DRIVER_CONFIG_H
#define __RP_DRIVER_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stdbool.h"

/* Exported macro ------------------------------------------------------------*/
#define configDRV_CAN_USE_MAIL  1

/* Exported types ------------------------------------------------------------*/
/* ?????? --------------------------------------------------------------------*/
/**
 *	@brief	????????
 *	@class	driver
 */
typedef enum drv_type{
		DRV_CAN,
		DRV_PWM,
		DRV_SPI,
		DRV_IIC,
		DRV_UART,
} drv_type_t;

/**
 *	@brief	can???? id
 *	@class	driver
 */
typedef enum {
    DRV_CAN1,
    DRV_CAN2
} can_id_t;

/**
 *	@brief	iic???? id
 *	@class	driver
 */
typedef enum {
    DRV_IIC1
} iic_id_t;

/**
 *	@brief	spi???? id
 *	@class	driver
 */
typedef enum {
    DRV_SPI1
} spi_id_t;

/**
 *	@brief	uart???? id
 *	@class	driver
 */
typedef enum {
    DRV_UART1,
    DRV_UART2,
    DRV_UART3,
    DRV_UART4,
    DRV_UART5,
		DRV_UART6,
} uart_id_t;

/**
 *	@brief	iic????
 *	@class	driver
 */
typedef struct drv_iic {
    drv_type_t 	type;
		iic_id_t 	id;
} drv_iic_t;

/**
 *	@brief	can????
 *	@class	driver
 */
typedef struct drv_can {
    can_id_t    can_id;				// CAN1??CAN2
    uint32_t    err_cnt;
	uint32_t	rx_id;  		// ????????????
	uint32_t	tx_id;  		// ???????????
	uint8_t		data_id;		// ?????¡À?
    uint16_t    tx_period;  	// ?????????(ms)
	uint8_t		*CANx_XXX_DATA; // ?????????
} drv_can_t;

/**
 *	@brief	pwm????
 *	@class	driver
 */
typedef struct drv_pwm {
		drv_type_t	type;
		void				(*output)(struct drv_pwm *self, int16_t pwm);
} drv_pwm_t;

/**
 *	@brief	uart????
 *	@class	driver
 */
typedef struct drv_uart {
		drv_type_t	type;
    uart_id_t   id;
	    UART_HandleTypeDef *huart;
		void				(*tx_byte)(struct drv_uart *self, uint8_t byte);
} drv_uart_t;

#endif
