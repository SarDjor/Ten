
// MFCApplication1View.cpp : реализация класса CMFCApplication1View
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
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
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// создание/уничтожение CMFCApplication1View

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: добавьте код создания

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CMFCApplication1View

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	

	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;	
}
void CMFCApplication1View::OnDrawRectangle(CDC* pDC){
	
}


// печать CMFCApplication1View

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CMFCApplication1View

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CMFCApplication1View




//HRESULT CMFCApplication1View::accDoDefaultAction(VARIANT varChild)
//{
//	// TODO: добавьте специализированный код или вызов базового класса
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
	
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}




void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	Invalidate();
	UpdateWindow();
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

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
		
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CView::OnRButtonDown(nFlags, point);
}
