
// exp3.3View.h : Cexp33View ��Ľӿ�
//

#pragma once


class Cexp33View : public CView
{
protected: // �������л�����
	Cexp33View();
	DECLARE_DYNCREATE(Cexp33View)

// ����
public:
	Cexp33Doc* GetDocument() const;
	int N, flag = 0;
	CArray< CRect, CRect>cr;
	bool set;
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
	virtual ~Cexp33View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // exp3.3View.cpp �еĵ��԰汾
inline Cexp33Doc* Cexp33View::GetDocument() const
   { return reinterpret_cast<Cexp33Doc*>(m_pDocument); }
#endif

