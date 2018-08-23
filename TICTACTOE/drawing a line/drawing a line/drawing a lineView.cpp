
// drawing a lineView.cpp : implementation of the CdrawingalineView class
//

#include "stdafx.h"
#include "drawing a line.h"

#include "drawing a lineDoc.h"
#include "drawing a lineView.h"
#include "math.h"

int arrSinus[1000];
int iTime=0;

#ifdef _DEBGU
#define new DEBUG_NEW
#endif


void CdrawingalineView::kaboom(CDC *dc,CPoint point)
{
	

	
	CPen pen(PS_SOLID,3,RGB(110,215,55));
	CBrush brush(RGB(255,0,0));
	//dc->SetROP2(R2_NOT);
	dc->SelectObject(&pen);
	dc->MoveTo(0,0);
	dc->LineTo(point);
	//MessageBox("ADAD");
	dc->Ellipse(700,359,100,150);
	dc->Rectangle(125,155,255,255);
	
	
}

void CdrawingalineView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	//CWnd::OnLButtonDown(nFlags,point);
	//MessageBox("123");
	kaboom(&dc,point);
	

}


// CdrawingalineView

IMPLEMENT_DYNCREATE(CdrawingalineView, CView)

BEGIN_MESSAGE_MAP(CdrawingalineView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CdrawingalineView construction/destruction

CdrawingalineView::CdrawingalineView()
{
	// TODO: add construction code here

}

CdrawingalineView::~CdrawingalineView()
{
}

BOOL CdrawingalineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CdrawingalineView drawing

void CdrawingalineView::OnDraw(CDC* pDC)
{
	CClientDC dc(this);
	//bar.Create(WS_CHILD|WS_VISIBLE|SBS_VERT,CRect(418,0,461,800),this,24);
	image.Create(IDB_BITMAP2,60,0,CLR_NONE);
	image.Draw(pDC,1,CPoint(0,0),ILD_NORMAL);
	
	//image.Draw(  //change mouse cursor when on bitmap

	rgn.CreateRoundRectRgn(0,0,44,44,55,55);

	ci.Load((CString)"D:\\tcp.jpg");
	CDC *dc1 = AfxGetMainWnd()->GetDC();
	HDC hdc = *dc1;
	//ci.Draw(hdc,0,0);

	//pDC->Polygon(&CPoint(100,100),9);
	CRect rect(0,0,100,400);
	pDC->Rectangle(rect);
	pDC->Draw3dRect(rect,RGB(200,120,22),RGB(0,255,0));
	
/*
	/////////////
	#define xx0 30
	#define yy0 100

        dc.TextOut(30,105,"SINUS LINE");
        CString strx;
        strx.Format("Step = %d",iTime);
        dc.TextOut(30,120,strx);

        dc.MoveTo(xx0,yy0);
        dc.LineTo(xx0+800,yy0);
		
        int xx=0;
        int yy;
        while(xx <= iTime)
        {
    yy = arrSinus[xx];
        if(xx==0) dc.MoveTo(xx0+xx,yy0-yy);
        else dc.LineTo(xx0+xx,yy0-yy);
        xx++;
        }*/
	
	CdrawingalineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	
	
	// TODO: add draw code for native data here
}


// CdrawingalineView diagnostics

#ifdef _DEBUG
void CdrawingalineView::AssertValid() const
{
	CView::AssertValid();
}

void CdrawingalineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdrawingalineDoc* CdrawingalineView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdrawingalineDoc)));
	return (CdrawingalineDoc*)m_pDocument;
}
#endif //_DEBUG


// CdrawingalineView message handlers


void CdrawingalineView::OnInitialUpdate()
{
	
	//bar.Create(WS_CHILD|WS_VISIBLE|SBS_VERT,CRect(418,0,461,800),this,24);


	/*ci.Load((CString)"D:\\sizes.jpg");
	CDC *dc1 = AfxGetMainWnd()->GetDC();
	HDC hdc = *dc1;
	ci.Draw(hdc,100,100);*/
	
	//bar.EnableScrollBar(ESB_DISABLE_BOTH);
	//bar.SetScrollRange(0, 400);
}


