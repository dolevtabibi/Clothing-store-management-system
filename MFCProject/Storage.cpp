// Storage.cpp : implementation file
//

#include "pch.h"
#include "MFCProject.h"
#include "Storage.h"
#include "afxdialogex.h"
#include "dataStoring.h"
#include "Shirts.h"
#include "Pants.h"

// Storage dialog

IMPLEMENT_DYNAMIC(Storage, CDialogEx)

Storage::Storage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Storage, pParent)
	, Amount(0)
	, SelShirt(0)
	, SelPant(0)
	, SelProd(0)
{

}

Storage::~Storage()
{
}

void Storage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Amount);
	DDX_Radio(pDX, IDC_RADIO3, SelShirt);
	DDX_Radio(pDX, IDC_RADIO9, SelPant);
	DDX_Radio(pDX, IDC_RADIO4, SelProd);
	GetDlgItem(IDC_RADIO9)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO10)->EnableWindow(FALSE);
	DDX_Control(pDX, IDC_LIST1, ListofStorage);
}


BEGIN_MESSAGE_MAP(Storage, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Storage::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO4, &Storage::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &Storage::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO9, &Storage::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_RADIO10, &Storage::OnBnClickedRadio10)
	ON_BN_CLICKED(IDC_RADIO3, &Storage::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO1, &Storage::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &Storage::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO6, &Storage::OnBnClickedRadio6)
	ON_EN_CHANGE(IDC_EDIT1, &Storage::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &Storage::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Storage::OnBnClickedButton3)
END_MESSAGE_MAP()


int ProductLoc;
CStatic* Productholder;

// Storage message handlers
BOOL Storage::OnInitDialog()
{

	CDialogEx::OnInitDialog();
	// TODO:  Add extra initialization here
	/*CheckRadioButton(IDC_RADIO4, IDC_RADIO5,IDC_RADIO4);*/ //Initalize the radio buttons..
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2,IDC_RADIO3); //Initalize the radio buttons..
	CheckRadioButton(IDC_RADIO4, IDC_RADIO5, IDC_RADIO4);
	Productholder = (CStatic*)GetDlgItem(IDC_PRODUCT);
	CString str;
	str = CString(_T("jerseys.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 282, 231, LR_LOADFROMFILE);
	Productholder->SetBitmap(pic1);



	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void Storage::OnBnClickedButton1()
{
	Products* productPtr;
	UpdateData(true);
	switch (SelProd)
	{
	case 0: // חולצה

		dataStoring::productsList[0]->updateInventory(Amount, SelShirt);
		MessageBox(_T("מוצר נוסף בהצלחה"));
		break;

	case 1: // מכנס
		dataStoring::productsList[1]->updateInventory(Amount, SelPant);
		MessageBox(_T("מוצר נוסף בהצלחה"));
		break;
	}
	GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO6)->EnableWindow(FALSE);
	ListofStorage.ResetContent();
	CString str;
	int num = dataStoring::productsList[0]->getAmount(0);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("גופיות: ") + str);

	num = dataStoring::productsList[0]->getAmount(1);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("חולצת ויי: ") + str);

	num = dataStoring::productsList[0]->getAmount(2);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("פולו: ") + str);

	num = dataStoring::productsList[0]->getAmount(3);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("מחויטת: ") + str);

	num = dataStoring::productsList[1]->getAmount(0);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("מכנס קצר ") + str);

	num = dataStoring::productsList[1]->getAmount(1);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("מכנס ארוך: ") + str);
}

	



	/*CDialogEx::OnOK();*/




