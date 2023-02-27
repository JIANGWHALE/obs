
// obsView.h: CobsView 类的接口
//

#pragma once


class CobsView : public CView
{
protected: // 仅从序列化创建
	CobsView() noexcept;
	DECLARE_DYNCREATE(CobsView)

// 特性
public:
	CobsDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CobsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // obsView.cpp 中的调试版本
inline CobsDoc* CobsView::GetDocument() const
   { return reinterpret_cast<CobsDoc*>(m_pDocument); }
#endif

