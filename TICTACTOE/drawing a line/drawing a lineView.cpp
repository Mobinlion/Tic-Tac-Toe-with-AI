
// drawing a lineView.cpp : implementation of the CdrawingalineView class
//

#include "stdafx.h"
#include "drawing a line.h"

#include "drawing a lineDoc.h"
#include "drawing a lineView.h"
#include "math.h"

int arrSinus[1000];
int iTime=0;
#define LIMIT GetSystemMetrics(SM_CYSCREEN)/3.3712 
#define LIMIT2 GetSystemMetrics(SM_CXSCREEN)/3.012
//#define LIMIT 228
//#define LIMIT2 340
//RECT mRect[9];
//int win[3][3];
Data buf[3][3];
#define X 1
#define O 2

bool X_turn = true;
bool O_turn = false;
int DRAW;
bool isBot = false;

#ifdef _DEBGU
#define new DEBUG_NEW
#endif

char data[4][4] = {'h','e','l','l','o'};
int table[9] = {0,0,0,0,0,0,0,0,0};
int player=1;
unsigned turn;

enum day {mon =1, tuesday, wed, thu, fri
};


void CdrawingalineView::victory()
{
	
	int counter = 0, counter2 = 0;
	int counter3 = 0, counter4 = 0;
	int limit = 3;

	for(int i = 0; i < limit; i++)
	{
		
		for(int j = 0 ; j < limit; j++)
		{
		 if(buf[i][j].win == X)
			 counter++;

		 else if(buf[i][j].win == O)
			 counter2++;
		}

		for(int k = 0; k < limit; k++)
		{
			if(buf[k][i].win == X)
				counter3++;

			else if(buf[k][i].win == O) 
				counter4++;

		}
		if(counter == limit || counter3 == limit)
		{
			
			MessageBoxA("X victory!", "DONT BRAG LOL");
			this->Invalidate();
			return;
			
		}
		else if(counter2 == limit || counter4 == limit )
		{

			MessageBox("O victory!", "Did you lose to a computer? Really?");
			this->Invalidate();
			return;
			
		}

		counter  = 0;
		counter2 = 0;
		counter3 = 0;
		counter4 = 0;


	}




	for (int i = 0, j = 0; i < limit; i++, j++)
	{

		
		if(buf[i][j].win == X)
		{
			counter++;
		}
		else if(buf[i][j].win == O)
			counter2++;
	}

		if(counter == limit)
		{			
			MessageBox("X victory!", "DONT BRAG LOL");
			this->Invalidate();	
			return;
		}

		else if (counter2 == limit)
		{			
			MessageBox("O victory!", "Did you lose to a computer? Really?");
			this->Invalidate();			
			return;
		}


	
	for(int i = (limit-1), j = 0; j<limit; i--, j++)
	{
		
		if(buf[i][j].win == X)
		{
			counter3++;

		}
		else if(buf[i][j].win == O)
			counter4++;

	}
	
	if(counter3 == limit)
		{			
			MessageBox("X victory!", "DONT BRAG LOL");
			this->Invalidate();		
			return;
		}


	else if (counter4 == limit)
		{			
			MessageBox("O victory!", "Did you lose to a computer? Really?");
			this->Invalidate();	
			return;
		}

	if(DRAW==9)
	{
		MessageBox("Draw!", "Nobody victory");
		this->Invalidate();
		return;
	}
	
}



void CdrawingalineView::drawcircle(CDC *dc, int i, int j)
{

	//this->Invalidate(1);
	//pen is for drawing the lines
	CPen pen2(PS_SOLID,9,RGB(0,0,255));
	dc->SelectObject(&pen2);
	//brush is for interior of the ellipse
	CBrush brush(RGB(255,255,255));
	dc->SelectObject(&brush);
	dc->Ellipse(buf[i][j].mRect.left+5, buf[i][j].mRect.top+5, buf[i][j].mRect.right-5, buf[i][j].mRect.bottom-5);
	
}

void CdrawingalineView::drawline(CDC *dc, int i, int j)
{

	CPen pen2(PS_SOLID,9,RGB(255,0,0));
	//dc->br
	dc->SelectObject(&pen2);
	dc->MoveTo(buf[i][j].mRect.left +5, buf[i][j].mRect.top+5);
	dc->LineTo(buf[i][j].mRect.right-5, buf[i][j].mRect.bottom-5);
	dc->MoveTo(buf[i][j].mRect.left + LIMIT2 - 5 , buf[i][j].mRect.top + 5);
	dc->LineTo(buf[i][j].mRect.right - LIMIT2 + 5, buf[i][j].mRect.bottom - 5);

}


