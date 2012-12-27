/* 
Serial_UART.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	/* itself definition */
		#include "Serial_UART.h"
		
	/* for timer procedures */
		#include "../Timer_or_counter/Timer_or_counter.h"
		
	/* for hang procedures */
		#include "../Flow_of_control/Hang.h"

	/* for LOGIC_* */
		#include "../Project_configurations/Common_definitions.h"
		
	/* for control signal definition */
		#include "../Project_configurations/Configuration_NTOUCS_HN_Winbond_W78E58B.h"
		
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
	void serial_uartSetSMOD(
		bit position
			/* HIGH or LOW */){
		if(position == LOGIC_HIGH){
			power_control_reg = 
				power_control_reg | 
				/* 1000_0000b */0x80;
		}else{
			power_control_reg = 
				power_control_reg & 
				/* 0111_1111b */0x7F;
		}
		return;
	}
	
	void serial_uartMode1Enable(
		/* 啟動 UART */
		Oscillator_type oscillator
			/* 晶體振盪器的類型 */, 
		Baud_rate_type rate
			/* 要使用的傳輸速率 */, 
		bit timer){
		tmr_ctrDisable(timer);
		serial_uart_control = 
			/* 0101_0000b */0x50;
		switch(oscillator){
		case OSC_11_0592:
			switch(rate){
			case BAUD_1200:
				tmr_ctrSetMode(timer, TMR_CTR_MODE2);
				tmr_ctrSetValueMode2(
					timer, 
					UART_TMRM2_11_0952_1200_RELOAD, 
					UART_TMRM2_11_0952_1200_RELOAD);				
				serial_uartSetSMOD(LOGIC_LOW);
				break;
			case BAUD_2400:
				tmr_ctrSetMode(timer, TMR_CTR_MODE2);
				tmr_ctrSetValueMode2(
					timer, 
					UART_TMRM2_11_0952_2400_RELOAD, 
					UART_TMRM2_11_0952_2400_RELOAD);
				serial_uartSetSMOD(LOGIC_LOW);
				break;				
			case BAUD_4800:
				tmr_ctrSetMode(timer, TMR_CTR_MODE2);
				tmr_ctrSetValueMode2(
					timer, 
					UART_TMRM2_11_0952_4800_RELOAD, 
					UART_TMRM2_11_0952_4800_RELOAD);
				serial_uartSetSMOD(LOGIC_LOW);
				break;
			case BAUD_9600:
				tmr_ctrSetMode(timer, TMR_CTR_MODE2);
				timerSetPeriodMode2(timer, UART_TMRM2_11_0952_9600_PERIOD);
				serial_uartSetSMOD(LOGIC_LOW);
				break;
			case BAUD_19200:
				tmr_ctrSetMode(timer, TMR_CTR_MODE2);
				tmr_ctrSetValueMode2(
					timer, 
					UART_TMRM2_11_0952_19200_RELOAD, 
					UART_TMRM2_11_0952_19200_RELOAD);
				serial_uartSetSMOD(LOGIC_HIGH);
				break;			
			case BAUD_137500:
				tmr_ctrSetMode(timer, TMR_CTR_MODE2);
				tmr_ctrSetValueMode2(
					timer, 
					UART_TMRM2_11_0952_137500_RELOAD, 
					UART_TMRM2_11_0952_137500_RELOAD);
				serial_uartSetSMOD(LOGIC_LOW);
				break;			
			default:
				hangForever();
				break;
			}
			break;
	default:
			hangForever();
			break;
		}

		tmr_ctrEnable(timer); 
		return;
	}