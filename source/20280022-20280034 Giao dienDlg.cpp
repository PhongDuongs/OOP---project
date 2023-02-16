
// 20280022-20280034 Giao dienDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "20280022-20280034 Giao dien.h"
#include "20280022-20280034 Giao dienDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

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
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy2028002220280034GiaodienDlg dialog



CMy2028002220280034GiaodienDlg::CMy2028002220280034GiaodienDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MY2028002220280034_GIAO_DIEN_DIALOG, pParent)
	, input(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy2028002220280034GiaodienDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, input);
	DDX_Control(pDX, IDC_re, RE);

	DDX_Control(pDX, IDC_PICTURE_CONTROL, picture_control);
}

BEGIN_MESSAGE_MAP(CMy2028002220280034GiaodienDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMy2028002220280034GiaodienDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy2028002220280034GiaodienDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy2028002220280034GiaodienDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMy2028002220280034GiaodienDlg message handlers

BOOL CMy2028002220280034GiaodienDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy2028002220280034GiaodienDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy2028002220280034GiaodienDlg::OnPaint()
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
HCURSOR CMy2028002220280034GiaodienDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy2028002220280034GiaodienDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CMy2028002220280034GiaodienDlg::OnBnClickedButton1()/*Button 1 (Giải) dùng để solve bài toán*/
{
	// TODO: Add your control notification handler code here
	CString Input;/*MFC khởi tạo với biến Cstring*/
	TrungTo infix;
	GetDlgItemText(IDC_EDIT1, Input);
	input = Input;
	std::string STDStr(CW2A(input.GetString(), CP_UTF8));/*Do hàm TrungTo sử dụng std::string nên phải dùng câu lệnh này để chuyển từ CString sang std::String*/
	Tong = infix.Xuat(STDStr);

	CString text;
	text.Format(L"%f", Tong);
	RE.SetWindowText(text);



}


void CMy2028002220280034GiaodienDlg::OnBnClickedButton2()/*Button 2 (Click) khi bấm sẽ hiện thị ra hình ảnh đuôi jpg trong source*/
{
	// TODO: Add your control notification handler code here
	CStatic* picturebox = (CStatic*)(GetDlgItem(IDC_PICTURE_CONTROL));
	CRect rect;
	picturebox->GetClientRect(rect);
	CClientDC dc(picturebox);
	CImage image;
	image.Load(L"infix.jpg");
	CBitmap m_bitmap;
	m_bitmap.Attach(image.Detach());
	CDC memoryDC;
	memoryDC.CreateCompatibleDC(&dc);
	memoryDC.SelectObject(m_bitmap);
	BITMAP bmp;
	m_bitmap.GetBitmap(&bmp);
	dc.SetStretchBltMode(COLORONCOLOR);
	dc.StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memoryDC, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);
}
