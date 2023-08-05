#pragma once


// COpenCompany dialog

class COpenCompany : public CDialogEx, public CObject
{
	DECLARE_DYNAMIC(COpenCompany)

public:
	COpenCompany(CWnd* pParent = nullptr);   // standard constructor
	virtual ~COpenCompany();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CString NewStoreName;
	CString OwnerName;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit1();
	CString FirstID;
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedCancel();
	CSliderCtrl m_SliderCtrl;
	afx_msg void OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
