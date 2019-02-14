
// SortMethodDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SortMethod.h"
#include "SortMethodDlg.h"
#include "afxdialogex.h"
#include <Windows.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSortMethodDlg �Ի���



CSortMethodDlg::CSortMethodDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSortMethodDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSortMethodDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSortMethodDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BtnRand, &CSortMethodDlg::OnBnClickedBtnrand)
	ON_EN_CHANGE(IDC_EDITINPUT, &CSortMethodDlg::OnEnChangeEditinput)
	ON_EN_UPDATE(IDC_EDITINPUT, &CSortMethodDlg::OnEnUpdateEditinput)
	ON_BN_CLICKED(IDC_START, &CSortMethodDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_BTNQUICK, &CSortMethodDlg::OnBnClickedBtnquick)
	ON_BN_CLICKED(IDC_BTNREST, &CSortMethodDlg::OnBnClickedBtnrest)
END_MESSAGE_MAP()


// CSortMethodDlg ��Ϣ�������

BOOL CSortMethodDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MINIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	this->pwnd_pic = GetDlgItem(IDC_PIC);
	pwnd_pic->GetClientRect(&rec);
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	SetDlgItemText(IDC_EDITARRSTEP, _T("1"));
	SetDlgItemText(IDC_EDITARRLENGTH, _T("100"));


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CSortMethodDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSortMethodDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

	
		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	/*
	//����ֱ������ϵ
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc1(pwnd_pic);

	int height = rec.Height();
	int width = rec.Width();
	CPoint PointX;
	CPoint PointY;
	PointY.x = 30;
	PointY.y = 30;

	PointX.x = width - 30;
	PointX.y = height - 30;

	
	dc1.SelectObject(&pen);

	dc1.MoveTo(PointY);
	dc1.LineTo(PointY.x,PointX.y);
	dc1.LineTo(PointX);

	dc1.MoveTo(PointY);
	dc1.LineTo(PointY.x - 5,PointY.y + 5);
	dc1.MoveTo(PointY);
	dc1.LineTo(PointY.x + 5,PointY.y + 5);

	dc1.MoveTo(PointX);
	dc1.LineTo(PointX.x - 5, PointX.y - 5);
	dc1.MoveTo(PointX);
	dc1.LineTo(PointX.x - 5, PointX.y + 5);

	DrawingY(PointY.x - 10,PointY.y);
	DrawingX(PointX.x, PointX.y + 10);

	DrawingZero(PointY.x - 5, PointX.y + 5);
	*/
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSortMethodDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSortMethodDlg::OnBnClickedBtnrand()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	arr.rand_arr();
	CString value;
	for (int i = 0; i < arr.length; i++)
	{
		
		CString v;
		v.Format(_T("%d"), arr.array[i]);
		value += v;
		if (i < arr.length - 1)
		{
			value += ",";
		}

	}
	SetDlgItemText(IDC_EDITRAND, value);
	ShowHistogram(arr.array_copy);

}


void CSortMethodDlg::OnEnChangeEditinput()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString value;
	GetDlgItem(IDC_EDITINPUT)->GetWindowText(value);//��ȡ����������ַ�����value
	SetDlgItemText(IDC_EDITRAND, value);

}

//��������
void CSortMethodDlg::OnEnUpdateEditinput()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// �������Խ� EM_SETEVENTMASK ��Ϣ���͵��ÿؼ���
	// ͬʱ�� ENM_UPDATE ��־�������㵽 lParam �����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString value;
	GetDlgItem(IDC_EDITINPUT)->GetWindowText(value);//��ȡ����������ַ�����value
	arr.Input_arr(value);
	value.Format(_T("%d"), arr.length);
	SetDlgItemText(IDC_EDITLENGTH, value);
	ShowHistogram(arr.array_copy);
}

//��дOnOK������ֹ�س��˳�
void CSortMethodDlg::OnOK()
{

}

