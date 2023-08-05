#pragma once


// DelWorker dialog

class DelWorker : public CDialogEx
{
	DECLARE_DYNAMIC(DelWorker)

public:
	DelWorker(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DelWorker();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString FID;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CString DelWorkerLogin;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
	CButton Identity;
	CButton iconDEL;
	HICON UploadIcon = (HICON)LoadImage(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_iconDEL), IMAGE_ICON, 25, 25, 0);
};
