
// 3.16exp4.2View.h : CMy316exp42View ��Ľӿ�
//

#pragma once


class CMy316exp42View : public CView
{
protected: // �������л�����
	CMy316exp42View();
	DECLARE_DYNCREATE(CMy316exp42View)

// ����
public:
	CMy316exp42Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy316exp42View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 3.16exp4.2View.cpp �еĵ��԰汾
inline CMy316exp42Doc* CMy316exp42View::GetDocument() const
   { return reinterpret_cast<CMy316exp42Doc*>(m_pDocument); }
#endif

