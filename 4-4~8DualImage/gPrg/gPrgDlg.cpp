﻿
// gPrgDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "gPrg.h"
#include "gPrgDlg.h"
#include "afxdialogex.h"

#include<iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
using namespace std;

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
public:
	
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CgPrgDlg 대화 상자



CgPrgDlg::CgPrgDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GPRG_DIALOG, pParent)
	, nRadius(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgPrgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NRADIUS, nRadius);
}

BEGIN_MESSAGE_MAP(CgPrgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_TEST, &CgPrgDlg::OnBnClickedBtnTest)
	ON_BN_CLICKED(IDC_BTN_PROCESS, &CgPrgDlg::OnBnClickedBtnProcess)
	ON_BN_CLICKED(IDC_BTN_MAKE_PATTERN, &CgPrgDlg::OnBnClickedBtnMakePattern)
	ON_BN_CLICKED(IDC_BTN_GET_DATA, &CgPrgDlg::OnBnClickedBtnGetData)
	ON_BN_CLICKED(IDC_BTN_GET_CIRCLE, &CgPrgDlg::OnBnClickedBtnGetCircle)
END_MESSAGE_MAP()


// CgPrgDlg 메시지 처리기

BOOL CgPrgDlg::OnInitDialog()
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
	MoveWindow(0, 0, 1280, 800);
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_CDlgImage, this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(0, 0, 640, 480);

	m_pDlgImgResult = new CDlgImage;
	m_pDlgImgResult->Create(IDD_CDlgImage, this);
	m_pDlgImgResult->ShowWindow(SW_SHOW);
	m_pDlgImgResult->MoveWindow(640, 0, 640, 480);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CgPrgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CgPrgDlg::OnPaint()
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
HCURSOR CgPrgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CgPrgDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if(m_pDlgImage)		delete m_pDlgImage;
	if(m_pDlgImgResult) delete m_pDlgImgResult;
}

void CgPrgDlg::callFunc(int n)
{
	//int nData = n;
	cout << n << endl;
} 


void CgPrgDlg::OnBnClickedBtnTest()
{
	unsigned char* fm = (unsigned char*) m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	memset(fm, 0, nWidth * nHeight);
	
	resetImgResult();
	
	int x, y;
	for (int k = 0; k < MAX_POINT; ++k) {
		x = rand() % nWidth;
		y = rand() % nHeight;
		fm[y * nPitch + x] = rand()%0xff;
	}
	int nindex = 0;
	int nTh = 100;
	
	for (int j = 0; j < nHeight; ++j) {
		for (int i = 0; i < nWidth; ++i) {
			if (fm[j * nPitch + i] > nTh) {
				//m_pDlgImgResult[m_pDlgImgResult->m_nDataCount].m_ptData;
				if (m_pDlgImgResult->m_nDataCount < MAX_POINT) {
					m_pDlgImgResult->m_ptData[nindex].x = i;
					m_pDlgImgResult->m_ptData[nindex].y = j;
					m_pDlgImgResult->m_nDataCount = ++nindex;
					//cout << nindex << ":" << i << "," << j << endl;
				}
			}
		}
	}

	m_pDlgImage->Invalidate();
	m_pDlgImgResult->Invalidate();
}


void CgPrgDlg::resetImgResult() 
{
	int nWidth = m_pDlgImgResult->m_image.GetWidth();
	int nHeight = m_pDlgImgResult->m_image.GetHeight();
	unsigned char* fm = (unsigned char*)m_pDlgImgResult->m_image.GetBits();
	memset(fm, 0xff, nWidth * nHeight);
	m_pDlgImgResult->m_nDataCount = 0;

	for (int i = 0; i < MAX_POINT; ++i){
		m_pDlgImgResult->m_ptData[i] = CPoint(0, 0);
	}
}

#include "CProcess.h"
#include<chrono>
void CgPrgDlg::OnBnClickedBtnProcess()
{
	CProcess process;

	auto start = std::chrono::system_clock::now();
	int nRet = process.getStarInfo(&m_pDlgImage->m_image, 100);
	auto end = std::chrono::system_clock::now();
	auto millisec = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	cout << nRet << "\t" << millisec.count() << "ms" << endl;
}


void CgPrgDlg::OnBnClickedBtnMakePattern()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	memset(fm, 0, nWidth * nHeight);

	CRect rect(100, 200, 150, 400);
	for (int j = rect.top; j < rect.bottom; ++j){
		for (int i = rect.left; i < rect.right; ++i) {
			fm[j * nPitch + i] = rand()%0xff;
		}
	}
	m_pDlgImage->Invalidate();
}


void CgPrgDlg::OnBnClickedBtnGetData()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	int nTh = 0xff;
	CRect rect(0, 0, nWidth, nHeight);
	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;
	for (int j = rect.top; j < rect.bottom; ++j) {
		for (int i = rect.left; i < rect.right; ++i) {
			if (fm[j * nPitch + i] != nTh){
				nSumX += i;
				nSumY += j;
				++nCount;
			}
		}
	}
	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;

	cout << dCenterX << "\t" << dCenterY << endl;
}

// #H.W code
void CgPrgDlg::OnBnClickedBtnGetCircle()
{
	UpdateData(TRUE);
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();

	int nRandX = rand() % (nWidth - 2 * nRadius);
	int nRandY = rand() % (nHeight - 2 * nRadius);

	centerOfGravity(fm, nRandX, nRandY, nRadius);

	
	CClientDC dc(this);
	if (m_pDlgImage->m_image)
		m_pDlgImage->m_image.Draw(dc, 0, 0);
	int nCenterX = nRandX + nRadius;
	int nCenterY = nRandY + nRadius;
	drawLine(&dc, nCenterX, nCenterY, nRadius);
}

void CgPrgDlg::centerOfGravity(unsigned char* fm,int x,int y, int nRadius, int scale)
{	
	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;

	for (int j = y; j < y + nRadius * 2; ++j) {
		for (int i = x; i < x + nRadius * 2; ++i) {
			if (isInCircle(i, j, x + nRadius, y + nRadius, nRadius)) {
				nSumX += i;
				nSumY += j;
				++nCount;
			}
		}
	}
	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;

	cout << dCenterX << "\t" << dCenterY << endl;
}

BOOL CgPrgDlg::isInCircle(int x, int y, int nCenterX, int nCenterY, int nRadius)
{
	const double dX = x - nCenterX;
	const double dY = y - nCenterY;
	const double dDist = dX * dX + dY * dY;

	return dDist < nRadius * nRadius;
}


void CgPrgDlg::drawLine(CDC* pDC, int nCenterX, int centerY, int nRadius)
{
	CRect rect(nCenterX - nRadius, centerY - nRadius, nCenterX + nRadius, centerY + nRadius);
	CPen pen;
	pen.CreatePen(PS_SOLID, 2, COLOR_YELLOW);
	CPen* pOldPen = pDC->SelectObject(&pen);
	
	pDC->Ellipse(rect);

	pDC->MoveTo(nCenterX - nRadius, centerY);
	pDC->LineTo(nCenterX + nRadius, centerY);
	pDC->MoveTo(nCenterX, centerY - nRadius);
	pDC->LineTo(nCenterX, centerY + nRadius);

	pDC->SelectObject(pOldPen);
}




