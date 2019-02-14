
// SortMethodDlg.h : 头文件
//

#pragma once
#include "SR_array.h"

// CSortMethodDlg 对话框
class CSortMethodDlg : public CDialogEx
{
// 构造
public:
	CSortMethodDlg(CWnd* pParent = NULL);	// 标准构造函数
	virtual void OnOK();//重写OnOK函数

// 对话框数据
	enum { IDD = IDD_SORTMETHOD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	SR_array arr;
	CWnd *pwnd_pic;
	CRect rec;
	double StepX;
	double StepY;
	int StartTime;
	int EndTime;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	//自定义函数
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
