/* 
LCD.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	/* Hardware_configurations */
		#include "../Hardware_configurations/NTOUCS_Home_Network_51AVR.h"
		
	/* self definitions */
		#include "LCD.h"
		
	/* delay procedure definitions */
		#include "../Flow_of_control/Flow_of_control.h"

#ifndef NDEBUG
	/* LED procedures */
		#include "../LED/LED.h"
	
	/* TMR_CTRn definition */
		#include "../Timer_or_counter/Timer_or_counter.h"
#endif 

/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
	void lcdWaitIdle(
		/* 等待 LCD 控制器離開忙碌狀態 */
		void){
		lcd_busy = LOGIC_HIGH;
		lcd_register_select = LCD_REG_INSTRUCTION;
		lcd_read_write_bar = LOGIC_HIGH;
		lcd_enable = LOGIC_HIGH;
		while(lcd_busy == LOGIC_HIGH){
			/* do nothing */;
#ifndef NDEBUG			
			ledBlinkSecond(TMR_CTR0, 1);
			delaySecond(TMR_CTR0, 1);
#endif
		}
		lcd_enable = LOGIC_LOW;
		
		return;
	}
		
	void lcdExecInstruction(
			/* 寫入指令至 lcd 指令暫存器中並執行之 */
		unsigned char instruction){
		lcdWaitIdle();
		lcd_register_select = LCD_REG_INSTRUCTION;
		lcd_read_write_bar = LOGIC_LOW;
		lcd = instruction;
		/* 給 lcd 一個脈衝訊號，讓它趕快收(?) */
		lcd_enable = LOGIC_HIGH;
		/* 等 lcd 處理的時間（至少要 195ns）（待測試） */
			delay8bit(LCD_INST_GENERIC_TIME);
		lcd_enable = LOGIC_LOW;	
		return;
	}
	
	void lcdWriteData(
		/* 寫入資料至 lcd 資料暫存器中 */
		unsigned char datum){
		lcdWaitIdle();
		lcd_register_select = LCD_REG_DATA;
		lcd_read_write_bar = LOGIC_LOW;
		lcd = datum;
		/* 給 lcd 一個脈衝訊號，讓它趕快收(?) */
		lcd_enable = LOGIC_HIGH;
		/* 等 lcd 處理的時間（至少要 195ns）（待測試） */
			delay8bit(LCD_INST_GENERIC_TIME);
		lcd_enable = LOGIC_LOW;	
		return;
	}
	
	void lcdOn(
		/* 開啟螢幕 */
		bit cursur, 
		bit blink){
		unsigned char instruction = 
			LCD_INST_PRT_SWITCH | LCD_INST_PRT_DISPLAY_ON;
			
		if(cursur){
			instruction |= LCD_INST_PRT_CURSOR_ON;
		}
		
		if(blink){
			instruction |= LCD_INST_PRT_BLINK_ON;
		}
		
		lcdExecInstruction(instruction);
		return;
	}
	
	void lcdOff(
		/* 關閉螢幕 */
		void){
		lcdExecInstruction(
			LCD_INST_OFF);
		return;
	}
	
	void lcdClear(
		/* 清除螢幕內容 */
		void){
		lcdExecInstruction(
			LCD_INST_CLEAR);
		/* delay(LCD_INST_CLEAR_TIME); */
		return;
	}
	
	void lcdSetPositionCursur(
		unsigned position){
		lcdExecInstruction(position);
		return;
	}
	
	void lcdMoveCursur(
		/* 移動游標子程式 */
		bit direction
			/* 移動方向(LCD_DIR_*) */, 
		unsigned char length
			/* 移動距離 */){
		/* setDirection() */
			lcdExecInstruction(
				LCD_INST_PRT_MODE | 
				((direction == LCD_DIR_RIGHT) ? 
					LCD_INST_PRT_CUR_INCRE : 0x0));

		/* moveCursur() */
			do{
				lcdExecInstruction(LCD_INST_PRT_CTRL | 
					((direction == LCD_DIR_RIGHT) ? 
						LCD_INST_PRT_RGT_LFT_BAR : 0x0));
#ifndef NDEBUG	
				delaySecond(TMR_CTR0, 1);
#endif				
				--length;
			}while(length > 0);
		
		/* resetDirection() */
			lcdExecInstruction(
				LCD_INST_PRT_MODE | LCD_INST_PRT_CUR_INCRE);
		return;
	}
	
	void lcdPrintDecimal16bit(
		unsigned int content
			/* 顯示內容(0~65535) */)	{
		unsigned char digit;
		/* 游標移動到後 4 格 */
			lcdMoveCursur(LCD_DIR_RIGHT, 4);
				
		/* 改為寫入字元後游標左移 */
			lcdExecInstruction(LCD_INST_PRT_MODE);
			
		for(digit = 1; digit <= 5; ++digit){
			lcdWriteData('0' + content % 10);
			content /= 10;
#ifndef NDEBUG	
			delaySecond(TMR_CTR0, 1);
#endif
		}
		
		/* 游標移動到後6格 */
			lcdMoveCursur(LCD_DIR_RIGHT, 6);
			
		/* 改為寫入字元後游標右移（預設值） */
			lcdExecInstruction(LCD_INST_PRT_MODE);
		return;
	}

	void lcdPrintDecimal8bit(
		unsigned char content
			/* 顯示內容(0~255) */)	{
		unsigned char digit;
		/* 游標移動到後 2 格 */
			lcdMoveCursur(LCD_DIR_RIGHT, 2);
				
		/* 改為寫入字元後游標左移 */
			lcdExecInstruction(LCD_INST_PRT_MODE);
					
		for(digit = 0; digit < 3; ++digit){
			lcdWriteData('0' + content % 10);
			content /= 10;
#ifndef NDEBUG	
			delaySecond(TMR_CTR0, 1);
#endif
		}
		
		/* 游標移動到後 4 格 */
			lcdMoveCursur(LCD_DIR_RIGHT, 4);
			
		/* 改為寫入字元後游標右移（預設值） */
			lcdExecInstruction(LCD_INST_PRT_MODE);
		return;
	}
	
	void lcdPrintChar(
		/* */
		unsigned char character){
			
		lcdWriteData(character);
		return;
	}

	void lcdPrintString(
		/* 印出字串子程式 */
		const unsigned char string[]){
		unsigned char *ptr;
			
		for(ptr = string; *ptr != '\0'; ++ptr){
			lcdWriteData(*ptr);
		}
		return;
	}