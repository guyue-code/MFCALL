// TEST.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCALL.h"
#include "TEST.h"
#include "afxdialogex.h"
#include <stdio.h>
#include "NIDAQmx.h"


// TEST 对话框

IMPLEMENT_DYNAMIC(TEST, CDialogEx)
TaskHandle	taskHandle = 0;

TEST::TEST(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST, pParent)
{

}

TEST::~TEST()
{
}

void TEST::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TEST, CDialogEx)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &TEST::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TEST::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &TEST::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &TEST::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &TEST::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &TEST::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &TEST::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &TEST::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &TEST::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &TEST::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &TEST::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &TEST::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &TEST::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &TEST::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &TEST::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &TEST::OnBnClickedButton16)
END_MESSAGE_MAP()


// TEST 消息处理程序


void TEST::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	switch (nIDEvent)
	{
	case 1:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xfe);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(1);
	
	}
		break;
	case 2:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xfd);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(2);

	}
	break;
	case 3:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xfb);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(3);

	}
	break;
	case 4:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xf7);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(4);

	}
	break;
	case 5:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xef);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(5);

	}
	break;
	case 6:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xdf);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(6);

	}
	break;
	case 7:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xbf);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(7);

	}
	break;
	case 8:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0x7f);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(8);

	}
	break;
	case 9:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data | 0x01);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		
		SetTimer(17, 1000, NULL);

	}
	break;
	case 10:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data | 0x02);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);

		SetTimer(18, 1000, NULL);

	}
	break;
	case 11:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data | 0x04);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);

		SetTimer(19, 1000, NULL);

	}
	break;
	case 12:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data | 0x08);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);

		SetTimer(20, 1000, NULL);

	}
	break;
	case 13:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data | 0x10);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);

		SetTimer(21, 1000, NULL);

	}
	break;
	case 14:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data | 0x20);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);

		SetTimer(22, 1000, NULL);

	}
	break;
	case 15:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data | 0x40);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);

		SetTimer(23, 1000, NULL);

	}
	break;
	case 16:
	{
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data | 0x80);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);

		SetTimer(24, 1000, NULL);

	}
	break;
	case 17:
	{
		KillTimer(9);
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xfe);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(17);
		

	}
	break;
	case 18:
	{
		KillTimer(10);
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xfd);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(18);


	}
	break;
	case 19:
	{
		KillTimer(11);
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xfb);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(19);


	}
	break;
	case 20:
	{
		KillTimer(12);
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xf7);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(20);


	}
	break;
	case 21:
	{
		KillTimer(13);
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xef);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(21);


	}
	break;
	case 22:
	{
		KillTimer(14);
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xdf);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(22);


	}
	break;
	case 23:
	{
		KillTimer(15);
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0xbf);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(23);


	}
	break;
	case 24:
	{
		KillTimer(16);
		DAQmxCreateTask("", &taskHandle);
		uInt32      data;
		int32		written;
		int32		read;
		DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
		DAQmxStartTask(taskHandle);
		DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
		data = (data & 0x7f);
		DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
		DAQmxStopTask(taskHandle);
		KillTimer(24);


	}
	break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


void TEST::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	DAQmxCreateTask("", &taskHandle);
	uInt32      data;
	int32		written;
	int32		read;
	DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
	DAQmxStartTask(taskHandle);
	DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
	data = (data | 0x01);

	DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
	DAQmxStopTask(taskHandle);
	SetTimer(1, 2000, NULL);
}


void TEST::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	DAQmxCreateTask("", &taskHandle);
	uInt32      data;
	int32		written;
	int32		read;
	DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
	DAQmxStartTask(taskHandle);
	DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
	data = (data | 0x02);

	DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
	DAQmxStopTask(taskHandle);
	SetTimer(2, 2000, NULL);
}


void TEST::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	DAQmxCreateTask("", &taskHandle);
	uInt32      data;
	int32		written;
	int32		read;
	DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
	DAQmxStartTask(taskHandle);
	DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
	data = (data | 0x04);
	DAQmxWriteDigitalU32(taskHandle, 1, 0, 10.0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
	DAQmxStopTask(taskHandle);

	SetTimer(3, 2000, NULL);
}


void TEST::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	DAQmxCreateTask("", &taskHandle);
	uInt32      data;
	int32		written;
	int32		read;
	DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
	DAQmxStartTask(taskHandle);
	DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
	data = (data | 0x08);
	DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
	DAQmxStopTask(taskHandle);

	SetTimer(4, 2000, NULL);
}


void TEST::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	DAQmxCreateTask("", &taskHandle);
	uInt32      data;
	int32		written;
	int32		read;
	DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
	DAQmxStartTask(taskHandle);
	DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
	data = (data | 0x10);
	DAQmxWriteDigitalU32(taskHandle, 1, 0, 10.0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
	DAQmxStopTask(taskHandle);

	SetTimer(5, 2000, NULL);
}


void TEST::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	DAQmxCreateTask("", &taskHandle);
	uInt32      data;
	int32		written;
	int32		read;
	DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
	DAQmxStartTask(taskHandle);
	DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
	data = (data | 0x20);
	DAQmxWriteDigitalU32(taskHandle, 1, 0, 10.0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
	DAQmxStopTask(taskHandle);

	SetTimer(6, 2000, NULL);
}


void TEST::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	DAQmxCreateTask("", &taskHandle);
	uInt32      data;
	int32		written;
	int32		read;
	DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
	DAQmxStartTask(taskHandle);
	DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
	data = (data | 0x40);
	DAQmxWriteDigitalU32(taskHandle, 1, 0, 10.0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
	DAQmxStopTask(taskHandle);

	SetTimer(7, 2000, NULL);
}


void TEST::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	DAQmxCreateTask("", &taskHandle);
	uInt32      data;
	int32		written;
	int32		read;
	DAQmxCreateDOChan(taskHandle, "Dev1/port0", "", DAQmx_Val_ChanForAllLines);
	DAQmxStartTask(taskHandle);
	DAQmxReadDigitalU32(taskHandle, 1, 0, DAQmx_Val_GroupByChannel, &data, 1, NULL, NULL);
	data = (data | 0x80);
	DAQmxWriteDigitalU32(taskHandle, 1, 0, 0, DAQmx_Val_GroupByChannel, &data, NULL, NULL);
	DAQmxStopTask(taskHandle);

	SetTimer(8, 2000, NULL);

}


void TEST::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(9, 2000, NULL);

}


void TEST::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(10, 2000, NULL);
}


void TEST::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(11, 2000, NULL);
}


void TEST::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(12, 2000, NULL);
}


void TEST::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(13, 2000, NULL);
}


void TEST::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(14, 2000, NULL);
}


void TEST::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(15, 2000, NULL);
}


void TEST::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(16, 2000, NULL);
}
