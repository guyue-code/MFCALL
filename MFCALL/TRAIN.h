#pragma once


// TRAIN 对话框

class TRAIN : public CDialogEx
{
	DECLARE_DYNAMIC(TRAIN)

public:
	TRAIN(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TRAIN();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