void CSortMethodDlg::OnBnClickedStart()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	/*������
	CClientDC dc(pwnd_pic);
	CBrush brush(RGB(0,0,0));
	dc.SelectObject(&brush);
	dc.Rectangle(0, 0, 100, 100);
	*/
	int type = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO10);
	if (arr.length != 0)
	{	
		ShowHistogram(arr.array_copy);
		switch (type)
		{
			case IDC_RADIO1:QuickSort(0, arr.length - 1); break;
			case IDC_RADIO2:BubbleSort(); break;
			case IDC_RADIO3:HeapSort(); break;
			case IDC_RADIO4:InsertSort(); break;
			case IDC_RADIO5:SelectSort(); break;
			case IDC_RADIO6:MergeSort(); break;
			case IDC_RADIO7:
			case IDC_RADIO8:
			case IDC_RADIO9:
			case IDC_RADIO10:
			default:
				break;
		}
	}

}

//��λ
void CSortMethodDlg::OnBnClickedBtnrest()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	arr.arr_copy();
	ShowHistogram(arr.array_copy);
}

void CSortMethodDlg::DrawingZero(int x,int y)
{
	CPoint p(x, y);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc(pwnd_pic);
	dc.SelectObject(&pen);
	dc.MoveTo(p);
	dc.LineTo(p.x + 5, p.y);
	dc.LineTo(p.x + 5, p.y + 11);
	dc.LineTo(p.x + 0, p.y + 11);
	dc.LineTo(p);
}
void CSortMethodDlg::DrawingOne(int x, int y)
{
	CPoint p(x, y);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc(pwnd_pic);
	dc.SelectObject(&pen);
	dc.MoveTo(p);
	dc.LineTo(p.x, p.y + 11);
}
void CSortMethodDlg::DrawingTwo(int x, int y)
{
	CPoint p(x, y);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc(pwnd_pic);
	dc.SelectObject(&pen);
	dc.MoveTo(p);
	dc.LineTo(p.x + 5, p.y + 0);
	dc.LineTo(p.x + 5, p.y + 5);
	dc.LineTo(p.x + 0, p.y + 5);
	dc.LineTo(p.x + 0, p.y + 11);
	dc.LineTo(p.x + 5, p.y + 11);
}
void CSortMethodDlg::DrawingThree(int x, int y)
{
	CPoint p(x, y);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc(pwnd_pic);
	dc.SelectObject(&pen);
	dc.MoveTo(p);
	dc.LineTo(p.x + 5, p.y + 0);
	dc.LineTo(p.x + 5, p.y + 5);
	dc.LineTo(p.x + 0, p.y + 5);
	dc.MoveTo(p.x + 5, p.y + 5);
	dc.LineTo(p.x + 5, p.y + 11);
	dc.LineTo(p.x + 0, p.y + 11);

}
void CSortMethodDlg::DrawingFour(int x, int y)
{
	CPoint p(x, y);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc(pwnd_pic);
	dc.SelectObject(&pen);
	dc.MoveTo(p);
	dc.LineTo(p.x + 0, p.y + 5);
	dc.LineTo(p.x + 5, p.y + 5);
	dc.MoveTo(p.x + 5, p.y + 0);
	dc.LineTo(p.x + 5, p.y + 11);
}
void CSortMethodDlg::DrawingFive(int x, int y)
{
	CPoint p(x, y);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc(pwnd_pic);
	dc.SelectObject(&pen);
	dc.MoveTo(p.x + 5, p.y + 0);
	dc.LineTo(p.x + 0, p.y + 0);
	dc.LineTo(p.x + 0, p.y + 5);
	dc.LineTo(p.x + 5, p.y + 5);
	dc.LineTo(p.x + 5, p.y + 11);
	dc.LineTo(p.x + 0, p.y + 11);
}
void CSortMethodDlg::DrawingSix(int x, int y)
{
	CPoint p(x, y);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc(pwnd_pic);
	dc.SelectObject(&pen);
	dc.MoveTo(p.x + 5, p.y + 0);
	dc.LineTo(p.x + 0, p.y + 0);
	dc.LineTo(p.x + 0, p.y + 11);
	dc.LineTo(p.x + 5, p.y + 11);
	dc.LineTo(p.x + 5, p.y + 5);
	dc.LineTo(p.x + 0, p.y + 5);
}
void CSortMethodDlg::DrawingSeven(int x, int y)
{
	CPoint p(x, y);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc(pwnd_pic);
	dc.SelectObject(&pen);
	dc.MoveTo(p);
	dc.LineTo(p.x + 5, p.y + 0);
	dc.LineTo(p.x + 5, p.y + 11);
}
void CSortMethodDlg::DrawingEight(int x, int y)
{
	CPoint p(x, y);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc(pwnd_pic);
	dc.SelectObject(&pen);
	dc.MoveTo(p);
	dc.LineTo(p.x + 0, p.y + 11);
	dc.LineTo(p.x + 5, p.y + 11);
	dc.LineTo(p.x + 5, p.y + 0);
	dc.LineTo(p.x + 0, p.y + 0);
	dc.MoveTo(p.x + 5, p.y + 5);
	dc.LineTo(p.x + 0, p.y + 5);
}
void CSortMethodDlg::DrawingNine(int x, int y)
{
	CPoint p(x, y);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc(pwnd_pic);
	dc.SelectObject(&pen);
	dc.MoveTo(p.x + 0, p.y + 11);
	dc.LineTo(p.x + 5, p.y + 11);
	dc.LineTo(p.x + 5, p.y + 0);
	dc.LineTo(p.x + 0, p.y + 0);
	dc.LineTo(p.x + 0, p.y + 5);
	dc.LineTo(p.x + 5, p.y + 5);
}
void CSortMethodDlg::DrawingX(int x, int y)
{
	CPoint p(x, y);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc(pwnd_pic);
	dc.SelectObject(&pen);
	dc.MoveTo(p.x - 3, p.y - 5);
	dc.LineTo(p.x + 3, p.y + 5);
	dc.MoveTo(p.x - 3, p.y + 5);
	dc.LineTo(p.x + 3, p.y - 5);
}
void CSortMethodDlg::DrawingY(int x, int y)
{
	CPoint p(x, y);
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CClientDC dc(pwnd_pic);
	dc.SelectObject(&pen);
	dc.MoveTo(p.x - 3, p.y - 5);
	dc.LineTo(p.x + 0, p.y + 0);
	dc.LineTo(p.x + 3, p.y - 5);
	dc.MoveTo(p.x - 0, p.y - 0);
	dc.LineTo(p.x + 0, p.y + 5);

}
//���������±�AB����a:�±�A,b:�±�B
void CSortMethodDlg::swapAB(int *arr, int a, int b)
{
	int c = arr[a];
	arr[a] = arr[b];
	arr[b] = c;
}
//ˢ����ʾ��״ͼ
void CSortMethodDlg::ShowHistogram(int *array)
{
	int height = rec.Height();
	int width = rec.Width();
	this->StepX = width / arr.length;
	this->StepY = (height - 25) / arr.max;

	CClientDC dc(pwnd_pic);
	CBrush brush(RGB(0, 0, 0));
	CBrush brushbg(RGB(255, 255, 255));
	CPen pen(PS_SOLID, 2, RGB(0, 0, 0));
	CPen penbg(PS_SOLID, 1, RGB(255, 255, 255));
	dc.SelectObject(&brushbg);
	dc.Rectangle(0, 0, width, height);
	//dc.SelectObject(&brush);
	dc.SelectObject(&pen);
	dc.MoveTo(0, height - 25);
	dc.LineTo(width, height - 25);
	
	for (int i = 0; i < arr.length; i++)
	{
		int x0 = (i)*StepX;
		int y0 = height - 25 - array[i] * StepY;
		int x1 = (i + 1) * StepX;
		int y1 = height - 25;
		dc.SelectObject(&brush);
		dc.Rectangle(x0+1, y0, x1-1, y1);
	}
	Sleep(10);
	/*
	CString v;
	v.Format(_T("%lf"), StepY);
	SetDlgItemText(IDC_EDITLENGTH, v);
	*/
}

