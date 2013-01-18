/* Flow_of_control.h
程式名稱 | Program name
	Flow_of_control library
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	Flow_of_control library is part of NTOUCS Winbond_W78E58B Libraries
	NTOUCS Winbond_W78E58B Libraries is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	NTOUCS Winbond_W78E58B Libraries is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with NTOUCS Winbond_W78E58B Libraries.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
#ifndef FLOW_OF_CONTROL_H_INCLUDED
	#define FLOW_OF_CONTROL_H_INCLUDED
	/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/
		/* Delay procedures */
			#include "Delay.h"
			
		/* Hang procedures */
			#include "Hang.h"
			
	/*||||| 常數與巨集 | Constants & Macros |||||*/

	/*||||| Definition of data type, enumeration, data structure and class |||||*/

	/*||||| 函式雛型 | Function Prototypes |||||*/

	/*||||| 全域變數 | Global Variables |||||*/
	
	#ifdef __cplusplus
		}
	#endif
#endif
