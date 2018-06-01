// Text.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"

				
#include <commctrl.h>				
#pragma comment(lib,"comctl32.lib")				
				

HINSTANCE hAppInstance;

VOID EnumProcess(HWND hListProcess)
{
	LV_ITEM vitem;						
							
	//��ʼ��						
	memset(&vitem,0,sizeof(LV_ITEM));						
	vitem.mask = LVIF_TEXT;						
							
	vitem.pszText = "csrss.exe";						
	vitem.iItem = 0;						
	vitem.iSubItem = 0;						
	//ListView_InsertItem(hListProcess, &vitem);						
	SendMessage(hListProcess, LVM_INSERTITEM,0,(DWORD)&vitem);						
							
	vitem.pszText = TEXT("448");						
	vitem.iItem = 0;						
	vitem.iSubItem = 1;						
	ListView_SetItem(hListProcess, &vitem);						
							
	vitem.pszText = TEXT("56590000");						
	vitem.iItem = 0;						
	vitem.iSubItem = 2;						
	ListView_SetItem(hListProcess, &vitem);						
							
	vitem.pszText = TEXT("000F0000");						
	vitem.iItem = 0;						
	vitem.iSubItem = 3;						
	ListView_SetItem(hListProcess, &vitem);						
							
	vitem.pszText = TEXT("winlogon.exe");						
	vitem.iItem = 1;						
	vitem.iSubItem = 0;						
	//ListView_InsertItem(hListProcess, &vitem);						
	SendMessage(hListProcess, LVM_INSERTITEM,0,(DWORD)&vitem);						
							
	vitem.pszText = TEXT("456");						
	vitem.iSubItem = 1;						
	ListView_SetItem(hListProcess, &vitem);						
							
	vitem.pszText = TEXT("10000000");						
	vitem.iSubItem = 2;						
	ListView_SetItem(hListProcess, &vitem);						
							
	vitem.pszText = TEXT("000045800");						
	vitem.iSubItem = 3;						
	ListView_SetItem(hListProcess, &vitem);						

}

VOID InitProcessListView(HWND hDlg)
{
	LV_COLUMN lv;								
	HWND hListProcess;								
									
	//��ʼ��								
	memset(&lv,0,sizeof(LV_COLUMN));								
	//��ȡIDC_LIST_PROCESS���								
	hListProcess = GetDlgItem(hDlg,IDC_LIST_PROSS);								
	//��������ѡ��								
	SendMessage(hListProcess,LVM_SETEXTENDEDLISTVIEWSTYLE,LVS_EX_FULLROWSELECT,LVS_EX_FULLROWSELECT);								
									
	//��һ��								
	lv.mask = LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM;								
	lv.pszText = TEXT("����");				//�б���				
	lv.cx = 150;							 	//�п�
	lv.iSubItem = 0;								
	//ListView_InsertColumn(hListProcess, 0, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,0,(DWORD)&lv);								
	//�ڶ���								
	lv.pszText = TEXT("PID");								
	lv.cx = 80;								
	lv.iSubItem = 1;								
	//ListView_InsertColumn(hListProcess, 1, &lv);								
	SendMessage(hListProcess,LVM_INSERTCOLUMN,1,(DWORD)&lv);								
	//������								
	lv.pszText = TEXT("�����ַ");								
	lv.cx = 80;								
	lv.iSubItem = 2;								
	ListView_InsertColumn(hListProcess, 2, &lv);								
	//������								
	lv.pszText = TEXT("�����С");								
	lv.cx = 80;								
	lv.iSubItem = 3;								
	ListView_InsertColumn(hListProcess, 3, &lv);
	
	EnumProcess(hListProcess);

}

BOOL CALLBACK MainDlgProc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	BOOL bRet = TRUE;

	switch(uMsg)
	{
	case WM_CLOSE:
		{
			EndDialog(hDlg,0);
			break;
		}
	case WM_INITDIALOG:
		{
			InitProcessListView(hDlg);
			break;
		}
	case WM_NOTIFY:
		{
			NMHDR* pNMHDR = (NMHDR*)lParam;

			break;
		}
	
	case WM_COMMAND:
		switch(LOWORD(wParam))
		{
		case IDC_BUTTON_PE:
			
			return TRUE;
		case IDC_BUTTON_ABOUT:
			
			return TRUE;
		case IDC_BUTTON_OUT:
			EndDialog(hDlg,0);
			return TRUE;
		
		}
		break;
	
	default:
			bRet = FALSE;
			break;
	}
	
	return bRet;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	INITCOMMONCONTROLSEX icex;				
	icex.dwSize = sizeof(INITCOMMONCONTROLSEX);				
	icex.dwICC = ICC_WIN95_CLASSES;				
	InitCommonControlsEx(&icex);				

 	// TODO: Place code here.
	hAppInstance = hInstance;
	
	DialogBox(hInstance,MAKEINTRESOURCE(IDD_DIALOG_MAIN),NULL,MainDlgProc);

	return 0;
}



