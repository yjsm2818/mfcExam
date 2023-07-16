# Mfc imagedlg

이미지는 보통 2D행렬 형태이나 c++ 은 기본적으로 matrixArr을 flattened 하여 사용하는게 일반적 

MFC 에서도 `m_image.Create(nWidth, nHeight, nBpp);` 로 이미지를 생성하지만 2D 배열일 때처럼 image[x][y] 구문을 사용하여 이미지 데이터에 직접 액세스할 수 없습니다.

픽셀 데이터에 액세스하고 조작하려면`unsigned char* fm = (unsigned char*)m_image.GetBits();` 로서 이미지 데이터에 대한 포인터를 검색할 수 있습니다.

fm[Y * nPitch + X] 를 사용하여 위치 (X, Y)의 픽셀에 액세스할 수 있음.

또는 이미지 또는 비트맵 클래스가 `m_image.SetPixel(16, 12, 0);` 와 같은 메서드를 제공하는 경우 포인터를 참조하지 않고 픽셀을 직접 수정할 수 있습니다. 하지만 이 경우 함수 호출 오버헤드가 발생합니다.
-------------
* `Invalidate()` 메서드 : 창에 특정 변경 사항이 있을 때 자동으로 발생함.

* void* memset(void* ptr, int value, size_t num); : 메모리 초기화

* static int nSttX = 0; : 정적 변수임을 선언하는 기능으로 c++ 에서는 정적 변수는 해당 함수가 종료된 후에도 값을 기억하고 있음 

* if (m_image != NULL) {
m_image.Destroy();
}

c++에서 이미지를 로드시 해당 메모리가 비어 있는지 확인하여 메모리를 수동으로 관리해줘야 함