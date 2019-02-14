
// SortMethodDlg.h : ͷ�ļ�
//

#pragma once
#include "SR_array.h"

// CSortMethodDlg �Ի���
class CSortMethodDlg : public CDialogEx
{
// ����
public:
	CSortMethodDlg(CWnd* pParent = NULL);	// ��׼���캯��
	virtual void OnOK();//��дOnOK����

// �Ի�������
	enum { IDD = IDD_SORTMETHOD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	SR_array arr;
	CWnd *pwnd_pic;
	CRect rec;
	double StepX;
	double StepY;
	int StartTime;
	int EndTime;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	//�Զ��庯��
	void DrawingZero(int x, int y);
	void DrawingOne(int x, int y);
	void DrawingTwo(int x, int y);
	void DrawingThree(int x, int y);
	void DrawingFour(int x, int y);
	void DrawingFive(int x, int y);
	void DrawingSix(int x, int y);
	void DrawingSeven(int x, int y);
	void DrawingEight(int x, int y);
	void DrawingNine(int x, int y);
	void DrawingX(int x, int y);
	void DrawingY(int x, int y);
	void ShowHistogram(int *array);
	void swapAB(int *arr, int a, int b);
	void QuickSort(int low, int height);
	void BubbleSort();
	void HeapSort();
	void InsertSort();
	void SelectSort();
	void MergeSort();
public:
	afx_msg void OnBnClickedBtnrand();
	afx_msg void OnEnChangeEditinput();
	afx_msg void OnEnUpdateEditinput();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedBtnquick();
	afx_msg void OnBnClickedBtnrest();
	
};
