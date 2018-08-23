
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
};

#ifndef _DEBUG  // debug version in drawing a lineView.cpp
inline CdrawingalineDoc* CdrawingalineView::GetDocument() const
   { return reinterpret_cast<CdrawingalineDoc*>(m_pDocument); }
#endif

