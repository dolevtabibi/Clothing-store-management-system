
// MFCProjectDlg.h : header file
//

#pragma once


// CMFCProjectDlg dialog
class CMFCProjectDlg : public CDialogEx
{
// Construction
public:
	CMFCProjectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CString WorkerID;
	afx_msg void OnEnChangeEdit1();
	CString SDay;
	CString SMonth;
	afx_msg void OnEnChangeEdit2();
	CString SYear;
	CString SName;
	CString SAge;
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnLbnSelchangeList1();
	CListBox Listofworkers;
	afx_msg void OnBnClickedCancel();
};
