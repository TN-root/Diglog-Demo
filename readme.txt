这是自己的第一个win32界面；
Windows标准控件,标准控件总是可用的:				
				
Static				
Group Box				
Button				
Check Box				
Radio Button				
Edit				
ComboBox				
ListBox				
				
				
Windows通用控件,代码包含在Comctrl32.dll				
				
使用前：				
				
#include <commctrl.h>				
#pragma comment(lib,"comctl32.lib")				
				
Animation				
ComboBoxEx 				
Date_and_Time_Picker 				
Drag_List_Box 				
Flat_Scroll_Bar 				
Header 				
HotKey 				
ImageList 				
IPAddress 				
List_View 				
Month_Calendar 				
Pager 				
Progress_Bar 				
Property_Sheets 				
Rebar 				
Status Bars 				
SysLink 				
Tab 				
Toolbar 				
ToolTip 				
Trackbar 				
TreeView 				
Up_and_Down				
				
				
特别说明：				
				
通用控件在使用前，需要通过INITCOMMONCONTROLSEX进行初始化				
				
只要在您的程序中的任意地方引用了该函数就、会使得WINDOWS的程序加载器PE Loader加载该库				
				
INITCOMMONCONTROLSEX icex;				
icex.dwSize = sizeof(INITCOMMONCONTROLSEX);				
icex.dwICC = ICC_WIN95_CLASSES;				
InitCommonControlsEx(&icex);	

WM_NOTIFY的使用：							
							
	该消息类型与WM_COMMAND类型相似，都是由子窗口向父窗口发送的消息。						
							
	WM_NOTIFY可以包含比WM_COMMAND更丰富的信息						
							
	Windows通用组件中有很多消息，都是通过WM_NOTIFY来描述的.						
							
							
WM_NOTIFY消息中的参数如下：							
							
	wParam:控件ID						
							
	lParam:指向一个结构						
							
	typedef struct tagNMHDR { 						
	        HWND hwndFrom; //发送通知消息的控制窗口句柄						
	        UINT idFrom;   //发送通知消息的控制ID值						
	        UINT code;     //通知码，如LVM_SELCHANGED						
	    } NMHDR; 						
							
							
这个结构体能满足一般的要求，但能描述的信息还是有限的							
							
解决方案：对每种不同用途的通知消息都定义另一种结构来表示							
							
	typedef struct tagNMLVCACHEHINT {						
	    NMHDR   hdr;						
	    int     iFrom;						
	    int     iTo;						
	} NMLVCACHEHINT, *PNMLVCACHEHINT;						
							
	typedef struct tagLVDISPINFO {						
	    NMHDR hdr;						
	    LVITEM item;						
	} NMLVDISPINFO, FAR *LPNMLVDISPINFO;						
							
	typedef struct _NMLVFINDITEM {						
	    NMHDR hdr;						
	    int iStart;						
	    LVFINDINFO lvfi;						
	} NMLVFINDITEM, *PNMLVFINDITEM;						
			
