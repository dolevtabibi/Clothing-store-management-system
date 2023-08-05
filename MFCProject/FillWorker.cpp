// FillWorker.cpp : implementation file
//

#include "pch.h"
#include "MFCProject.h"
#include "FillWorker.h"
#include "afxdialogex.h"
#include "Workers.h"
#include "dataStoring.h"
#include "Managers.h"
#include "GlobalEmployee.h"
#include "PerHour.h"
#include "Owner.h"

// FillWorker dialog

IMPLEMENT_DYNAMIC(FillWorker, CDialogEx)

CStatic* Workerholder;
int workerLoc;

FillWorker::FillWorker(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, NewName(_T(""))
	, NewID(_T(""))
	, NewAge(0)
	, NewDateOfJoin(COleDateTime::GetCurrentTime())
	, SelType(0)
	, NewSalary(0)

	, NewUsername(_T(""))
	, NewPassword(_T(""))
	, NewBonus(0)
	, AddWorkerLogin(_T(""))
{

}

FillWorker::~FillWorker()
{
}

void FillWorker::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, NewName);
	DDX_Text(pDX, IDC_EDIT2, NewID);
	DDX_Text(pDX, IDC_EDIT3, NewAge);
	DDX_MonthCalCtrl(pDX, IDC_MONTHCALENDAR1, NewDateOfJoin);
	DDX_Radio(pDX, IDC_RADIO1, SelType);
	DDX_Text(pDX, IDC_EDIT4, NewSalary);
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT7)->EnableWindow(FALSE);
	GetDlgItem(IDC_MONTHCALENDAR1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);




	DDX_Text(pDX, IDC_EDIT5, NewUsername);
	DDX_Text(pDX, IDC_EDIT6, NewPassword);
	DDX_Text(pDX, IDC_EDIT7, NewBonus);
	DDX_Text(pDX, IDC_EDIT10, AddWorkerLogin);
}


BEGIN_MESSAGE_MAP(FillWorker, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &FillWorker::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &FillWorker::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &FillWorker::OnEnChangeEdit2)
	ON_NOTIFY(MCN_SELCHANGE, IDC_MONTHCALENDAR1, &FillWorker::OnMcnSelchangeMonthcalendar1)
	ON_BN_CLICKED(IDOK, &FillWorker::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO1, &FillWorker::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &FillWorker::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &FillWorker::OnBnClickedRadio3)
	ON_EN_CHANGE(IDC_EDIT4, &FillWorker::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON2, &FillWorker::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &FillWorker::OnBnClickedCancel)

	ON_STN_CLICKED(IDC_WORKER, &FillWorker::OnStnClickedWorker)
END_MESSAGE_MAP()

BOOL FillWorker::OnInitDialog()
{

	CDialogEx::OnInitDialog();
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO3); //Initalize the radio buttons..
	CheckRadioButton(IDC_RADIO4, IDC_RADIO5, IDC_RADIO4);
	Workerholder = (CStatic*)GetDlgItem(IDC_WORKER);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
// FillWorker message handlers


