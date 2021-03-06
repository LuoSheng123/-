
// LatitudeAndLongitudeDlg.h: 头文件
//

#pragma once

#include "bmplib.h"
#include "correctlib.h"
#include "afxwin.h"

// CLatitudeAndLongitudeDlg 对话框
class CLatitudeAndLongitudeDlg : public CDialog
{
// 构造
public:
	CLatitudeAndLongitudeDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LATITUDEANDLONGITUDE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLoad();
	void DisPlay();
	void ShowImage(int options, bool clear);
	// 画出param的辅助点、线
	void DrawParam();
	void ShowView();
	void BarInit();

	// 源图像
	ClImage *mImg;
	// 矫正图像
	ClImage *cImg;
	//有效图像参数
	CorrectParam param;
	CString msg;
	//焦距
	double f;

	bool isLoad;
	bool isCorrect;
	bool showParam;
	
	afx_msg void OnBnClickedCheckparam();
	CScrollBar m_bar_x;
	CScrollBar m_bar_y;
	CScrollBar m_bar_r;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar m_bar_f;
	afx_msg void OnBnClickedCheckcorrect();
	void Correct();
	CScrollBar m_bar_fx;
	CScrollBar m_bar_fy;
	CScrollBar m_bar_k1;
	CScrollBar m_bar_k2;
	CScrollBar m_bar_p1;
	CScrollBar m_bar_p2;
};
