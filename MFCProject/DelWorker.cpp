// DelWorker.cpp : implementation file
//

#include "pch.h"
#include "MFCProject.h"
#include "DelWorker.h"
#include "afxdialogex.h"
#include "dataStoring.h"


// DelWorker dialog

IMPLEMENT_DYNAMIC(DelWorker, CDialogEx)

CStatic* Identityholder;

DelWorker::DelWorker(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, FID(_T(""))
	, DelWorkerLogin(_T(""))
{

}

DelWorker::~DelWorker()
{
}

void DelWorker::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, FID);
	DDX_Text(pDX, IDC_EDIT2, DelWorkerLogin);
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	DDX_Control(pDX, IDC_BUTTON1, iconDEL);
}

BOOL DelWorker::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  Add extra initialization here
	/*CheckRadioButton(IDC_RADIO4, IDC_RADIO5,IDC_RADIO4);*/ //Initalize the radio buttons..
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO3); //Initalize the radio buttons..
	CheckRadioButton(IDC_RADIO4, IDC_RADIO5, IDC_RADIO4);
	iconDEL.SetButtonStyle(BS_ICON | WS_VISIBLE | WS_CHILD| WM_CTLCOLORBTN, 1);
	iconDEL.SetIcon(UploadIcon);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE

}




BEGIN_MESSAGE_MAP(DelWorker, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DelWorker::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DelWorker::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &DelWorker::OnBnClickedCancel)
END_MESSAGE_MAP()


// DelWorker message handlers


void DelWorker::OnBnClickedButton1()
{
	DelWorker dlgAbout;
	UpdateData(true);
	int loc = -1;
	for (int i = 0; i < dataStoring::workerList.size(); i++)
	{
		if (dataStoring::workerList[i] != NULL)
		{

			if (FID == dataStoring::workerList[i]->getID() && dataStoring::workerList[i]->getType() == 3)
			{
				MessageBox(L"אין אפשרות להסיר את הבעלים");
				GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
				return;
			}
			else if (FID == dataStoring::workerList[i]->getID())
			{ //std::vector<Workers*>::iterator
				auto it = dataStoring::workerList.begin() + i;
				dataStoring::workerList.erase(it);
				loc = 0;
				MessageBox(L"עובד נמחק במערכת", L"עבר בהצלחה");
				break;
			}
		}
	}
	if (loc == -1)
		MessageBox(L"עובד לא נמצא במערכת", L"שגיאה", MB_ICONEXCLAMATION);
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE); 
	
}


void DelWorker::OnBnClickedButton2() // הזדהות במערכת
{
	UpdateData(true);
	for (int i = 0; i < dataStoring::workerList.size(); i++)
	{
		if (DelWorkerLogin == dataStoring::workerList[i]->getID())
		{
			if (dataStoring::workerList[i]->getType() == 3 || dataStoring::workerList[i]->getType() == 1)
			{
				GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
				GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				MessageBox(_T("יש הרשאה"));
				return;
			}
		}
		else
			MessageBox(_T("אין לך מספיק הרשאות"));
	}
}


void DelWorker::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
