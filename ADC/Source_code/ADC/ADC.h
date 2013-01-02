/* ADC.h
程式名稱 | Program name
	類比→數位轉換器(ADC)控制函式庫
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	類比→數位轉換器(ADC)控制函式庫 is part of NTOU_W78E58B_libraries
	NTOU_W78E58B_libraries is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	NTOU_W78E58B_libraries is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with NTOU_W78E58B_libraries.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
#ifndef ADC_H_INCLUDED
	#define ADC_H_INCLUDED
	/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/

	/*||||| 常數與巨集 | Constants & Macros |||||*/
		
	/*||||| Definition of data type, enumeration, data structure and class |||||*/

	/*||||| 函式雛型 | Function Prototypes |||||*/
		/* 因為轉換結果輸出至恢復第3態時間很短所以直接跟 adcGetValue() 合併
		void adcDisable(void);
		void adcEnable(void); */
		void adcStartConvert(
			/* 讓 ADC 開始進行轉換的子程式
			   　ADC 於 free running 模式需要有一段 
					   chip_select_bar HIGH->LOW 
				     write_bar HIGH->LOW->HIGH
						 chip_select_bar LOW->HIGH
					 才會開始轉換 */
			void);
		unsigned char adcGetValue(
			/* 獲取 ADC 的數值 */
			void);
	/*||||| 全域變數 | Global Variables |||||*/
	
	#ifdef __cplusplus
		}
	#endif
#endif /* ADC_H_INCLUDED */
