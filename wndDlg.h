// wndDlg.h : header file
//

#if !defined(AFX_WNDDLG_H__2982CEA1_8A15_4732_BCF6_E3D836AE36E8__INCLUDED_)
#define AFX_WNDDLG_H__2982CEA1_8A15_4732_BCF6_E3D836AE36E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWndDlg dialog

class CWndDlg : public CDialog
{
// Construction
public:
	bool failed();
	bool Over();
	void drawline(CPoint _p1,CPoint _p2);
	bool find1(int _x1,int _y1,int _x2,int _y2);
	bool find3(CPoint _p1,CPoint _p2);
	bool find2(CPoint _p1,CPoint _p2);
	bool find1(CPoint _p1,CPoint _p2);
	bool judge();
	void clear();
	void ShowAll();
	
	void FreshMap();
	void ShowRect(CPoint pt);
	void DelPicture(CPoint _pt);
	void ShowPicture(CPoint _pt, int _bmp);
	CWndDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWndDlg)
	enum { IDD = IDD_WND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onnewgame();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CPoint m_subpoint[2];
	int m_maxnum;
	CPoint mark[2];
	int m_margin;
	int m_y;
	int m_x;
	int m_num;   //ͼƬ��Ŀ
	int map[15][15];  //ȫͼ
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WNDDLG_H__2982CEA1_8A15_4732_BCF6_E3D836AE36E8__INCLUDED_)
