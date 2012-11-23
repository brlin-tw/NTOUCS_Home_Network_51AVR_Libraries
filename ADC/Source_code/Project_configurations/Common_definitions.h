/* Common_definitions.h
程式名稱 | Program name
	Common definitions of 8051 C program
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	Common definitions of 8051 C program is part of Project_configurations
	Project_configurations is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	Project_configurations is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with Project_configurations.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個header檔案被include第二次 */
#ifndef COMMON_DEFINITIONS_H_INCLUDED
	#define COMMON_DEFINITIONS_H_INCLUDED
	/* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/
		/* macro definition of 8051 */
		#include <reg51.h>
		
	/*||||| 常數與巨集與 SFR bit alias |||||*/
		/* digital logic definitions */
			#define LOGIC_HIGH 1
			#define LOGIC_LOW 0

		/* Conventional C constants */
			#define TRUE 1
			#define FALSE 0

		/* 按鈕 */
			sbit switch4 = P3^3;
			sbit switch5 = P3^4;
			sbit switch6 = P3^5;
			
		/* 指撥開關(DIP) */
			sbit dip_ground = P2^5;
		
		/* 液晶螢幕(LCD) */
			sbit lcd_enable = P2^2;
				/* 啟用 LCD 訊號 */
			sbit lcd_register_select = P2^0;
				/* LCD 暫存器選擇信號 */
			sbit lcd_read_write_bar = P2^1;
					/* LCD 暫存器讀寫 */
	/*||||| Definition of data type, enumeration, data structure and class |||||*/

	/*||||| 函式雛型 | Function Prototypes |||||*/

	/*||||| 全域變數 | Global Variables |||||*/
	
	#ifdef __cplusplus
		}
	#endif
#endif /* COMMON_DEFINITIONS_H_INCLUDED */
