#pragma once


// Storage dialog

class Storage : public CDialogEx , public CObject
{
	DECLARE_DYNAMIC(Storage)

public:
	Storage(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Storage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Storage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio4();
	int Amount;
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio8();
	int SelShirt;
	int SelPant;
	afx_msg void OnBnClickedRadio9();
	afx_msg void OnBnClickedRadio10();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio6();
	int SelProd;
	afx_msg void OnEnChangeEdit1();
	CListBox ListofStorage;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
