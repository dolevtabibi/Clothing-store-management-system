#pragma once

// FillWorker dialog

class FillWorker : public CDialogEx , public CObject
{
	DECLARE_DYNAMIC(FillWorker)

public:
	FillWorker(CWnd* pParent = nullptr);   // standard constructor
	virtual ~FillWorker();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	// Input name to add
	CString NewName;
	afx_msg void OnEnChangeEdit1();
	// Add new ID
	CString NewID;
	int NewAge;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnMcnSelchangeMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult);
	// join date to add
	COleDateTime NewDateOfJoin;
	afx_msg void OnBnClickedOk();
	int SelType;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	virtual BOOL OnInitDialog();
	double NewSalary;
	afx_msg void OnEnChangeEdit4();
	CString NewUsername;
	CString NewPassword;
	double NewBonus;
	afx_msg void OnBnClickedButton2();
	CString AddWorkerLogin;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnStnClickedWorker();
};
