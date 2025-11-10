/**
 ******************************************************************************
 * @file    monitor_task.c
 * @brief   监控任务
 *          1. 各模块心跳失联检测
 *          2. 监控遥控器状态，软件复位
 ************* *****************************************************************
 */
#include "monitor_task.h"

float volume=1;
float fre=1;
void StartMonitorTask(void const *argument)
{
	
	//buzzer.init(&buzzer);
	
	for (;;)
	{
		if ((imu_sensor.work_state.err_code == IMU_NONE_ERR) || \
				(imu_sensor.work_state.err_code == IMU_DATA_CALI))
		{
			imu_sensor.update(&imu_sensor);
			
		}
		buzzer.base_info.input_info.freq=fre;
		buzzer.base_info.input_info.volume=volume;
		buzzer.work(&buzzer);
       
        
		
		osDelay(1);
	}
}