//������������
void CSortMethodDlg::OnBnClickedBtnquick()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int step;
	int length;
	CString get_step;
	CString get_length;
	GetDlgItem(IDC_EDITARRSTEP)->GetWindowText(get_step);
	GetDlgItem(IDC_EDITARRLENGTH)->GetWindowText(get_length);
	step = _ttoi(get_step);
	length = _ttoi(get_length);
	CString value;
	for (int i = 1; i < length; i = i + step)
	{
		CString v;
		v.Format(_T("%d"), i);
		v += ",";
		value += v;
	}
	CString v;
	v.Format(_T("%d"), length);
	value += v;

	arr.Input_arr(value);
	SetDlgItemText(IDC_EDITINPUT, value);
	value.Format(_T("%d"), arr.length);
	SetDlgItemText(IDC_EDITLENGTH, value);
	ShowHistogram(arr.array_copy);
}

//****************����************************************//
void CSortMethodDlg::QuickSort(int low, int height)
{
	if (low <= height)
	{
		int first = low;
		int last = height;
		int key = arr.array_copy[low];
		while (first < last)
		{

			while (first < last && arr.array_copy[last] >= key)
			{
				last--;
			}
			arr.array_copy[first] = arr.array_copy[last];
			ShowHistogram(arr.array_copy);
			while (first < last && arr.array_copy[first] <= key)
			{
				first++;
			}
			arr.array_copy[last] = arr.array_copy[first];
			ShowHistogram(arr.array_copy);
		}
		arr.array_copy[first] = key;
		ShowHistogram(arr.array_copy);
		QuickSort(low, first - 1);
		QuickSort(first + 1, height);
	}
}