void FillWorker::OnBnClickedButton1() // ON click "הוספה"
{
	int insert = 0;
	UpdateData(true);
	switch (SelType)
	{
	case 0:
		if (NewID == "" || NewName == "" || NewAge == 0)
		{
			MessageBox(_T("Missing information, Worker not created."));
			UpdateWindow();
			Invalidate();
			insert = 1;
		}
		break;
	case 1:
		if (NewID == "" || NewName == "" || NewAge == 0 || NewUsername == "" || NewPassword == "")
		{
			MessageBox(_T("Missing information, Worker not created."));
			UpdateWindow();
			Invalidate();
			insert = 1;
		}
		break;
	case 2:
		if (NewID == "" || NewName == "" || NewAge == 0 || NewBonus == 0 || NewSalary == 0)
		{
			MessageBox(_T("Missing information, Worker not created."));
			UpdateWindow();
			Invalidate();
			insert = 1;
		}
		break;
	}
	if (insert == 1)
		return;
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	if (SelType == 0) //If he click "הוספה" without "choose radio button"
		NewSalary = 5000;
	if (SelType == 1)
		NewSalary = 10000;

	for (int i = 0; i < dataStoring::workerList.size(); i++)
	{
		if (dataStoring::workerList[i]->getID() == NewID)
		{
			MessageBox(L"עובד כבר קיים במערכת", L"שגיאה");
			GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
			return;
		}
	}
	int loc = -1;
	for (int i = 0; i < dataStoring::workerList.size(); i++)
	{
		if (dataStoring::workerList[i]->getID() == NewID) {
			workerLoc = loc = i;
			NewName = dataStoring::workerList[i]->getName();
			NewID = dataStoring::workerList[i]->getID();
			NewAge = dataStoring::workerList[i]->getAge();
			SelType = dataStoring::workerList[i]->getType();
			NewSalary = dataStoring::workerList[i]->getSalary();
			UpdateData(false);
			UpdateWindow();
			Invalidate();
			break;
		}
	}
	if (loc == -1) {
		workerLoc = loc = dataStoring::workerList.size();
		Workers* newWorker = 0;
		if (SelType == 0) newWorker = new GlobalEmployee(NewID, NewName, NewDateOfJoin, NewAge, SelType, NewSalary, SelType);
		else if (SelType == 1) newWorker = new Managers(NewID, NewName, NewDateOfJoin, NewAge, SelType, NewSalary, NewUsername, NewPassword, SelType);
		else if (SelType == 2) newWorker = new PerHour(NewID, NewName, NewDateOfJoin, NewAge, SelType, NewSalary, NewBonus);
		dataStoring::workerList.push_back(newWorker);
		(MessageBox(L"עובד נוסף למערכת"));
		GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
		return;

	}
	GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
		
}
		/*CDialogEx::OnOK();*/


void FillWorker::OnEnChangeEdit1()
{

	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void FillWorker::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void FillWorker::OnMcnSelchangeMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMSELCHANGE pSelChange = reinterpret_cast<LPNMSELCHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void FillWorker::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	/*CDialogEx::OnOK();*/

}


void FillWorker::OnBnClickedRadio1()
{

	CString str;
	str = CString(_T("globalemployee.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
	Workerholder->SetBitmap(pic1);
	UpdateData(true);
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_MONTHCALENDAR1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	SelType = 0; // עובד גלובלי
	NewSalary = 5000;
}


void FillWorker::OnBnClickedRadio2()
{
	CString str;
	str = CString(_T("manager.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
	Workerholder->SetBitmap(pic1);
	UpdateData(true);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	SelType = 1; //מנהל
	NewSalary = 10000;
	GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT6)->EnableWindow(TRUE);
	GetDlgItem(IDC_MONTHCALENDAR1)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
	if (NewID == "" || NewName == "" || NewAge == 0)
		return;
	else
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	
}


void FillWorker::OnBnClickedRadio3()
{
	CString str;
	str = CString(_T("perhour.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
	Workerholder->SetBitmap(pic1);
	UpdateData(true);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT4)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
	GetDlgItem(IDC_MONTHCALENDAR1)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT7)->EnableWindow(TRUE);
	SelType = 2; //עובד לפי שעה
}

void FillWorker::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}




void FillWorker::OnBnClickedButton2() //הזדהות במערכת
{
	bool id = true;
	UpdateData(true);
	for (int i = 0; i < dataStoring::workerList.size(); i++)
	{
		if (AddWorkerLogin == dataStoring::workerList[i]->getID())
		{
			if (dataStoring::workerList[i]->getType() == 3 || dataStoring::workerList[i]->getType() == 1)
			{
				GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
				GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
				GetDlgItem(IDC_EDIT3)->EnableWindow(TRUE);
				GetDlgItem(IDC_EDIT4)->EnableWindow(FALSE);
				GetDlgItem(IDC_EDIT10)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_MONTHCALENDAR1)->EnableWindow(TRUE);
				GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
				GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
				GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
				MessageBox(_T("יש הרשאה"));
				return;
			}
			else
			{
				id = false;
				break;
			}
		}
	}
	if (id == false)
	{
		MessageBox(_T("אין לך מספיק הרשאות"));
		return;
	}
	else
	{
		MessageBox(_T("לא נמצא עובד"));
		return;
	}
}



void FillWorker::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void FillWorker::OnStnClickedWorker()
{
	// TODO: Add your control notification handler code here
}
