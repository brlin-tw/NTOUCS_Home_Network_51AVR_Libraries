/* Ports_and_control_signals_NTOUCS_HN_Winbond_W78E58B.h
程式名稱 | Program name
	Ports and control signals definition of NTOUCS Home Network Winbond W78E58B development board.
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	Ports and control signals definition of NTOUCS Home Network Winbond W78E58B development board is part of NTOUCS_Home_Network_W78E58B_board_libraries
	NTOUCS_Home_Network_W78E58B_board_libraries is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	NTOUCS_Home_Network_W78E58B_board_libraries is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with NTOUCS_Home_Network_W78E58B_board_libraries.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
#ifndef NTOUCS_HN_W78E58B_DEF_INCLUDED
	#define NTOUCS_HN_W78E58B_DEF_INCLUDED
	/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
		/* Special Function Registers(SFR) definitions of generic 8052 microcontroller
		   　Cx51 User's Guide: Special Function Registers
		   　http://www.keil.com/support/man/docs/c51/c51_le_sfrs.htm */
			#include <reg52.h>
		
	/*||||| 常數與巨集 | Constants & Macros |||||*/
		/* 8 位元 LED
			 　連接至 W78E58B 的 P1 連接埠*/
			#define LED P1
		
		/* 按鈕開關 */
			sbit switch3 = P3^2;
			sbit switch4 = P3^3;
			sbit switch5 = P3^4;
			sbit switch6 = P3^5;
			
		/* 類比→數位轉換器(ADC) */
			#define ADC P0
			sbit adc_chip_select_bar_read_bar = P2^6;
				/* 開啟 ADC 至 bus 輸出的訊號 */
				
		/* DIP 封裝指撥開關 */
			#define DIP_SW P0
			sbit dip_sw_chip_enable_bar = P2^5;
				/* 開啟 DIP 開關至 bus 輸出的訊號 */
		
		/* 液晶螢幕(LCD) */
			sbit lcd_enable = P2^2;
				/* 啟用 LCD 訊號 */
			sbit lcd_register_select = P2^0;
				/* LCD 暫存器選擇信號 */
			sbit lcd_read_write_bar = P2^1;
				/* LCD 暫存器讀寫 */	
		
		/* 7 段顯示器 */
			#define SEVEN_SEG P0
			/* Renesas(Hitachi) HD74LS373P 控制訊號 */
				sbit seven_seg_latch_position_enable = P2^3;
				sbit seven_seg_latch_font_enable = P2^4;
		
		/* 計時器(timer)／計數器(counter)與外部中斷 */
			/* 計時器(timer)／計數器(counter)外部訊號輸入 */
				#define tmr_ctr1_ext_src T1
				#define tmr_ctr0_ext_src T0
				
			/* 外部中斷輸入 */
				#define ext_interrupt1_bar INT1
				#define ext_interrupt0_bar INT0
				
			/* 內部暫存器 */
				#define tmr_ctr1_reg_high TH1
				#define tmr_ctr1_reg_low TL1			
				#define tmr_ctr0_reg_high TH0
				#define tmr_ctr0_reg_low TL0

			/* TCON(Timer/counter CONtrol register) 暫存器 */
				#define tmr_ctr1_overflow TF1
				#define tmr_ctr1_run TR1
				#define tmr_ctr0_overflow TF0
				#define tmr_ctr0_run TR0
				
				#define ext_int1_triggered IE1
				#define ext_int1_type IT1
				#define ext_int0_triggered IE0
				#define ext_int0_type IT0
			
			/* TMOD(Timer/counter MODe control register) 暫存器 */
				#define tmr_ctr_mode TMOD
			
		/* RS-232 連接埠定義 */
			
	/*||||| Definition of data type, enumeration, data structure and class |||||*/

	/*||||| 函式雛型 | Function Prototypes |||||*/

	/*||||| 全域變數 | Global Variables |||||*/
	
	#ifdef __cplusplus
		}
	#endif
#endif /* NTOUCS_HN_W78E58B_DEF_INCLUDED */
