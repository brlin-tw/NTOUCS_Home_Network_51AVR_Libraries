/* Delay.h
程式名稱 | Program name
	延遲時間函式庫
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	「程式名稱 | Program name」 is part of 「軟體名稱 | Software name」
	「軟體名稱 | Software name」 is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	「軟體名稱 | Software name」 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with 「軟體名稱 | Software name」.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個header檔案被include第二次 */
#ifndef DELAY_H_INCLUDED
	#define DELAY_H_INCLUDED
	/* 如果是C++編譯器則停用C++特有的函式名稱mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所include之函式庫的標頭檔 | Included Library Headers |||||*/

	/*||||| 常數與巨集 | Constants & Macros |||||*/

	/*||||| Definition of data type, enumeration, data structure and class |||||*/

	/*||||| 函式雛型 | Function Prototypes |||||*/
	/* 單純的倒數產生時間延遲的函式
	   　time
		 　　延遲時距（單位：while 迴圈一次運行的時間）
	*/
	void delay(unsigned int time);
	
	void delayDoing(
		/* 延遲並於該時段中執行特定功能 */
		unsigned int time, 
		void (*doing)(unsigned int param1), 
		unsigned int param1);
		
	void delaySecond(
		/* 延遲（單位：秒） */
		bit timer, 
			/* 用來計時的 timer */
		unsigned int time
			/* 延遲時距 */);

	void delaySecondDoing(
		/* 延遲（單位：秒）並於該時段中執行特定功能 */
		bit timer, 
			/* 用來計時的 timer */
		unsigned int time
			/* 延遲時距 */, 
		void (*doing)(unsigned int param1), 
		unsigned int param1);
			
	/*||||| 全域變數 | Global Variables |||||*/
	
	#ifdef __cplusplus
		}
	#endif
#endif /* DELAY_H_INCLUDED */
