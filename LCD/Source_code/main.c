/* 
主程式
	請見本檔案的header檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
	/* Standard io library definition? */
		#include <stdio.h>

	/* Definitions of 8052 register constants
		 　如果您要直接存取而非透過 Project_configurations/Ports_and_control_signals_* 來存取硬體的話需引入此檔案
		#include <REG52.h> */

	/* Project_configurations */
		#include "Project_configurations/Common_definitions.h"

	/* Hardware_configurations */
		#include "Hardware_configurations/NTOUCS_Home_Network_51AVR.h"
		
	/* test target */
		#include "LCD/LCD.h"
	
	/* Button_switch */
		#include "Button_switch/Button_switch.h"
		
	/* Timer_or_counter */
		#include "Timer_or_counter/Timer_or_counter.h"
	
	/* Flow_of_control */
		#include "Flow_of_control/Flow_of_control.h"

	/* LED */
		#include "LED/LED.h"
		
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 中斷服務子程式 */
		void cbExtInt0(void);
		void cbExtInt1(void);
		void cbTimer0(void);
		void cbTimer1(void);
		void cbSerialUART(void);
		
	/* test target */
		void testInitialization(void);
		void testlcdOff(void);
		void testlcdOn(void);
		void testPrintCharMap(void);
		void testlcdSetPositionCursur(void);
		void testlcdMoveCursur(void);
		void testlcdPrintDecimal16bit(void);
		void testlcdPrintDecimal8bit(void);
		void testlcdPrintChar(void);
		void testlcdPrintString(void);
		
/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
	/* 程式進入點 | Program entry point
		 　因為嵌入式系統開機之後就會執行到電源關閉，故不需要回傳值*/
	void main(void){
		initializeSystem();
		
		/* main loop */
		while(TRUE){
#if 0
			testInitialization();
			testlcdOn();
			testlcdOff();
			testlcdPrintDecimal8bit();
			testlcdPrintDecimal16bit();
			testPrintCharMap();
			testlcdSetPositionCursur();
			testlcdSetPositionCursur();
			testlcdMoveCursur();
			testlcdPrintChar();
			testlcdPrintString();
#endif
			testlcdPrintString();
			
			ledBlinkSecond(TMR_CTR0, 1);
			delaySecond(TMR_CTR0, 1);
			ledDisplayValue(LED_ALL);

			hangForever();
		}
		
		return;
	}

	/* 外部中斷 callback 函式 */
		void cbExtInt0(void) interrupt 0{
			return;
		}
		
		void cbExtInt1(void) interrupt 2{
			return;
		}
		
	/* 計時器／計數器中斷 callback 函式 */
		void cbTimer0(void) interrupt 1{
			return;
		}
		
		void cbTimer1(void) interrupt 3{
			return;
		}
		
	/* 序列式 UART 介面中斷 callback 函式 */
		void cbSerialUART(void) interrupt 4{
			return;
		}
	
	void testInitialization(void){
		while(button_swIsPressed(BTN_SW6) == FALSE){
			;
		}
		return;
	}
	
	void testlcdOn(void){
		/* none */
			lcdOn(FALSE, FALSE);
			while(button_swIsPressed(BTN_SW6) == FALSE){
				;
			}
			ledBlinkSecond(TMR_CTR0, 1);

		/* blink */
			lcdOn(FALSE, TRUE);
			while(button_swIsPressed(BTN_SW6) == FALSE){
				;
			}		
			ledBlinkSecond(TMR_CTR0, 1);

		/* cursur */
			lcdOn(TRUE, FALSE);
			while(button_swIsPressed(BTN_SW6) == FALSE){
				;
			}
			ledBlinkSecond(TMR_CTR0, 1);

		/* cursur and blink */
			lcdOn(TRUE, TRUE);
			while(button_swIsPressed(BTN_SW6) == FALSE){
				;
			}

		return;
	}

	void testlcdOff(void){
		lcdOff();
		while(button_swIsPressed(BTN_SW6) == FALSE){
			;
		}
		ledBlinkSecond(TMR_CTR0, 1);
		
		return;
	}

	void testlcdSetPositionCursur(void){
		lcdOn(TRUE, FALSE);
		lcdSetPositionCursur(LCD_INST_POSITION_ROW1 + 10);
		while(button_swIsPressed(BTN_SW6) == FALSE){
			;
		}
		lcdOff();		
		return;
	}
	
	void testlcdMoveCursur(void){
		lcdOn(TRUE, TRUE);
		lcdSetPositionCursur(LCD_INST_POSITION_ROW2 + 10);
		while(button_swIsPressed(BTN_SW6) == FALSE){
			lcdMoveCursur(LCD_DIR_RIGHT, 1);
			delaySecond(TMR_CTR0, 1);
		}
		ledBlinkSecond(TMR_CTR0, 1);
		while(button_swIsPressed(BTN_SW6) == FALSE){
			lcdMoveCursur(LCD_DIR_LEFT, 1);
			delaySecond(TMR_CTR0, 1);
		}
		lcdOff();
		return;
	}
	
	void testPrintCharMap(void){
		unsigned char column = 0;
		bit row = 0;
		unsigned char char_code = 0;
		
		lcdOn(TRUE, TRUE);
		lcdExecInstruction(LCD_PHYSICAL_MODE);
		while(button_swIsPressed(BTN_SW6) == FALSE){
			lcdExecInstruction(((!row)? LCD_INST_POSITION_ROW1 : LCD_INST_POSITION_ROW2) + column++);
			lcdWriteData(char_code++);
			if(column == 16){
				row = !row;
				column = 0;
			}
			delay(12345);
		}
		
		lcdClear();
		lcdOff();
		return;
	}
	
	void testlcdPrintDecimal16bit(void){
		unsigned int i;
		
		lcdOn(FALSE, FALSE);
		for(i = 0; i < 65535; ++i){
			lcdPrintDecimal16bit(i);
			lcdMoveCursur(LCD_DIR_LEFT, 5);
			if(button_swIsPressed(BTN_SW6) == TRUE){
				break;
			}else{
				delay(0);
			}
		}
		lcdClear();
		lcdOff();		
		return;		
	}
	
	void testlcdPrintDecimal8bit(void){
		unsigned char i;
		
		lcdOn(TRUE, FALSE);
		for(i = 0; i <= 255; ++i){
			lcdPrintDecimal8bit(i);
			if(button_swIsPressed(BTN_SW6) == TRUE){
				break;
			}else{
				delaySecond(TMR_CTR0, 1);
			}			lcdMoveCursur(LCD_DIR_LEFT, 3);
		}

		lcdClear();
		lcdOff();		
		return;		
	}
	
	void testlcdPrintChar(void){
		lcdOn(TRUE, FALSE);
		lcdPrintChar('C');
		lcdPrintChar('a');
		lcdPrintChar('t');
		lcdPrintChar('.');
		
		while(button_swIsPressed(BTN_SW6) == FALSE){
			;
		}
		
		lcdClear();
		lcdOff();		
		return;
	}
	
	void testlcdPrintString(void){
		lcdOn(TRUE, FALSE);
		lcdPrintString("testlcdPrintString() called.");
		while(button_swIsPressed(BTN_SW6) == FALSE){
			;
		}
		
		lcdClear();
		lcdOff();		
		return;
	}