/**
  ******************************************************************************
  * @file    control_task.c
  * @brief   
  ******************************************************************************
  */
#include "control_task.h"

float t;
void StartControlTask(void const * argument)
{

	for(;;) 
	{
		if ((imu_sensor.work_state.err_code == IMU_NONE_ERR) || \
				(imu_sensor.work_state.err_code == IMU_DATA_CALI))
		{
			imu_sensor.update(&imu_sensor);
			
		}
		
		Yaw_Motor.tx_info->torque = t;
		Yaw_Motor.single_set_torque(&Yaw_Motor);
		osDelay(1);
	}
}



