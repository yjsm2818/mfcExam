// CDlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "gPrg.h"
#include "afxdialogex.h"
#include "CDlgImage.h"


// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CDlgImage, pParent)
{
	m_pParent = pParent;
} 

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_UP_PARENT, &CDlgImage::OnBnClickedBtnUpParent)
END_MESSAGE_MAP()



#include"gPrgDlg.h"
void CDlgImage::OnBnClickedBtnUpParent()
{
	static int n = 100;
	CgPrgDlg* pDlg = (CgPrgDlg*)m_pParent;
	pDlg->callFunc(++n);
}