void CdrawingalineView::kaboom(CDC *dc,CPoint point)
{
	
	this->ShowWindow(SW_MAXIMIZE);
	memset(buf, '\0', sizeof(buf));
	memset(table, '\0', sizeof(table));
	DRAW = 0;
	X_turn = true;
	O_turn = false;

	CPen pen(PS_SOLID,5,RGB(0,0,0));
	CBrush brush(RGB(255,255,255));
	//dc->SetROP2(R2_NOT);
	dc->SelectObject(&pen);
	//brush paints the inner of an object like ellipse or rectangle or can use fillsolidrect
	dc->SelectObject(&brush);

	
	POINT p1 = {point.x, point.y};
	POINT data = {0,0};
	POINT data2 = {LIMIT2,LIMIT};
	//mRect[0].top = 0; mRect[0].left = 0;
	//mRect[0].bottom = LIMIT; mRect[0].right = LIMIT2;

	for ( int i = 0 ; i<3; i++)
	{

		for(int j =0 ; j<3; j++)
		{
			dc->Rectangle(data.x , data.y, data2.x, data2.y);
			//fills rect with solid color from pen
			//brush paints the inner of an object like ellipse or rectangle or can use fillsolidrect
			//dc->FillSolidRect(data.x , data.y, data2.x, data2.y, RGB(2,0,0));
			
			//store rectangle point of every box

			buf[i][j].mRect.top = data.y;
			buf[i][j].mRect.left = data.x;
			buf[i][j].mRect.bottom = data2.y;
			buf[i][j].mRect.right = data2.x;
			
			//end of rectangle point storage

			data.x += LIMIT2;
			data2.x += LIMIT2;
		}

		data.x   = 0;
		data.y  += LIMIT;
		data2.y += LIMIT;
		data2.x  = LIMIT2;

	}


	
	//this->drawline(dc);

	//POINT lp = {1,2};
	
	
	
	
}

void CdrawingalineView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);


	
	for(int i = 0 ; i<3 ; i++)
	{
		for(int j = 0 ; j<3; j++)
		{
			if(X_turn){

				if(PtInRect(&buf[i][j].mRect, point) && buf[i][j].win == 0)
				{
					this->drawline(&dc, i, j);
					buf[i][j].win = X;
					switch(i){
						case 0:
							table[j] = -1;
							break;
						case 1:
							table[j+3] = -1;
							break;
						case 2:
							table[6+j] = -1;
							break;
					}
					
					DRAW++;
					X_turn = false;
					O_turn = true;  //X turn needs to be true laterz
					this->victory();

				}
			}

			if(O_turn)
			{	
				//COMPUTER MOVE
					
					int tmov = -1;
					int PScr = -2;	
					int i;
					for(i = 0; i < 9; ++i) {
						if(table[i] == 0) {
							table[i] = 1;
							int tmpvar = -MiniMaxAlgorithm(table, -1);
							table[i] = 0;
							if(tmpvar > PScr) {
								PScr = tmpvar;
								tmov = i;
							}
						}
					}
					//returns a PScr based on MiniMaxAlgorithm tree at a given node.
					table[tmov] = 1;
					switch(tmov)
					{
					case 0:
						this->drawcircle(&dc, tmov, tmov);
						buf[0][0].win = O;
						break;
					case 1:
						this->drawcircle(&dc, 0, 1);
						buf[0][1].win = O;
						break;
					case 2:
						this->drawcircle(&dc, 0,2);
						buf[0][2].win = O;
						break;
					case 3:
						this->drawcircle(&dc, 1,0);
						buf[1][0].win = O;
						break;
					case 4:
						this->drawcircle(&dc, 1,1);
						buf[1][1].win = O;
						break;
					case 5: 
						this->drawcircle(&dc, 1,2);
						buf[1][2].win = O;
						break;
					case 6:
						this->drawcircle(&dc, 2,0);
						buf[2][0].win = O;
						break;
					case 7:
						this->drawcircle(&dc, 2,1);
						buf[2][1].win = O;
						break;
					case 8:
						this->drawcircle(&dc, 2,2);
						buf[2][2].win = O;
						break;
						
					}
					X_turn = true;
					O_turn = false;
					DRAW++;
					this->victory();
					/*this->drawcircle(&dc, i, j);*/

					//END COMPUTER MOVE
			}
		}
	}

	
	//CWnd::OnLButtonDown(nFlags,point);
	//MessageBox("123");
	//kaboom(&dc,point);
	

}


// CdrawingalineView

IMPLEMENT_DYNCREATE(CdrawingalineView, CView)

