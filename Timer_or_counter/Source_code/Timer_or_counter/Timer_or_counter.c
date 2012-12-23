/* 
Timer_or_counter.c
	請見本檔案的 header 檔案以得到更多關於本檔案的說明
*/
/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
	/* 目標微控制器的 SFR 暫存器定義 */
		#include "../Project_configurations/Configuration_NTOUCS_HN_Winbond_W78E58B.h"

	/* for LOGIC_* definition */
		#include "../Project_configurations/Common_definitions.h"
		
	/* Timer_or_counter constants definitions */
		#include "Timer_or_counter.h"
		
/*||||| 常數與巨集 | Constants & Macros |||||*/

/*||||| Definition of data type, enumeration, data structure and class |||||*/

/*||||| 函式雛型 | Function Prototypes |||||*/

/*||||| 全域變數 | Global Variables |||||*/

/*||||| 主要程式碼 | Main Code |||||*/
	void tmr_ctrSetValue16bit(
		/* 設定計時器(timer)／計數器(counter)內部暫存器（16位元） */
		bit selection
			/* 選擇哪一個計時器(timer)／計數器(counter) */, 
		unsigned int value
			/* 要填入暫存器的數值（16位元） */){
		if(selection == TMR_CTR1){
			tmr_ctr1_reg_high = 
				value / /* 2^8 */256;
			tmr_ctr1_reg_low = 
				value % /* 2^8 */256;
		}else{
			tmr_ctr0_reg_high = 
				value / /* 2^8 */256;
			tmr_ctr0_reg_low = 
				value % /* 2^8 */256;
		}
		return;
	}	

	void tmr_ctrSetValueMode2(
		/* 設定計時器(timer)／計數器(counter)內部暫存器（16位元） */
		bit selection
			/* 選擇哪一個計時器(timer)／計數器(counter) */, 
		unsigned char high, 
		unsigned char low
			/* 要填入暫存器的數值（0~255） */){
		tmr_ctrSetValue16bit(selection, high * 256/* 2^8 */ + low);
		return;
	}

	void timerSetPeriod16bit(
		/* 設定16位元計時器(timer)溢位(overflow)週期 */
		bit selection
			/* 選擇哪一個計時器(timer) */, 
		unsigned int period
		/* 讓計時器(timer)暫存器溢位(overflow)所需時間
			 單位
			 　讓計時器(timer)暫存器溢位的遞增次數
			 參數定義域
			 　0（暫存器遞增 1 次就溢位）
			 　~
			 　65535（暫存器遞增 65536 次溢位） */){
		tmr_ctrSetValue16bit(
		selection, 
		(TMR_CTR_REG_MAX_16B - period));
		return;
	}

	void timerSetPeriodMode2(
		/* 設定 8 位元計時器(timer)溢位(overflow)週期(mode2) */
		bit selection
			/* 選擇哪一個計時器(timer)／計數器(counter) */, 
		unsigned int period
		/* 讓計時器(timer)暫存器溢位(overflow)所需時間
			 單位
			 　讓計時器(timer)暫存器溢位的遞增次數
			 參數定義域
			 　0（暫存器遞增 1 次就溢位的時間）
			 　~
			 　255（暫存器遞增 256 次溢位的時間） */){
		tmr_ctrSetValueMode2(
			selection, 
			(TMR_CTR_REG_MAX_8B - period), 
			(TMR_CTR_REG_MAX_8B - period));
	  return;
	}

	void tmr_ctrSetMode(
		bit selection
			/* 選擇哪一個計時器(timer)／計數器(counter) */, 
		unsigned char mode
			/* selection 暫存器的模式
			   (4 bit: 0000_MODEb) */){
	  /* TMOD 暫存器原始內容假設為
		   PREVPREVb */
					 
		if(selection == TMR_CTR1){
			/* 平移 4 個位元到上半 */
				mode *= 0x10;
					/* MODE0000b */
			/* 欲保留 TMOD 暫存器原下半內容
			   將上半內容改為 MODE
			     MODE_0000
			     PREV_PREV
			   ???????????
			     MODE_PREV

			     PREV_PREV		|	     PREV_PREV
			   & 0000_1111		|	   | 1111_0000
			   -----------		|	   -----------
			     0000_PREV		|	     1111_PREV	
			                  |
			     0000_PREV		|	     1111_PREV
			   | MODE_0000		|	   & MODE_1111
			   -----------		|	   -----------
			     MODE_PREV		|	     MODE_PREV		*/	
			   tmr_ctr_mode &= 0x0f/* 0000_1111b */;
		
		}else{
			tmr_ctr_mode &= 0xf0/* 1111_0000b */;
		}
		tmr_ctr_mode |= mode;
		
		return;
	}
	
	void tmr_ctrEnable(
		/* 啟用計時器(timer)／計數器(counter) */
		bit selection
			/* 選擇設定哪一個計時器(timer)／計數器(counter) */){
		if(selection == TMR_CTR1){
			tmr_ctr1_overflow = LOGIC_LOW;
			tmr_ctr1_run = LOGIC_HIGH;
		}else{
			tmr_ctr0_overflow = LOGIC_LOW;
			tmr_ctr0_run = LOGIC_HIGH;
		}
		return;
	}
	
	void tmr_ctrDisable(
		/* 停用計時器(timer)／計數器(counter) */
		bit selection
			/* 選擇設定哪一個計時器(timer)／計數器(counter) */){
		if(selection == TMR_CTR1){
			tmr_ctr1_run = LOGIC_LOW;
			tmr_ctr1_overflow = LOGIC_LOW;
		}else{
			tmr_ctr0_run = LOGIC_LOW;
			tmr_ctr0_overflow = LOGIC_LOW;
		}
		return;
	}

	bit/* boolean */ tmr_ctrIsOverflow(
		bit selection){
		if(selection == TMR_CTR1){
			return tmr_ctr1_overflow;
		}else{
			return tmr_ctr0_overflow;
		}
	}

	void tmr_ctrClearOverflow(bit selection){
		if(selection == TMR_CTR1){
			tmr_ctr1_overflow = LOGIC_LOW;
		}else{
			tmr_ctr0_overflow = LOGIC_LOW;
		}
		return;
	}