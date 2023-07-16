# Mfc bitmap

메시지->WM_EraseBkgnd : 창에 새로운 내용이 그려지기 전에 배경을 깨끗하게 만듦
재정의 하는 이유 : Default 함수는 배경을 단색으로 채우는 과정이 들어가있어 깜빡임이 발생할 수 있으나 bitmap 사용시 특정 부분만 업로드하면 되기때문에 재정의 해서 사용함

`
void CMFCBitmapBtnDlg::initButtons() 
{
	CRect rect;
	GetDlgItem(IDC_BTN_ON_OFF)->GetWindowRect(&rect);//버튼의 정보를 가져옴 
	//GetDlgItem(IDC_BTN_ON_OFF)->GetClientRect(&rect); //Cveiw 기준으로 좌표적용

	m_pBtnOnOff = new CBitmapButton;
	m_pBtnOnOff->Create(NULL, WS_CHILD | WS_VISIBLE | BS_OWNERDRAW, rect, this, IDC_BTN_ON_OFF);
	m_pBtnOnOff->LoadBitmaps(IDB_ON, IDB_OFF);
	m_pBtnOnOff->SizeToContent(); //콘텐츠에 정확히 맞도록 버튼의 크기를 조정
}
`