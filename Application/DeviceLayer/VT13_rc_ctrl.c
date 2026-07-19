/**
 * @file        VT13_rc_ctrl.c
 * @brief       VT13遥控器协议解析
 */
 
/* Includes ------------------------------------------------------------------*/
#include "VT13_rc_ctrl.h"
#include "crc.h"

/**
 * @brief          VT13遥控器协议解析
 * @param[in]      VT13_buf: 原生数据指针
 * @param[out]     rc_info: 遥控器数据结构指针
 * @retval         none
 */
void VT13_to_rc(uint8_t *VT13_buf, rc_sensor_info_t *rc_info)
{
    if (VT13_buf == NULL || rc_info == NULL)
        return;

    if (VT13_buf[0] == 0xA9 && VT13_buf[1] == 0x53 &&
        Verify_CRC16_Check_Sum(VT13_buf, VT13_FRAME_LEN))
    {
        rc_info->ch0 = ((VT13_buf[2] | (VT13_buf[3] << 8)) & 0x07FF) - 1024;
        rc_info->ch1 = (((VT13_buf[3] >> 3) | (VT13_buf[4] << 5)) & 0x07FF) - 1024;
        rc_info->ch2 = (((VT13_buf[4] >> 6) | (VT13_buf[5] << 2) | (VT13_buf[6] << 10)) & 0x07FF) - 1024;
        rc_info->ch3 = (((VT13_buf[6] >> 1) | (VT13_buf[7] << 7)) & 0x07FF) - 1024;

        rc_info->s1.value = (VT13_buf[7] >> 4) & 0x03;
        rc_info->s2.value = RC_SW_MID;
        rc_info->stop = (VT13_buf[7] >> 6) & 0x01;
        rc_info->left_button = (VT13_buf[7] >> 7) & 0x01;
        rc_info->right_button = VT13_buf[8] & 0x01;
        rc_info->thumbwheel.value = (((VT13_buf[8] >> 1) | (VT13_buf[9] << 7)) & 0x07FF) - 1024;
        rc_info->shutter = (VT13_buf[9] >> 4) & 0x01;

        rc_info->mouse_vx = VT13_buf[10] | (VT13_buf[11] << 8);
        rc_info->mouse_vy = VT13_buf[12] | (VT13_buf[13] << 8);
        rc_info->mouse_vz = VT13_buf[14] | (VT13_buf[15] << 8);

        rc_info->mouse_btn_l.value = VT13_buf[16] & 0x03;
        rc_info->mouse_btn_r.value = (VT13_buf[16] >> 2) & 0x03;
        rc_info->mouse_btn_m.value = (VT13_buf[16] >> 4) & 0x03;

        rc_info->key_v = VT13_buf[17] | (VT13_buf[18] << 8);

        rc_info->W.value = KEY_PRESSED_W;
        rc_info->S.value = KEY_PRESSED_S;
        rc_info->A.value = KEY_PRESSED_A;
        rc_info->D.value = KEY_PRESSED_D;
        rc_info->Shift.value = KEY_PRESSED_SHIFT;
        rc_info->Ctrl.value = KEY_PRESSED_CTRL;
        rc_info->Q.value = KEY_PRESSED_Q;
        rc_info->E.value = KEY_PRESSED_E;
        rc_info->R.value = KEY_PRESSED_R;
        rc_info->F.value = KEY_PRESSED_F;
        rc_info->G.value = KEY_PRESSED_G;
        rc_info->Z.value = KEY_PRESSED_Z;
        rc_info->X.value = KEY_PRESSED_X;
        rc_info->C.value = KEY_PRESSED_C;
        rc_info->V.value = KEY_PRESSED_V;
        rc_info->B.value = KEY_PRESSED_B;

        rc_info->offline_cnt = 0;
    }
}
