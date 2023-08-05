
// MFCProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCProject.h"
#include "MFCProjectDlg.h"
#include "afxdialogex.h"
#include "FillWorker.h"
#include "dataStoring.h"
#include "DelWorker.h"
#include "Menu.h"
#include "Storage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

int worker_loc1;
dataStoring save;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO4, &CAboutDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CAboutDlg::OnBnClickedRadio5)
END_MESSAGE_MAP()


// CMFCProjectDlg dialog



CMFCProjectDlg::CMFCProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
	, WorkerID(_T(""))
	, SDay(_T(""))
	, SMonth(_T(""))
	, SYear(_T(""))
	, SName(_T(""))
	, SAge (_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, WorkerID);
	DDX_Text(pDX, IDC_EDIT2, SDay);
	DDX_Text(pDX, IDC_EDIT3, SMonth);
	DDX_Text(pDX, IDC_EDIT4, SYear);
	DDX_Text(pDX, IDC_EDIT5, SName);
	DDX_Text(pDX, IDC_EDIT6, SAge);

	DDX_Control(pDX, IDC_LIST1, Listofworkers);
}

BEGIN_MESSAGE_MAP(CMFCProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCProjectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCProjectDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCProjectDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCProjectDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT5, &CMFCProjectDlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCProjectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK, &CMFCProjectDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCProjectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCProjectDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCProjectDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCProjectDlg::OnBnClickedButton6)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCProjectDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDCANCEL, &CMFCProjectDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMFCProjectDlg message handlers
CStatic* backgroundHolder;

BOOL CMFCProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}

	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	backgroundHolder = (CStatic*)GetDlgItem(IDC_background);
	CString str;
	str = CString(_T("clothing.bmp"));
	HBITMAP pic1 = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 1300, 410, LR_LOADFROMFILE);
	backgroundHolder->SetBitmap(pic1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCProjectDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	FillWorker dlg;
	dlg.DoModal();
}


void CMFCProjectDlg::OnBnClickedButton2()
{
	int i;
	UpdateData(true);
	int WorkerLoc = -1;
	for (i = 0; i < dataStoring::workerList.size(); i++)
	{
		if (dataStoring::workerList[i] == NULL) 
		{
			continue;
		}
		if (WorkerID == dataStoring::workerList[i]->getID()) 
		{
			worker_loc1 = WorkerLoc = i;
			break;
		}
	}
	if (WorkerLoc != -1)
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
		WorkerID = dataStoring::workerList[WorkerLoc]->getID();
		Listofworkers.ResetContent();
		SDay.Format(L"%d", (dataStoring::workerList[WorkerLoc]->getDateOfJoin().GetDay()));
		SMonth.Format(L"%d", (dataStoring::workerList[WorkerLoc]->getDateOfJoin().GetMonth()));
		SYear.Format(L"%d", (dataStoring::workerList[WorkerLoc]->getDateOfJoin().GetYear()));
		SName.Format(L"%s", (dataStoring::workerList[WorkerLoc]->getName()));
		SAge.Format(_T("%d"), (dataStoring::workerList[WorkerLoc]->getAge()));
		for(int i = 0; i<dataStoring::workerList.size();i++)
		{
			Listofworkers.AddString(_T("שם העובד: ") + dataStoring::workerList[i]->getName() +
				_T(".  תעודת זהות: ") + dataStoring::workerList[i]->getID());
		}
		UpdateData(false);
	}
	else
	{
		MessageBox(_T(" עובד לא נמצא במערכת"), _T("שגיאה"), MB_ICONWARNING);
		if (MessageBox(_T("האם ברצונך להוסיפו?"), _T("הוספה"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			FillWorker dlg;
			dlg.DoModal();
		}
	}
}


void CMFCProjectDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCProjectDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCProjectDlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CMFCProjectDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	DelWorker dlg;
	dlg.DoModal();
}


void CMFCProjectDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

void CMFCProjectDlg::OnBnClickedButton4() // 

{
	// TODO: Add your control notification handler code here.
	CFileDialog dlg(FALSE, _T("wrk"), _T("Untitled"), 0, _T("All Files ||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		dataStoring save;
		CFile file;
		filename = dlg.GetPathName();
		file.Open(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		save.serializing(ar);
		ar.Close();
	}
}

void CMFCProjectDlg::OnBnClickedButton5() // Load
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
	}
}

void CMFCProjectDlg::OnBnClickedButton7()
{
	Storage dlg;
	dlg.DoModal();
}


void CAboutDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
}


void CAboutDlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
}


void CMFCProjectDlg::OnBnClickedButton6()
{
	WorkerID = "";
	SName= "";
	SAge = "";
	SDay = "";
	SMonth = "";
	SYear = "";
	Listofworkers.ResetContent();
	UpdateData(false);
}


void CMFCProjectDlg::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}


void CMFCProjectDlg::OnBnClickedCancel()
{
	if (IDCANCEL)
		exit(1);
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


