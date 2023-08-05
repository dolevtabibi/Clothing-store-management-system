// COpenCompany.cpp : implementation file
//
#include "pch.h"
#include "MFCProject.h"
#include "COpenCompany.h"
#include "afxdialogex.h"
#include "MFCProjectDlg.h"
#include "dataStoring.h"
#include "Owner.h"
#include "Shirts.h"
#include "Pants.h"
#include <mmsystem.h>
#include <Windows.h>

CStatic* Mainholder;

// COpenCompany dialog

IMPLEMENT_DYNAMIC(COpenCompany, CDialogEx)

COpenCompany::COpenCompany(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, NewStoreName(_T(""))
	, OwnerName(_T(""))
	, FirstID(_T(""))
{

}

COpenCompany::~COpenCompany()
{
}
void COpenCompany::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, NewStoreName);
	DDX_Text(pDX, IDC_EDIT2, OwnerName);
	DDX_Text(pDX, IDC_EDIT3, FirstID);
	DDX_Control(pDX, IDC_SLIDER1, m_SliderCtrl);
}

BOOL COpenCompany::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  Add extra initialization here
	/*CheckRadioButton(IDC_RADIO4, IDC_RADIO5,IDC_RADIO4);*/ //Initalize the radio buttons..
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO3); //Initalize the radio buttons..
	CheckRadioButton(IDC_RADIO4, IDC_RADIO5, IDC_RADIO4);
	PlaySound(TEXT("Music.wav"), NULL, SND_ASYNC);
	m_SliderCtrl.SetRange(0, 0xFFFF, TRUE);
	m_SliderCtrl.SetPos(0x7FFF);
	Mainholder = (CStatic*)GetDlgItem(IDC_Login);
	CString str;
	str = CString(_T("Login.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 650, 470, LR_LOADFROMFILE);
	Mainholder->SetBitmap(pic1);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
	
}

BEGIN_MESSAGE_MAP(COpenCompany, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &COpenCompany::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &COpenCompany::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &COpenCompany::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &COpenCompany::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &COpenCompany::OnEnChangeEdit3)
	ON_BN_CLICKED(IDCANCEL, &COpenCompany::OnBnClickedCancel)
	ON_WM_VSCROLL()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &COpenCompany::OnNMCustomdrawSlider1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// COpenCompany message handlers

void COpenCompany::OnBnClickedButton2()
{
	UpdateData(true);
	Products* productPtr;
	Workers* ownerPtr;
	COleDateTime dateofjoin;
	dateofjoin = COleDateTime::COleDateTime::GetCurrentTime();
	dataStoring creatingComapny;
	int NewAge = 23; // לא חשוב הגיל של הבעלים לכן נתתי מספר קבוע כלשהו.
	int SelType = 3;
	double NewSalary = 0; // רציתי מערכת לניהול יותר את העובדים ולא הבעלים.

	if (FirstID == "" || OwnerName == "" || NewStoreName == "")
		return;
	else
	{
		ownerPtr = new Owner(NewStoreName, FirstID, OwnerName, dateofjoin, NewAge, SelType, NewSalary, SelType);
		dataStoring::workerList.push_back(ownerPtr);
		productPtr = new Shirts(0, 0);
		dataStoring::productsList.push_back(productPtr);
		productPtr->updateInventory(1, 1);
		productPtr->updateInventory(2, 2);
		productPtr->updateInventory(3, 3);

		productPtr = new Pants(10, 0);
		dataStoring::productsList.push_back(productPtr);
		productPtr->updateInventory(11, 1);

		ShowWindow(SW_HIDE);
		CMFCProjectDlg dlg;
		dlg.DoModal();
		ShowWindow(SW_SHOW);
	}
}



void COpenCompany::OnBnClickedButton1()
{
	CFileDialog dlg(TRUE, _T(".wrk"), NULL, 0, _T("All Files ||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		dataStoring load;
		CFile file;
		filename = dlg.GetPathName();
		file.Open(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		load.serializing(ar);
		ar.Close();
		file.Close();
		ShowWindow(SW_HIDE);
		CMFCProjectDlg dlg;
		dlg.DoModal();
		ShowWindow(SW_SHOW);
	}
}

void COpenCompany::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void COpenCompany::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void COpenCompany::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void COpenCompany::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void COpenCompany::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}


void COpenCompany::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default

	__super::OnHScroll(nSBCode, nPos, pScrollBar);
	if (pScrollBar == (CScrollBar*)&m_SliderCtrl) {
		int value = m_SliderCtrl.GetPos();
		waveOutSetVolume(0, (value & 0x0000ffff) | (value << 16));
		UpdateData(FALSE);
	}
	else {
		CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	}
}
