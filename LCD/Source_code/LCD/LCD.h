/* LCD.h
程式名稱 | Program name
	液晶螢幕控制函式庫
更新紀錄 | Changelog
	Changelog is now stored on GitHub(http://www.github.com)
已知問題 | Known issues
	Known issues is now stored on GitHub(http://www.github.com)
待辦事項 | Todos
	Todo is now stored on GitHub(http://www.github.com)
著作權宣告 | Copyright declaration
	Copyright 2012 林博仁(Henry Lin, pika1021@gmail.com)
智慧財產授權條款：
	液晶螢幕控制函式庫 is part of 海洋大學資訊工程學系 家庭網路設備設計與控制課程 8051 開發版函式庫
	海洋大學資訊工程學系 家庭網路設備設計與控制課程 8051 開發版函式庫 is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	
	海洋大學資訊工程學系 家庭網路設備設計與控制課程 8051 開發版函式庫 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
	
	You should have received a copy of the GNU Lesser General Public License along with 海洋大學資訊工程學系 家庭網路設備設計與控制課程 8051 開發版函式庫.  If not, see <http://www.gnu.org/licenses/>.
*/
/* include guard：避免同一個 header 檔案被 include 第二次 */
#ifndef LCD_H_INCLUDED
	#define LCD_H_INCLUDED
	/* 如果是 C++ 編譯器則停用 C++ 特有的函式名稱 mangling*/
	#ifdef __cplusplus
		extern "C"{
	#endif

	/*||||| Forward declarations |||||*/

	/*||||| 程式所 include 之函式庫的標頭檔 | Included Library Headers |||||*/

	/*||||| 常數與巨集 | Constants & Macros |||||*/
		/* 設定指令 */
			#define LCD_INST_CLEAR 0x01
			#define LCD_INST_OFF 0x08
			#define LCD_INST_POSITION_RESET 0x02
			#define LCD_INST_POSITION_ROW1 0x80
			#define LCD_INST_POSITION_ROW2 0xc0
			
			/* 組合式 */
				#define LCD_INST_PRT_MODE 0x04
				#define LCD_INST_PRT_CUR_INCRE 0x02
				#define LCD_INST_PRT_SCR_SHIFT 0x01
				
				#define LCD_INST_PRT_SWITCH 0x08
				#define LCD_INST_PRT_DISPLAY_ON 0x04
				#define LCD_INST_PRT_CURSOR_ON 0x02
				#define LCD_INST_PRT_BLINK_ON 0x01
			
				#define LCD_INST_PRT_CTRL 0x10
				#define LCD_INST_PRT_SCR_CSR_BAR 0x08
				#define LCD_INST_PRT_RGT_LFT_BAR 0x04
				
				#define LCD_INST_PRT_PHYSICAL 0x20
				#define LCD_INST_PRT_BIT8_4BAR 0x10
				#define LCD_INST_PRT_5_10_5_7BAR 0x08
				#define LCD_INST_PRT_LINE_2_1BAR 0x04
		
		/* for lcdMove*() */
			#define LCD_DIR_RIGHT 0
			#define LCD_DIR_LEFT 1
			
	/*||||| Definition of data type, enumeration, data structure and class |||||*/
		
	/*||||| 函式雛型 | Function Prototypes |||||*/
		void lcdWaitIdle(
			/* 等待 LCD 控制器離開忙碌狀態 */
			void);
			
		void lcdExecInstruction(
			/* 寫入指令至 lcd 指令暫存器中並執行之 */
			unsigned char instruction);
			
		void lcdWriteData(
			/* 寫入資料至 lcd 資料暫存器中 */
			unsigned char datum);
			
		void lcdOn(
			/* 開啟螢幕 */
			bit cursur, 
			bit blink);

		void lcdOff(
			/* 關閉螢幕 */
			void);
		
		void lcdClear(
			/* 清除螢幕內容 */
			void);
			
		void lcdSetPositionCursur(
			/* 設定游標位址 */
			unsigned position
				/* 位址 */);
		
		void lcdMoveCursur(
			/* 移動游標子程式
			   　依照提供的方向與距離移動游標，移動後方向將設定為預設的
				 　LCD_DIR_RIGHT */
			bit direction
				/* 移動方向(LCD_DIR_*) */, 
			unsigned char length
				/* 移動距離 */);
				
		void lcdPrintDecimal16bit(
			unsigned int content
		);
		
		void lcdPrintDecimal8bit(
			unsigned char content
		);
		
		void lcdPrintChar(
			/* 印出字元子程式 */
			unsigned char character
		);

		void lcdPrintString(
			/* 印出字串子程式 */
			const unsigned char string[]
		);
		
	/*||||| 全域變數 | Global Variables |||||*/
	
	#ifdef __cplusplus
		}
	#endif
#endif
