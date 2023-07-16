
// mfcCimageDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mfcCimage.h"
#include "mfcCimageDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CmfcCimageDlg 대화 상자



CmfcCimageDlg::CmfcCimageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCIMAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcCimageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcCimageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_IMAGE, &CmfcCimageDlg::OnBnClickedBtnImage)
	ON_BN_CLICKED(IDC_BTN_SAVE, &CmfcCimageDlg::OnBnClickedBtnSave)
	ON_BN_CLICKED(IDC_BTN_Load, &CmfcCimageDlg::OnBnClickedBtnLoad)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CmfcCimageDlg::OnBnClickedBtnAction)
	ON_BN_CLICKED(IDC_BUT_RAND, &CmfcCimageDlg::OnBnClickedButRand)
END_MESSAGE_MAP()


// CmfcCimageDlg 메시지 처리기

BOOL CmfcCimageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CmfcCimageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmfcCimageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmfcCimageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcCimageDlg::OnBnClickedBtnImage()
{
	const int nBpp = 8;

	if (m_image != NULL) {
		m_image.Destroy();
	}

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; ++i) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}
		m_image.SetColorTable(0, 256, rgb);
	}
	const int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth*nHeight);

	//for (int j = 0; j < nHeight; ++j) {
	//	for (int i = 0; i < nWidth; ++i) {
	//		fm[j * nPitch + i] = (i%0xff);
	//	}
	//}

	//fm[12 * nPitch + 16] = 0;
	//fm[0 * nPitch + 0] = 128;
	//fm[0 * nPitch + 1] = 128;
	//fm[1 * nPitch + 1] = 128;

	UpdateDisplay();

}


void CmfcCimageDlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}

void CmfcCimageDlg::moveRect()
{
	static int nSttX = 0;
	static int nSttY = 0;

	const int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	//memset(fm, 0xff, nWidth * nHeight);
	drawCircle(fm, nSttX, nSttY, nRadius, 0xff);//전체초기화를 하지 않고 원만 배경과 같은 색으로 다시 칠함 
	drawCircle(fm, ++nSttX, ++nSttY, nRadius, nGray);

	UpdateDisplay();
}

BOOL CmfcCimageDlg::validImgPos(const int x, const int y)
{

	CRect rect(0, 0, nWidth, nHeight);

	return rect.PtInRect(CPoint(x, y));
}

void CmfcCimageDlg::drawCircle(unsigned char* fm, const int x, const int y, const int nRadius, const int nGray)
{
	const int nCenterX = x + nRadius;
	const int nCenterY = y + nRadius;
	const int nPitch = m_image.GetPitch();

	for (int j = y; j < y + nRadius * 2; ++j) {
		for (int i = x; i < x + nRadius * 2; ++i) {
			if (isInCircle(i, j, nCenterX, nCenterY, nRadius))
				fm[j * nPitch + i] = nGray;
		}
	}
}

BOOL CmfcCimageDlg::isInCircle(const int x, const int y, const int nCenterX, const int nCenterY, const int nRadius)
{
	const double dX = x - nCenterX;
	const double dY = y - nCenterY;
	const double dDist = dX * dX + dY * dY;

	return dDist < nRadius * nRadius;
}


CString g_strFileImate = _T("../save.bmp");
void CmfcCimageDlg::OnBnClickedBtnSave()
{
	m_image.Save(g_strFileImate);
}


void CmfcCimageDlg::OnBnClickedBtnLoad()
{
	if (m_image != NULL) {
		m_image.Destroy();
	}
	m_image.Load(g_strFileImate);

	UpdateDisplay();
}

void CmfcCimageDlg::OnBnClickedBtnAction()
{
	for (int i = 0; i < 300; ++i) {
		moveRect();
		Sleep(10);
	}
}

#include <random>
void CmfcCimageDlg::OnBnClickedButRand()
{
	static int nRandX = 0;
	static int nRandY = 0;
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	drawCircle(fm, nRandX, nRandY, nRadius, 0xff);

	nRandX = rand() % (nWidth - nRadius * 2);
	nRandY = rand() % (nHeight - nRadius * 2);
	drawCircle(fm, nRandX, nRandY, nRadius, nGray);

	UpdateDisplay();
}
