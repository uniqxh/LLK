// wndDlg.cpp : implementation file
//

#include "stdafx.h"
#include "wnd.h"
#include "wndDlg.h"
#include <vector>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
using namespace std;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWndDlg dialog

CWndDlg::CWndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWndDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWndDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWndDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWndDlg, CDialog)
	//{{AFX_MSG_MAP(CWndDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_new_game, Onnewgame)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWndDlg message handlers

BOOL CWndDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//m_iml.Create( 80, 80, ILC_COLOR24 | ILC_MASK, 0, 1 );
	//CBitmap bmpBlack, bmpWhite, bb, ww;
    //bmpBlack.LoadBitmap( IDB_BITMAP2 );
    //m_iml.Add( &bmpBlack, 0xff00ff );
	//设置对话框大小
	CWnd::SetWindowPos(NULL,0,0,890,695,SWP_NOZORDER|SWP_NOMOVE);
	
	m_maxnum = 43;
	m_num = 13;
	m_x = 10;
	m_y = 7;
	m_margin = 40; //边距

	clear();


	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWndDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWndDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWndDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWndDlg::ShowPicture(CPoint _pt, int _bmp)
{
	CDC *dc = GetDC();
	CDC *mdc=new CDC;
	mdc->CreateCompatibleDC(dc);

	CString str;
	str.Format(".\\bin\\%d.bmp",_bmp);
	CBitmap bitmap;
	HBITMAP hbmp=(HBITMAP)::LoadImage(AfxGetInstanceHandle(),str,IMAGE_BITMAP,80,80,LR_CREATEDIBSECTION|LR_LOADFROMFILE);
	bitmap.Attach(hbmp);
	mdc->SelectObject( bitmap);
	dc->BitBlt( _pt.x, _pt.y, 80, 80, mdc, 0, 0,SRCCOPY);

	bitmap.DeleteObject();
	ReleaseDC(mdc);
	ReleaseDC(dc);
}

void CWndDlg::DelPicture(CPoint _pt)
{
	CDC *dc = GetDC();
	_pt.x--;
	_pt.y--;
	dc->BitBlt( _pt.x*80+m_margin, _pt.y*80+m_margin, 80, 80, dc, 0, 0, PATCOPY ); //SRCCOPY   WHITENESS
	ReleaseDC(dc);
}

void CWndDlg::ShowRect(CPoint pt)
{
	CClientDC dc(this);
	CPen pen;
	pen.CreatePen(PS_SOLID, 3, RGB(255,0,0));
	dc.SelectObject(&pen);
	dc.SetROP2( R2_NOTXORPEN );
	pt.x--;
	pt.y--;
	dc.Rectangle( pt.x*80+m_margin+1, pt.y*80+m_margin+1, pt.x*80+80+m_margin-1, pt.y*80+80+m_margin-1 );
}

void CWndDlg::Onnewgame() 
{
	// TODO: Add your command handler code here
	FreshMap();
	CString str;
	MessageBox("第 1 关");
	ShowAll();
}

void CWndDlg::FreshMap()
{
	int i,j;
	for(i=0;i<=m_x+1;i++)
		for(j=0;j<=m_y+1;j++) map[i][j] = -1;
	time_t t;
	srand((unsigned) time(&t));

	for(i=1;i<=m_x;i++)
		for(j=1;j<=m_y;j++)
		{
			if( map[i][j]>=0 ) continue ;
			int t = rand()%m_num;
			map[i][j] = t;

			while(1)
			{
				int x = rand()%m_x + 1;
				int y = rand()%m_y + 1;
				if( map[x][y] < 0 )
				{
					map[x][y] = t;
					break;
				}
			}
		}

}

void CWndDlg::ShowAll()
{
	int i,j;
	CPoint pt;
	for(i=1;i<=m_x;i++)
		for(j=1;j<=m_y;j++)
		{
			pt.x = (i-1)*80 + m_margin;
			pt.y = (j-1)*80 + m_margin;
			ShowPicture( pt, map[i][j] );
		}
}

void CWndDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CPoint pt;
	if(point.x - m_margin < 0 || point.y -m_margin < 0) return ;
	pt.x = (point.x - m_margin)/80 + 1;
	pt.y = (point.y - m_margin)/80 + 1;

	if( pt.x >m_x || pt.y >m_y) return ;

	if( map[pt.x][pt.y] < 0 )
	{
		MessageBeep(0);
		return ;
	}
	ShowRect( pt );
	//还没有按下
	if( mark[0].x <= 0 || mark[0].y <= 0 ) 
	{
		mark[0] = pt;
	}//已经按下一个
	else if( mark[0] == pt )
	{
		clear();
	}
	else
	{
		mark[1] = pt;
		if( map[mark[0].x][mark[0].y] == map[mark[1].x][mark[1].y] && judge() )
		{
			ShowRect( mark[0] );
			DelPicture( mark[0] );
			ShowRect( pt );
			DelPicture( pt );
			map[mark[0].x][mark[0].y] = -1;
			map[mark[1].x][mark[1].y] = -1;
			clear();
			if( Over() )
			{
				m_num += 2;
				CString str;
				str.Format("**^_^**恭喜你，过关啦！，是否继续第 %d 关？", (m_num - 13)/2+1);
				if( m_num > m_maxnum )
				{
					MessageBox("真棒，你通关啦！");
					return ;
				}
				else if( IDYES == MessageBox(str, "过关", MB_ICONQUESTION |MB_YESNO) )
				{
					FreshMap();
					ShowAll();
				}
			}
			else if( !failed() )
			{
				if( IDYES == MessageBox("很遗憾，闯关失败！，是否重新开始？","失败", MB_ICONQUESTION |MB_YESNO) )
				{
					Onnewgame();
				}
			}
		}
		else 
		{
			ShowRect( mark[0] );
			mark[0] = mark[1];	
		}
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CWndDlg::clear()
{
	mark[0].x = -1;
	mark[0].y = -1;
	mark[1].x = -1;
	mark[1].y = -1;
}

bool CWndDlg::judge()
{
	if( find1( mark[0], mark[1] )) 
	{
		drawline( mark[0], mark[1] );
		Sleep( 100 );
		drawline( mark[0], mark[1] );
		return 1;
	}
	if( find2( mark[0], mark[1] ) ) 
	{
		drawline( mark[0] , m_subpoint[0] );
		drawline( m_subpoint[0], mark[1] );
		Sleep( 100 );
		drawline( mark[0], m_subpoint[0] );
		drawline( m_subpoint[0], mark[1] );
		return 1;
	}
	if( find3( mark[0], mark[1] ) )
	{
		drawline( mark[0], m_subpoint[0] );
		drawline( m_subpoint[0], m_subpoint[1] );
		drawline( m_subpoint[1], mark[1] );
		Sleep( 100 );
		drawline( mark[0], m_subpoint[0] );
		drawline( m_subpoint[0], m_subpoint[1] );
		drawline( m_subpoint[1], mark[1] );
		return 1;
	}
	return 0;
}
//一条直线
bool CWndDlg::find1(CPoint _p1,CPoint _p2)
{
	int i;
	//-
	if( _p1.x == _p2.x )
	{
		int x = _p1.x;
		int y1 = _p1.y;
		int y2 = _p2.y;
		if( y1 > y2 ) swap( y1, y2 );
		for( i = y1+1; i < y2; i++ )
			if( map[x][i] >= 0 ) return 0;
		return 1;
	}
	if( _p1.y == _p2.y )
	{
		int x1 = _p1.x;
		int x2 = _p2.x;
		int y = _p1.y;
		if( x1 > x2 ) swap( x1, x2 );
		for( i = x1+1; i < x2; i++ )
			if( map[i][y] >= 0 ) return 0;
		return 1;
	}
	return 0;
}
//有一个角
bool CWndDlg::find2(CPoint _p1,CPoint _p2)
{
	CPoint p1 = _p1, t1, t2;
	CPoint p2 = _p2;
	if( p1.x == p2.x || p1.y == p2.y ) return 0;
	int i;
	if( p1.x > p2.x ) swap( p1, p2 );
	t1.x = p1.x;
	t1.y = p2.y;
	t2.x = p2.x;
	t2.y = p1.y;
	//"\"
	bool flag1,flag2;
	if( p1.y < p2.y )
	{
		flag1 = flag2 = 0;
		//左下角
		for( i = p1.y+1; i < t1.y; i++ )
			if( map[t1.x][i] >= 0 )
			{
				flag1 = 1;
				break;
			}
		if( !flag1 )
		for( i = t1.x; i < p2.x; i++ )
			if( map[i][t1.y] >= 0 )
			{
				flag2 = 1;
				break;
			}
		if( !flag1 && !flag2 ) 
		{
			m_subpoint[0] = t1;
			return 1;
		}
		//右上角
		for( i = t2.y; i < p2.y; i++ )
			if( map[t2.x][i] >= 0 ) return 0;
		for( i = p1.x+1; i < t2.x; i++ )
			if( map[i][t2.y] >= 0 ) return 0;
		m_subpoint[0] = t2;
		return 1;
	}
	//"/"
	if( p1.y > p2.y )
	{
		flag1 = flag2 = 0;
		//左上角
		for( i = t1.y+1; i < p1.y; i++ )
			if( map[t1.x][i] >= 0 )
			{
				flag1 = 1;
				break;
			}
		if( !flag1 )
		for( i = t1.x; i < p2.x; i++ )
			if( map[i][t1.y] >= 0 )
			{
				flag2 = 1;
				break;
			}
		if( !flag1 && !flag2 ) 
		{
			m_subpoint[0] = t1;
			return 1;
		}
		//右下角
		for( i = p2.y+1; i < t2.y; i++ )
			if( map[t2.x][i] >= 0 ) return 0;
		for( i = p1.x+1; i <= t2.x; i++ )
			if( map[i][t2.y] >= 0 ) return 0;
		m_subpoint[0] = t2;
		return 1;
	}
	return 0;
}

bool CWndDlg::find3(CPoint _p1,CPoint _p2)
{
	CPoint p1 = _p1, t1, t2;
	CPoint p2 = _p2;
	int i;

	t1.x = p1.x;
	t2.x = p2.x;

	for( i = 0; i <= m_y+1; i++ )
	{
		if( i == p1.y || i == p2.y ) continue;
		t1.y = t2.y = i;
		if( find1( p1, t1 ) && find1( p2, t2 ) && find1( t1.x, t1.y, t2.x, t2.y ) )
		{
			m_subpoint[0] = t1;
			m_subpoint[1] = t2;
			return 1;
		}
	}

	t1.y = p1.y;
	t2.y = p2.y;

	for( i = 0; i <= m_x+1; i++ )
	{
		if( i == p1.x || i == p2.x ) continue;
		t1.x = t2.x = i;
		if( find1( p1, t1 ) && find1( p2, t2 ) && find1( t1.x, t1.y, t2.x, t2.y ) )
		{
			m_subpoint[0] = t1;
			m_subpoint[1] = t2;
			return 1;
		}
	}

	return 0;
}

bool CWndDlg::find1(int _x1, int _y1, int _x2, int _y2)
{
	int i;
	if( _x1 == _x2 )
	{
		if( _y1 > _y2 ) swap(_y1,_y2);
		for( i = _y1; i <= _y2 ; i++ )
			if( map[_x1][i] >= 0 ) return 0;
		return 1;
	}
	if( _y1 == _y2 )
	{
		if( _x1 > _x2 ) swap(_x1,_x2);
		for( i = _x1; i <= _x2; i++ )
			if( map[i][_y1] >= 0 ) return 0;
		return 1;
	}
	return 0;
}

void CWndDlg::drawline(CPoint _p1, CPoint _p2)
{
	CPoint p1,p2;
	p1.x = (_p1.x-1)*80 + m_margin + 40;
	p1.y = (_p1.y-1)*80 + m_margin + 40;
	p2.x = (_p2.x-1)*80 + m_margin + 40;
	p2.y = (_p2.y-1)*80 + m_margin + 40;
	CDC *dc = GetDC();
	CPen pen;
	pen.CreatePen( PS_SOLID, 1, RGB(255,0,0) );
	dc->SelectObject( &pen );
	dc->SetROP2( R2_NOTXORPEN );
	dc->MoveTo( p1 );
	dc->LineTo( p2 );
	ReleaseDC(dc);
}

bool CWndDlg::Over()
{
	for(int i = 1; i <= m_x; i++ )
		for(int j = 1; j <= m_y; j++ )
			if( map[i][j] >= 0 ) return 0;
	return 1;
}

bool CWndDlg::failed()
{
	int cnt,i,j,k;
	vector<CPoint> vp[45];
	for(i = 1; i <= m_x; i++ )
		for(j = 1; j <= m_y; j++ )
			if( map[i][j] >= 0 ) 
			{
				CPoint pt(i,j);
				vp[map[i][j]].push_back(pt);
			}
	for(i = 0; i < m_num; i++ )
	{
		cnt = vp[i].size();
		for(j = 0; j < cnt-1; j++ )
		{
			for(k = j+1; k < cnt; k++ )
			{
				if( find1( vp[i][j], vp[i][k] ) || find2( vp[i][j], vp[i][k] ) || find3( vp[i][j], vp[i][k] ) )
					return 1;
			}
		}
	}
	return 0;
}
