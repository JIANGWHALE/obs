
// obsView.cpp: CobsView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "obs.h"
#endif

#include "obsDoc.h"
#include "obsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CobsView

IMPLEMENT_DYNCREATE(CobsView, CView)

BEGIN_MESSAGE_MAP(CobsView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CobsView 构造/析构

CobsView::CobsView() noexcept
{
	// TODO: 在此处添加构造代码

}

CobsView::~CobsView()
{
}

BOOL CobsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CobsView 绘图

void CobsView::OnDraw(CDC* pDC)
{
	CobsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//客户区大小
	CRect rc;
	GetClientRect(&rc);

	//屏幕大小
	int nWidthScreen = GetSystemMetrics(SM_CXSCREEN);
	int nHeightScreen = GetSystemMetrics(SM_CYSCREEN);

	CDC dcScreen;
	dcScreen.CreateDC("DISPLAY", NULL, NULL, NULL);

	pDC->StretchBlt(
		0, 0, rc.Width(), rc.Height(),
		&dcScreen, 0, 0, nWidthScreen, nHeightScreen,
		SRCCOPY
	);
}


// CobsView 打印

BOOL CobsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CobsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CobsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CobsView 诊断

#ifdef _DEBUG
void CobsView::AssertValid() const
{
	CView::AssertValid();
}

void CobsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CobsDoc* CobsView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CobsDoc)));
	return (CobsDoc*)m_pDocument;
}
#endif //_DEBUG


// CobsView 消息处理程序


int CobsView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(0, 10, NULL);

	return 0;
}


void CobsView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	InvalidateRect(NULL, FALSE);

	CView::OnTimer(nIDEvent);
}
