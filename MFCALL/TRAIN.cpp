// TRAIN.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCALL.h"
#include "TRAIN.h"
#include "afxdialogex.h"


// TRAIN 对话框

IMPLEMENT_DYNAMIC(TRAIN, CDialogEx)

TRAIN::TRAIN(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TRAIN, pParent)
{

}

TRAIN::~TRAIN()
{
}

void TRAIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TRAIN, CDialogEx)
END_MESSAGE_MAP()


// TRAIN 消息处理程序
