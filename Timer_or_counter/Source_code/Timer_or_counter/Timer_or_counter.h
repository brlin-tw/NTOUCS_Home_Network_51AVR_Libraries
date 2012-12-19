/* Timer_or_counter.h
程式名稱 | Program name
	Timer_or_counter control library
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	Timer_or_counter control library is part of NTOUCS_Home_Network_W78E58B_board_libraries
	NTOUCS_Home_Network_W78E58B_board_libraries is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	NTOUCS_Home_Network_W78E58B_board_libraries is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with NTOUCS_Home_Network_W78E58B_board_libraries.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
#ifndef TIMER_OR_COUNTER_H_INCLUDED
	#define TIMER_OR_COUNTER_H_INCLUDED
	/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/

	/*||||| 常數與巨集 | Constants & Macros |||||*/
		/* 用於指定計時器(timer)／計數器(counter) */
			#define TMR_CTR1 1
			#define TMR_CTR0 0
	
		/* 用於 tmr_ctrSetMode() 中指定計時器(timer)／計數器(counter)模式 */
			#define TMR_CTR_GATE_INT 0x08
			#define TMR_CTR_CTR_TMR_BAR 0x04
			#define TMR_CTR_MODE0 0x00
			#define TMR_CTR_MODE1 0x01
			#define TMR_CTR_MODE2 0x02
			#define TMR_CTR_MODE3 0x03
			
		/* 用於 tmr_ctrRegisterSetValue*() */
			#define TMR_CTR_REG_MAX_16B 65535
		
		/* 用於 timerSetPeriod16bit() */
			#define TMR_16B_11_0592_MHZ_1S_PERIOD 61440
			#define TMR_16B_11_0592_MHZ_1S_COUNT 15
			
	/*||||| Definition of data type, enumeration, data structure and class |||||*/

	/*||||| 函式雛型 | Function Prototypes |||||*/
		void tmr_ctrSetValue16bit(
			/* 設定計時器(timer)／計數器(counter)內部暫存器（16位元） */
			bit selection
				/* 選擇哪一個計時器(timer)／計數器(counter) */, 
			unsigned int value
				/* 要填入暫存器的數值（0~65535） */);

		void timerSetPeriod16bit(
			/* 設定16位元計時器(timer)週期 */
			bit selection
				/* 選擇哪一個計時器(timer)／計數器(counter) */, 
			unsigned int period
				/* 計時器(timer)溢位(overflow)的時間（單位： */);
				
		void tmr_ctrSetMode(
			/* 設定計時器(timer)／計數器(counter)的模式 */
			bit selection
				/* 選擇設定哪一個計時器(timer)／計數器(counter) */, 
			unsigned char mode);
			
		void tmr_ctrEnable(
			/* 啟用計時器(timer)／計數器(counter) */
			bit selection
				/* 選擇設定哪一個計時器(timer)／計數器(counter) */);
		
		void tmr_ctrDisable(
			/* 停用計時器(timer)／計數器(counter) */
			bit selection
				/* 選擇設定哪一個計時器(timer)／計數器(counter) */);
		
		bit tmr_ctrIsOverflow(bit selection);
		void tmr_ctrClearOverflow(bit selection);
	/*||||| 全域變數 | Global Variables |||||*/
	
	#ifdef __cplusplus
		}
	#endif
#endif
