
// mfcCimageDlg.h: 헤더 파일
//

#pragma once


// CmfcCimageDlg 대화 상자
class CmfcCimageDlg : public CDialogEx
{
private:
	CImage m_image;
	const int nWidth = 640;
	const int nHeight = 480;
	const int nRadius = 20;
	const int nGray = 80;

	BOOL validImgPos(const int x, const int y);
// 생성입니다.
public:
	CmfcCimageDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCIMAGE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnImage();
	afx_msg void OnBnClickedBtnSave();
	afx_msg void OnBnClickedBtnLoad();
	void UpdateDisplay();
	void moveRect();
	void drawCircle(unsigned char* fm, const int i, const int j, const int nRadius, const int nGray);
	BOOL isInCircle(const int i, const int j, const int nCenterX, const int nCenterY, const int nRadius);

	afx_msg void OnBnClickedBtnAction();
	afx_msg void OnBnClickedButRand();
};