BEGIN_MESSAGE_MAP(CdrawingalineView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
//	ON_WM_SYSKEYDOWN()
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
	//image.Create(IDB_BITMAP2,60,0,CLR_NONE);
	//image.Draw(pDC,1,CPoint(0,0),ILD_NORMAL);
	//
	////image.Draw(  //change mouse cursor when on bitmap

	/*CDC (GetDC();
	DrawText(*/
	//rgn.CreateRoundRectRgn(0,0,44,44,55,55);

	//ci.Load((CString)"D:\\tcp.jpg");
	//CDC *dc1 = AfxGetMainWnd()->GetDC();
	//HDC hdc = *dc1;
	//ci.Draw(hdc,0,0);
	//pDC->SetBkColor(RGB(0,0,200));
	kaboom(&dc,NULL);

	if(isBot)
	{

		X_turn = false;
		O_turn = true;
		int tmov = -1;
		int PScr = -2;	
		int i;
		for(i = 0; i < 9; ++i) {
			if(table[i] == 0) {
				table[i] = 1;
				int tmpvar = -MiniMaxAlgorithm(table, -1);
				table[i] = 0;
				if(tmpvar > PScr) {
					PScr = tmpvar;
					tmov = i;
				}
			}
		}
		//returns a PScr based on MiniMaxAlgorithm tree at a given node.
		table[tmov] = 1;
		switch(tmov)
		{
		case 0:
			this->drawcircle(&dc, tmov, tmov);
			buf[0][0].win = O;
			break;
		case 1:
			this->drawcircle(&dc, 0, 1);
			buf[0][1].win = O;
			break;
		case 2:
			this->drawcircle(&dc, 0,2);
			buf[0][2].win = O;
			break;
		case 3:
			this->drawcircle(&dc, 1,0);
			buf[1][0].win = O;
			break;
		case 4:
			this->drawcircle(&dc, 1,1);
			buf[1][1].win = O;
			break;
		case 5: 
			this->drawcircle(&dc, 1,2);
			buf[1][2].win = O;
			break;
		case 6:
			this->drawcircle(&dc, 2,0);
			buf[2][0].win = O;
			break;
		case 7:
			this->drawcircle(&dc, 2,1);
			buf[2][1].win = O;
			break;
		case 8:
			this->drawcircle(&dc, 2,2);
			buf[2][2].win = O;
			break;
			
		}
		X_turn = true;
		O_turn = false;
		DRAW++;
	}
	//pDC->Polygon(&CPoint(100,100),9);
	CRect rect(0,0,100,400);
	//pDC->Rectangle(rect);
	//pDC->Draw3dRect(rect,RGB(200,120,22),RGB(0,255,0));
	
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



void CdrawingalineView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	/*if(PtInRect(&mRect[0], point))
	this->drawline(&dc, 0);*/

	CView::OnMouseMove(nFlags, point);
}

void CdrawingalineView::OnRButtonDown(UINT nFlags, CPoint point)
{
	this->Invalidate();
	// TODO: Add your message handler code here and/or call default

	CView::OnRButtonDown(nFlags, point);
}

void CdrawingalineView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	
	if(nChar == VK_ADD)//&& nRepCnt > 5) 
		this->Invalidate();

	if(nChar == 0x31)
	{
		X_turn = false;
		O_turn = true;
		isBot = true;
		this->Invalidate();
	}
	else if(nChar == 0x32)
	{
		X_turn = true;
		O_turn = false;
		isBot = false;
		this->Invalidate();
	}
		

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

//void CdrawingalineView::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	if(nChar == 0x4D)
//		MessageBoxA("system key", "lol", 2);
//	// TODO: Add your message handler code here and/or call default
//
//	CView::OnSysKeyDown(nChar, nRepCnt, nFlags);
//}



char CdrawingalineView::gridChar(int i) {
    switch(i) {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
	return 0;
}

void CdrawingalineView::draw(int b[9]) {
   
}


int CdrawingalineView::win(const int table[9]) {
    //determines if a player has won, returns 0 otherwise.
    unsigned victory[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i = 0; i < 8; ++i) {
        if(table[victory[i][0]] != 0 &&
           table[victory[i][0]] == table[victory[i][1]] &&
           table[victory[i][0]] == table[victory[i][2]])
            return table[victory[i][2]];
    }
    return 0;
}


int CdrawingalineView::MiniMaxAlgorithm(int table[9], int player) {
    //How is the position like for player (their turn) on table?
    int vick = win(table);
    if(vick != 0) return vick*player;

    int tmov = -1;
    int PScr = -2;//Losing moves are preferred to no move
    int i;
    for(i = 0; i < 9; ++i) {//For all moves,
        if(table[i] == 0) {//If legal,
            table[i] = player;//Try the move
            int thisPScr = -MiniMaxAlgorithm(table, player*-1);
            if(thisPScr > PScr) {
                PScr = thisPScr;
                tmov = i;
            }//Pick the one that's worst for the opponent
            table[i] = 0;//Reset table after try
        }
    }
    if(tmov == -1) return 0;
    return PScr;
}


void CdrawingalineView::computerMove(int table[9]) {
    int tmov = -1;
    int PScr = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(table[i] == 0) {
            table[i] = 1;
            int tmpvar = -MiniMaxAlgorithm(table, -1);
            table[i] = 0;
            if(tmpvar > PScr) {
                PScr = tmpvar;
                tmov = i;
            }
        }
    }
    //returns a PScr based on MiniMaxAlgorithm tree at a given node.
    table[tmov] = 1;
}