void Storage::OnBnClickedRadio4() // חולצות
{
	GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO6)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO9)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO10)->EnableWindow(FALSE);
	SelProd = 0;
	CString str;
	str = CString(_T("jerseys.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 282, 231, LR_LOADFROMFILE);
	Productholder->SetBitmap(pic1);
	UpdateData(FALSE);
}


void Storage::OnBnClickedRadio5() // מכנסים
{
	GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO6)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO9)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO10)->EnableWindow(TRUE);
	SelProd = 1;
	CString str;
	str = CString(_T("short.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 282, 231, LR_LOADFROMFILE);
	Productholder->SetBitmap(pic1);
}


void Storage::OnBnClickedRadio8()
{
	
}


void Storage::OnBnClickedRadio9() // מכנס קצר
{
	CString str;
	str = CString(_T("short.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 282, 231, LR_LOADFROMFILE);
	Productholder->SetBitmap(pic1);
	SelPant = 0;
}


void Storage::OnBnClickedRadio10() // מכנס ארוך
{
	CString str;
	str = CString(_T("long.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 282, 231, LR_LOADFROMFILE);
	Productholder->SetBitmap(pic1);
	SelPant = 1;
}


void Storage::OnBnClickedRadio3() // גופיות
{
	CString str;
	str = CString(_T("jerseys.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 282, 231, LR_LOADFROMFILE);
	Productholder->SetBitmap(pic1);
	SelShirt = 0;
}


void Storage::OnBnClickedRadio1() // חולצת V
{
	CString str;
	str = CString(_T("vshirt.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 282, 231, LR_LOADFROMFILE);
	Productholder->SetBitmap(pic1);
	SelShirt = 1;
}


void Storage::OnBnClickedRadio2() // פולו
{
	CString str;
	str = CString(_T("polo.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 282, 231, LR_LOADFROMFILE);
	Productholder->SetBitmap(pic1);
	SelShirt = 2;
}


void Storage::OnBnClickedRadio6() // מחוייטת 
{
	CString str;
	str = CString(_T("tailored.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 282, 231, LR_LOADFROMFILE);
	Productholder->SetBitmap(pic1);
	SelShirt = 3;
}




void Storage::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the __super::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void Storage::OnBnClickedButton2()
{
	ListofStorage.ResetContent();
	CString str;
	int num = dataStoring::productsList[0]->getAmount(0);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("גופיות: ") + str);

	num = dataStoring::productsList[0]->getAmount(1);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("חולצת ויי: ") + str);

	num = dataStoring::productsList[0]->getAmount(2);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("פולו: ") + str);

	num = dataStoring::productsList[0]->getAmount(3);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("מחויטת: ") + str);

	num = dataStoring::productsList[1]->getAmount(0);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("מכנס קצר ") + str);

	num = dataStoring::productsList[1]->getAmount(1);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("מכנס ארוך: ") + str);
}


void Storage::OnBnClickedButton3()
{
	int flag = 1, size = 0;
	size = dataStoring::productsList.size();
	UpdateData(true);
	for (int i = 0; i < size; i++)
	{
		flag = 1;
		switch (SelProd)
		{
		case 0: // חולצה
			if (dataStoring::productsList[i]->getAmount(SelShirt) >= Amount)
			{
				dataStoring::productsList[i]->updateInventory((-1 * Amount), SelShirt);
				flag = 0;
				MessageBox(L" מוצר הוסר מהמלאי בהצלחה", L" עבר בהצלחה");
				break;
			}
			if (dataStoring::productsList[i]->getAmount(SelShirt) == 0)
				flag = 1; // אין מוצר במלאי
			else
				flag = 2;
			break;

		case 1: // מכנס
			if (dataStoring::productsList[i]->getAmount(SelPant) >= Amount)
			{
				dataStoring::productsList[i]->updateInventory((-1 * Amount), SelPant);
				flag = 0;
				MessageBox(L" מוצר הוסר מהמלאי בהצלחה", L" עבר בהצלחה");
				break;
			}
			break;
		}
		break;
	}

	ListofStorage.ResetContent();
	CString str;
	int num = dataStoring::productsList[0]->getAmount(0);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("גופיות: ") + str);

	num = dataStoring::productsList[0]->getAmount(1);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("חולצת ויי: ") + str);

	num = dataStoring::productsList[0]->getAmount(2);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("פולו: ") + str);

	num = dataStoring::productsList[0]->getAmount(3);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("מחויטת: ") + str);

	num = dataStoring::productsList[1]->getAmount(0);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("מכנס קצר ") + str);

	num = dataStoring::productsList[1]->getAmount(1);
	str.Format(_T("%d"), num);
	ListofStorage.AddString(_T("מכנס ארוך: ") + str);

	if (flag == 1)
		MessageBox(L" לא נמצא במלאי", L" תקלה", MB_ICONWARNING);
	else if (flag == 2)
	{
		MessageBox(L" עברת את המכסה", L" תקלה", MB_ICONWARNING);
	}
	return;
}
