/* Serial_UART.h
程式名稱 | Program name
	串列式 Universal Asynchronous Receiver/Transmitter(UART)（通用非同步式接收／傳輸器）資料傳輸介面控制函式庫
	Serial Universal Asynchronous Receiver/Transmitter(UART) data transmission interface control library
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	串列式 Universal Asynchronous Receiver/Transmitter(UART)（通用非同步式接收／傳輸器）資料傳輸介面控制函式庫 is part of 海洋大學資訊工程學系 家庭網路設備設計與控制 W78E58B 開發版函式庫
	海洋大學資訊工程學系 家庭網路設備設計與控制 W78E58B 開發版函式庫 is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	海洋大學資訊工程學系 家庭網路設備設計與控制 W78E58B 開發版函式庫 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with 海洋大學資訊工程學系 家庭網路設備設計與控制 W78E58B 開發版函式庫.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
#ifndef SERIAL_UART_H_INCLUDED
	#define SERIAL_UART_H_INCLUDED
	/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/

	/*||||| 常數與巨集 | Constants & Macros |||||*/
		#define UART_TMRM2_11_0952_137500_RELOAD 0x1d
		#define UART_TMRM2_11_0952_19200_RELOAD 0xfd
		#define UART_TMRM2_11_0952_9600_PERIOD (3 - 1/* shift 1 to match param domain */)
		#define UART_TMRM2_11_0952_4800_RELOAD 0xfa
		#define UART_TMRM2_11_0952_2400_RELOAD 0xf4
		#define UART_TMRM2_11_0952_1200_RELOAD 0xe8
			
	/*||||| Definition of data type, enumeration, data structure and class |||||*/
		typedef enum oscillator_type{
			OSC_11_0592
		}Oscillator_type;
		
		typedef enum baud_rate_type{
			BAUD_1200, 
			BAUD_2400, 
			BAUD_4800, 
			BAUD_9600, 
			BAUD_19200, 
			BAUD_137500
		}Baud_rate_type;
		
	/*||||| 函式雛型 | Function Prototypes |||||*/
		void serial_uartSetSMOD(
			bit position
				/* HIGH or LOW */);
		
		void serial_uartMode1Enable(
			/* 啟動 UART */
			Oscillator_type oscillator
				/* 晶體振盪器的類型 */, 
			Baud_rate_type rate
				/* 要使用的傳輸速率 */, 
			bit timer
		);
		
	/*||||| 全域變數 | Global Variables |||||*/
	
	#ifdef __cplusplus
		}
	#endif
#endif
