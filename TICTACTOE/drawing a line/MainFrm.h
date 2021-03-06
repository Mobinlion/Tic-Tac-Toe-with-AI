
// MainFrm.h : interface of the CMainFrame class
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
public:
	CToolBar bar;
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
#ifdef NDEBUG
#ifndef _DEBUG
	virtual int OnCreate(LPCREATESTRUCT lpCreateStruct);
#endif
#endif

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

};


