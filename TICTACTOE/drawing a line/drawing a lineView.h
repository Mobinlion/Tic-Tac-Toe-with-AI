
// drawing a lineView.h : interface of the CdrawingalineView class
//


#pragma once


class CdrawingalineView : public CView
{
protected: // create from serialization only
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	void OnInitialUpdate();
	CdrawingalineView();
	DECLARE_DYNCREATE(CdrawingalineView)

// Attributes
public:
	CRgn rgn;
	CImageList image;
	CImage ci;
	CScrollBar bar;
	void kaboom(CDC *dc,CPoint point);
	void drawline(CDC*, int, int);
	void drawcircle(CDC*, int, int);
	void victory();
	void playerMove(int board[9]);
	void computerMove(int board[9]);
	int MiniMaxAlgorithm(int board[9], int player);
	int win(const int board[9]);
	void draw(int b[9]);
	char gridChar(int i);

	
	CdrawingalineDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	//virtual void OnCreate(LPCREATESTRUCT lpcs);

// Implementation
public:
	virtual ~CdrawingalineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#ifndef _DEBUG  // debug version in drawing a lineView.cpp
inline CdrawingalineDoc* CdrawingalineView::GetDocument() const
   { return reinterpret_cast<CdrawingalineDoc*>(m_pDocument); }
#endif





struct Data
{

	RECT mRect;
	int win;

};