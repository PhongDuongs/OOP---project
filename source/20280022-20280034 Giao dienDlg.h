
// 20280022-20280034 Giao dienDlg.h : header file
//

#pragma once
#include "TrungTo.h"

// CMy2028002220280034GiaodienDlg dialog
class CMy2028002220280034GiaodienDlg : public CDialogEx
{
// Construction
public:
	CMy2028002220280034GiaodienDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY2028002220280034_GIAO_DIEN_DIALOG };
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
	CStatic picture_control;
public:
	afx_msg void OnBnClickedCancel();
	TrungTo infix;
	float Tong;
	CStatic RE;/*Biến kết quả(Button Giải)*/
	CString input;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

