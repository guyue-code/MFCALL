#pragma once


// TRAIN �Ի���

class TRAIN : public CDialogEx
{
	DECLARE_DYNAMIC(TRAIN)

public:
	TRAIN(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TRAIN();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
