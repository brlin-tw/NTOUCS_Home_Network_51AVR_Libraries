/* LED.h
程式名稱 | Program name
	8 位元 LED 控制函式庫
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	8 位元 LED 控制函式庫 is part of NTOU_W78E58B_libraries
	NTOU_W78E58B_libraries is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	NTOU_W78E58B_libraries is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with NTOU_W78E58B_libraries.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
#ifndef LED_H_INCLUDED
	#define LED_H_INCLUDED
	/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/

	/*||||| 常數與巨集 | Constants & Macros |||||*/
		/* LED position definitions */
			/* 1000_0000b */
				#define LED7 0x80
				#define D8 0x80			
				#define LED_HIGHEST 0x80			
			/* 0100_0000b */
				#define LED6 0x40
				#define D7 0x40			
			/* 0010_0000b */
				#define LED5 0x20
				#define D6 0x20
			/* 0001_0000b */
				#define LED4 0x10
				#define D5 0x10
			/* 0000_1000b */
				#define LED3 0x08
				#define D4 0x08
			/* 0000_0100b */
				#define LED2 0x04
				#define D3 0x04
			/* 0000_0010b */	
				#define LED1 0x02	
				#define D2 0x02
			/* 0000_0001b */
				#define LED0 0x01
				#define D1 0x01
				#define LED_LOWEST 0x01
		
		/* 多重 LED pattern 定義 */
			/* 1111_1111b */
				#define LED_ALL 0xFF
			/* 0000_0000b */
				#define LED_NONE 0x00
			/* 1111_0000b */
				#define LED_HALF_UP 0xF0
			/* 0000_1111b */
				#define LED_HALF_DOWN 0x0F
			/* 1010_1010b */
				#define LED_ODD 0xAA
			/* 0101_0101b */
				#define LED_EVEN 0x55
		
	/*||||| Definition of data type, enumeration, data structure and class |||||*/

	/*||||| 函式雛型 | Function Prototypes |||||*/
		void ledDisable(
			/* 關閉 LED 顯示 */
			void);
				
		void ledDisplayValue(unsigned char value);
			/* 顯示數值至 LED
				 　value
				 　　要顯示的 8 位元數值，由 LED_LIT 決定什麼條件下發光 */

		/* 輪轉(rotate)相關函式 */
			#define LED_ROTATE_UP 1
				/* 往高位數輪轉 */
			#define LED_ROTATE_DOWN 0
				/* 往低位數輪轉 */
			void ledRotateOneWay(
				/* 讓 LED 從一邊亮到另外一邊 */
				unsigned char initial_position
					/* 初始位置 */, 
				bit direction
					/* 輪動方向 */, 
				void (*delay)(unsigned int)
					/* 用來當作輪動周期的時間延遲函式 */, 
				unsigned int interval
					/* 輪動週期（從一個 LED 跳到下一個 LED 的時間）
  					 會直接傳遞給 *delay(interval) */
			);
			void ledRotateTwoWay(
				/* 讓 LED 從一邊亮到另外一邊...再亮回來 */
				bit initial_direction
					/* 第一次輪轉的轉動方向 */, 
				void (*delay)(unsigned int)
					/* 用來當作輪動周期的時間延遲函式 */, 
				unsigned int interval
					/* 輪動週期（從一個 LED 跳到下一個 LED 的時間） */
			);
				
		void ledBlinkSecond(
			/* 讓 LED 亮一下再熄掉 */
			bit timer
				/* 用來計時的計時器 */, 
			unsigned char interval
				/* 亮一下的時間 */
		);
		
	/*||||| 全域變數 | Global Variables |||||*/
		/* 讓 LED 位置可以直接透過陣列索引值變數取得 */
			extern code unsigned char led_position[8];
			
	#ifdef __cplusplus
		}
	#endif
#endif /* LED_H_INCLUDED */