//**************ð����************************************//
void CSortMethodDlg::BubbleSort()
{
	int length = arr.length;
	int temp;
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (arr.array_copy[j] > arr.array_copy[j + 1])
			{
				temp = arr.array_copy[j + 1];
				arr.array_copy[j + 1] = arr.array_copy[j];
				arr.array_copy[j] = temp;
				ShowHistogram(arr.array_copy);
			}
		}
	}
}

//***************������***********************************//
void CSortMethodDlg::HeapSort()
{
	int length = arr.length;
	while (length > 0)
	{
		for (int i = length-1; i >= 0; i--)
		{
			if (i % 2 == 0)
			{
				if (arr.array_copy[i] > arr.array_copy[(i - 2) / 2])
				{
					swapAB(arr.array_copy, i, (i - 2) / 2);
					ShowHistogram(arr.array_copy);
				}
			}
			else
			{	
				if (arr.array_copy[i] > arr.array_copy[(i - 1) / 2])
				{
					swapAB(arr.array_copy, i, (i - 1) / 2);
					ShowHistogram(arr.array_copy);
				}
			}
		}
		swapAB(arr.array_copy, 0, length-1);
		ShowHistogram(arr.array_copy);
		length--;
	}
}

//*************��������************************************//
void CSortMethodDlg::InsertSort()
{
	int temp;
	int i, j;
	for (i = 1; i < arr.length; i++)
	{
		temp = arr.array_copy[i];
		for (j = i; j >0 && arr.array_copy[j-1] > temp ; j--)
		{
			arr.array_copy[j] = arr.array_copy[j - 1];
			ShowHistogram(arr.array_copy);
		}
		arr.array_copy[j] = temp;
		ShowHistogram(arr.array_copy);
	}
}

//***************ѡ������***********************************//
void CSortMethodDlg::SelectSort()
{
	for (int i = 0; i < arr.length; i++)
	{
		for (int j = i; j < arr.length; j++)
		{
			if (arr.array_copy[i]>arr.array_copy[j])
			{
				swapAB(arr.array_copy, i, j);
				ShowHistogram(arr.array_copy);
			}
		}
	}
}

//****************�鲢����********************************//
void CSortMethodDlg::MergeSort()
{


















}