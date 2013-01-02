/* DIP_switch
程式名稱 | Program name
	DIP 開關控制函式庫
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	DIP 開關控制函式庫 is part of 海洋大學資訊工程學系 家庭網路設備設計與控制 W78E58B 開發版函式庫
	海洋大學資訊工程學系 家庭網路設備設計與控制 W78E58B 開發版函式庫 is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	海洋大學資訊工程學系 家庭網路設備設計與控制 W78E58B 開發版函式庫 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with 海洋大學資訊工程學系 家庭網路設備設計與控制 W78E58B 開發版函式庫.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
#ifndef DIP_SWITCH_H_INCLUDED
	#define DIP_SWITCH_H_INCLUDED
	/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/

	/*||||| 常數與巨集 | Constants & Macros |||||*/

	/*||||| Definition of data type, enumeration, data structure and class |||||*/

	/*||||| 函式雛型 | Function Prototypes |||||*/
		void dip_swEnable(
			/* 啟用 DIP 封裝開關對匯流排的輸出 */
			void);
		void dip_swDisable(
			/* 停用 DIP 封裝開關對匯流排的輸出 */
			void);
		unsigned char dip_swGetValue(
			/* 取得 DIP 封裝開關的數值 */);
	/*||||| 全域變數 | Global Variables |||||*/
	
	#ifdef __cplusplus
		}
	#endif
#endif /* DIP_SWITCH_H_INCLUDED */
