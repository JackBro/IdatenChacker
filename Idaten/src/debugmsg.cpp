#include"debugmsg.h"

///// �����̕\���֐� /////////////////////////////////////////////////////
int Str_Put(HDC hdc, int x, int y, int font_size, UINT color, TCHAR *str)
{
	HFONT hfont, oldfont;

	hfont = CreateFont(
		font_size,					// �t�H���g�̍���
		0,							// ������������̊p�x
		0,							// �x�[�X���C���̊p�x
		0,							// �t�H���g�̑���
		FW_DONTCARE,				// ���ϕ�����
		FALSE, //or TRUE			// �Α̂ɂ��邩�ǂ���
		FALSE,						// ������t���邩�ǂ���
		FALSE,						// ����������t���邩�ǂ���
		SHIFTJIS_CHARSET,			// �����Z�b�g�̎��ʎq
		OUT_DEFAULT_PRECIS,			// �o�͐��x
		CLIP_DEFAULT_PRECIS,		// �N���b�s���O���x
		DEFAULT_QUALITY,			// �o�͕i��
		DEFAULT_PITCH | FF_DONTCARE,// �s�b�`�ƃt�@�~��
		//			TEXT("�l�r ����")			// �t�H���g��
		TEXT("HG�n�p�p�߯�ߑ�")
		);

	if (hfont == NULL)
	{
		MessageBox(NULL, TEXT("�t�H���g���s"), TEXT("Error"), MB_OK);
		return 0;
	}

	SetBkMode(hdc, TRANSPARENT);			//�w�i�̓���
	SetTextColor(hdc, color);				//�F�w��
	oldfont = (HFONT)SelectObject(hdc, hfont);//�t�H���g�w��

	//�\�� (2�o�C�g�����g�p�̂��� char �� TCHAR �ɕύX)
	TextOut(hdc, x, y, (LPCWSTR)str, lstrlen(str));

	SelectObject(hdc, oldfont);				//�t�H���g�w��߂�
	DeleteObject(hfont);

	return 0;
}
