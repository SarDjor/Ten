
// MFCApplication1View.cpp : ���������� ������ CMFCApplication1View
//

#include "stdafx.h"
// SHARED_HANDLERS ����� ���������� � ������������ �������� ��������� ���������� ������� ATL, �������
// � ������; ��������� ��������� ������������ ��� ��������� � ������ �������.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// ����������� ������� ������
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// ��������/����������� CMFCApplication1View

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: �������� ��� ��������

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �������� ����� Window ��� ����� ����������� ���������
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// ��������� CMFCApplication1View

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	

	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;	
}
void CMFCApplication1View::OnDrawRectangle(CDC* pDC){
	
}


// ������ CMFCApplication1View

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ���������� �� ���������
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� �������������� ������������� ����� �������
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �������� ������� ����� ������
}


// ����������� CMFCApplication1View

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // �������� ������������ ������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// ����������� ��������� CMFCApplication1View




//HRESULT CMFCApplication1View::accDoDefaultAction(VARIANT varChild)
//{
//	// TODO: �������� ������������������ ��� ��� ����� �������� ������
//
//	return CView::accDoDefaultAction(varChild);
//}


void CMFCApplication1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CClientDC* pDC = new CClientDC(this);
	CBrush aBrush(RGB(255, 157, 6));
	CBrush aBrush1(RGB(11, 34, 201));
	CBrush aBrush2(RGB(4, 255, 114));
	CBrush aBrush3(RGB(96, 195, 11));
	CBrush* pOldBrush = pDC->SelectObject(&aBrush);
	switch (nChar){
	case 0x31: pDC->SelectObject(aBrush); pDC->Ellipse(30, 30, 70, 70); break;
	case 0x32: pDC->SelectObject(aBrush1); pDC->Ellipse(80, 30, 100, 80); break;
	case 0x33: pDC->SelectObject(aBrush2); pDC->Rectangle(120, 30, 180, 50); break;
	case 0x34: pDC->SelectObject(aBrush3); pDC->Rectangle(200, 30, 250, 80); break;
	case 0x35: pDC->MoveTo(300, 30); pDC->LineTo(280, 50); pDC->LineTo(320, 40); pDC->LineTo(300, 30); break;
	case 0x36: pDC->MoveTo(350, 30); pDC->AngleArc(350, 30, 20, 0, 180); break;
	}
	
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}




void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	Invalidate();
	UpdateWindow();
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������

	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	int i = 0;
	while (i < 5){
		CClientDC pDC(this);
		pDC.SetTextColor(RGB(i*30, i*40, i*55));
		pDC.TextOut((i*150)+100, 50, L"Hello", 6);
		i++;
		Sleep(3000);
	}
		
	// TODO: �������� ���� ��� ����������� ��������� ��� ����� ������������

	CView::OnRButtonDown(nFlags, point);
}
