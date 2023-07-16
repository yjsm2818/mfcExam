﻿// CProcess.cpp: 구현 파일
//

#include "pch.h"
#include "gPrg.h"
#include "CProcess.h"


// CProcess

CProcess::CProcess()
{
}

CProcess::~CProcess()
{
}

int CProcess::getStarInfo(CImage* pImage, int nTh)
{
	unsigned char* fm = (unsigned char*)pImage->GetBits();
	int nWidth = pImage->GetWidth();
	int nHeigth = pImage->GetHeight();
	int nPitch = pImage->GetPitch();
	int nSum = 0;
	for (int k = 0; k < nWidth * nHeigth; ++k) {
		if (fm[k] > nTh)
			++nSum;
	}
	return nSum;
}


// CProcess 멤버 함수
