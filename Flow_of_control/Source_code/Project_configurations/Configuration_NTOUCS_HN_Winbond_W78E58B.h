/* Configurations_NTOUCS_HN_Winbond_W78E58B.h
程式名稱 | Program name
	Configurations(control signals, ports, and other values of NTOUCS Home Network Winbond W78E58B development board.
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
			#define led P1
		
		/* 按鈕開關 */
			sbit BTN_SW3 = P3^2;
			sbit BTN_SW4 = P3^3;
			sbit BTN_SW5 = P3^4;
			sbit BTN_SW6 = P3^5;
			
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
			#define seven_seg P0
			/* 7 段顯示器的數位數量 */
			#define SEVEN_SEG_DIGIT_NO 4
			/* Renesas(Hitachi) HD74LS373P 控制訊號 */
				sbit seven_seg_latch_position_enable = P2^3;
				sbit seven_seg_latch_font_enable = P2^4;
		
		/* 計時器(timer)／計數器(counter)與外部中斷 */
			/* 計時器(timer)／計數器(counter)外部訊號輸入 */
				sbit CTR1_EXT_SRC = P3^5;
				sbit CTR0_EXT_SRC = P3^4;
				
			/* 外部中斷輸入 */
				sbit EXT_INTERRUPT1_BAR = P3^3;
				sbit EXT_INTERRUPT0_BAR = P3^2;
				
			/* 內部暫存器 */
				#define tmr_ctr1_reg_high TH1
				#define tmr_ctr1_reg_low TL1			
				#define tmr_ctr0_reg_high TH0
				#define tmr_ctr0_reg_low TL0

			/* TCON(Timer/counter CONtrol register) 暫存器 */
				#define tmr_ctr1_overflowed TF1
				#define tmr_ctr1_run TR1
				
				#define tmr_ctr0_overflowed TF0
				#define tmr_ctr0_run TR0
				
				#define EXT_INT1_TRIGGERED IE1
				#define ext_int1_type IT1
				#define EXT_INT0_TRIGGERED IE0
				#define ext_int0_type IT0
			
			/* TMOD(Timer/counter MODe control register) 暫存器 */
				#define tmr_ctr_mode TMOD
			
		/* Serial UART 定義 */
			/* Serial port CONtrol register */
				#define serial_uart_control SCON
				
				/* 模式選擇：實際上代表模式 serial_mode0|serial_mode0 ，與習慣相反 */
					#define serial_mode0 SM0
					#define serial_mode1 SM1
				#define serial_mode2 SM2
				#define serial_recieve_enable REN
				#define SRL_TX_INT_TRIGGERED TI
				#define SRL_RX_INT_TRIGGERED RI
			
			/* Serial UART BUFfer register */
				#define serial_buffer_reg SBUF
			
		/* Power CONtrol register */
			#define power_control_reg PCON
		
		/* Interrupt Enable(IE) register */
			#define int_enable_all EA
			
			#define int_tmr_ctr2_enable ET2
			#define int_tmr_ctr1_enable ET1
			#define int_tmr_ctr0_enable ET0
			
			#define int_serial_uart_enable ES
			
			#define int_ext1_enable_bar EX1
			#define int_ext0_enable_bar EX0
			
		/* Interrupt Priority(IP) register */
			#define int_pri_tmr_ctr2_enable PT2
			#define int_pri_tmr_ctr1_enable PT1
			#define int_pri_tmr_ctr0_enable PT0
			
			#define int_pri_serial_uart_enable PS
			
			#define int_pri_ext1_enable_bar PX1
			#define int_pri_ext0_enable_bar PX0
			
	/*||||| Definition of data type, enumeration, data structure and class |||||*/

	/*||||| 函式雛型 | Function Prototypes |||||*/

	/*||||| 全域變數 | Global Variables |||||*/
	
	#ifdef __cplusplus
		}
	#endif
#endif /* NTOUCS_HN_W78E58B_DEF_INCLUDED */
