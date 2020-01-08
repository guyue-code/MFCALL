// EXE.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCALL.h"
#include "EXE.h"
#include "afxdialogex.h"

#include "yolo_v2_class.hpp" //引用动态链接库中的头文件
#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include "CvvImage.h"
#include <iostream>
#include"Resource.h"


using namespace std;
using namespace cv;


VideoCapture capture;
Mat frame, image; //定义一个Mat变量，用于存储每一帧的图像  
int width, height;
CRect pic_rect;
int width1, height1;
CRect pic_rect1;


string names_file = "voc.names";
string cfg_file = "yolov3-tiny.cfg";
string weights_file = "yolov3-tiny_last.weights";
Detector detector(cfg_file, weights_file, 0);
vector<string> obj_names;

// EXE 对话框

IMPLEMENT_DYNAMIC(EXE, CDialogEx)

EXE::EXE(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXE, pParent)
	, button(false)
	, button_stop(false)
	, color_sel(false)
	, last(0)
	, vec1(10, Point(0, 0))
	, vec2(10, Point(0, 0))
	, bottle_sum(0)
	, baise_sum(0)
	, lanse_sum(0)
	, qianlan_sum(0)
	, lvse_sum(0)
	, qianlv_sum(0)
	, zongse_sum(0)
	, zise_sum(0)
	
{

}

EXE::~EXE()
{
}

void EXE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_cbx);
}


BEGIN_MESSAGE_MAP(EXE, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &EXE::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON3, &EXE::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &EXE::OnBnClickedButton4)
	ON_CBN_SELCHANGE(IDC_COMBO1, &EXE::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON5, &EXE::OnBnClickedButton5)
END_MESSAGE_MAP()


// EXE 消息处理程序


BOOL EXE::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	namedWindow("MyPicture", WINDOW_AUTOSIZE);
	HWND hWnd = (HWND)cvGetWindowHandle("MyPicture");
	HWND hParent = ::GetParent(hWnd);
	::SetParent(hWnd, GetDlgItem(IDC_VIDEO_STATIC)->m_hWnd);
	::ShowWindow(hParent, SW_HIDE);
	GetDlgItem(IDC_VIDEO_STATIC)->GetClientRect(&pic_rect);
	width = pic_rect.right;
	height = pic_rect.bottom;

	


	// TODO:  在此添加额外的初始化

	m_cbx.InsertString(0, _T("白色_x"));
	// 为组合框控件的列表框添加列表项“淡紫色”   
	m_cbx.InsertString(1, _T("蓝色_x"));

	m_cbx.InsertString(2, _T("浅蓝色_x"));

	m_cbx.InsertString(3, _T("绿色_x"));
	m_cbx.InsertString(4, _T("浅绿色_x"));
	m_cbx.InsertString(5, _T("棕色_x"));
	m_cbx.InsertString(6, _T("紫色_x"));
	m_cbx.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void EXE::draw_boxes(Mat mat_img, vector<bbox_t> result_vec, vector<string> obj_names, int current_det_fps = -1, int current_cap_fps = -1)
{
	int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };

	for (auto &i : result_vec) {
		Scalar color = obj_id_to_color(i.obj_id);
		rectangle(mat_img, Rect(i.x, i.y, i.w, i.h), color, 2);

		if (obj_names.size() > i.obj_id) {
			string obj_name = obj_names[i.obj_id];
			if (i.track_id > 0) obj_name += " - " + to_string(i.track_id);
			Size const text_size = getTextSize(obj_name, FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
			int const max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
			rectangle(mat_img, Point2f(max((int)i.x - 1, 0), max((int)i.y - 30, 0)),
				Point2f(min((int)i.x + max_width, mat_img.cols - 1), min((int)i.y, mat_img.rows - 1)), color, CV_FILLED, 8, 0);
			putText(mat_img, obj_name, Point2f(i.x, i.y - 10), FONT_HERSHEY_COMPLEX_SMALL, 1.2, Scalar(0, 0, 0), 2);
		}
	}
	if (current_det_fps >= 0 && current_cap_fps >= 0) {
		string fps_str = "FPS detection: " + to_string(current_det_fps) + "   FPS capture: " + to_string(current_cap_fps);
		putText(mat_img, fps_str, Point2f(10, 20), FONT_HERSHEY_COMPLEX_SMALL, 1.2, Scalar(50, 255, 0), 2);
	}
}

void EXE::show_console_result(vector<bbox_t> const result_vec, vector<string> const obj_names, int frame_id)
{
	vector<Point> mc(result_vec.size());
	vec0.push_back(vec1);
	vec0.push_back(vec2);
	idex1 = last;
	int k = 0;
	idex2 = (idex1 + 1) % 2;
	last = idex2;
	int a, b;
	for (int i = 0; i < result_vec.size(); i++)
	{
		//std::cout << "obj_id = " << result_vec[i].obj_id << ",  x = " << result_vec[i].x + result_vec[i].w / 2 << ", y = " << result_vec[i].y + result_vec[i].h / 2 << std::endl;
		mc[i] = Point(result_vec[i].x + result_vec[i].w / 2, result_vec[i].y + result_vec[i].h / 2);
		int distance = 0;
		int n = 0;
		a = mc[i].x;
		b = mc[i].y;
		for (int m = 0; m < 10; m++)     //跟前一帧图像中的目标逐一比对
		{
			distance = sqrt((mc[i].x - vec0.at(idex1).at(m).x)*(mc[i].x - vec0.at(idex1).at(m).x) + (mc[i].y - vec0.at(idex1).at(m).y)*(mc[i].y - vec0.at(idex1).at(m).y));

			if (distance > 100)
				n++;
		}

		if (n == 10)      //若果跟所有的目标的距离都大于67，则判定为新目标
		{
			//cout<<"新目标坐标： "<<mc[i].x<<", "<<mc[i].y<<endl;
			bottle_sum++;
			CString str_show;         //编辑控件显示的个数
			str_show.Format(_T("%d"), bottle_sum);
			SetDlgItemText(IDC_EDIT1, str_show);
			if (result_vec[i].obj_id == 0 && baise_lable == 1)                        //如果是第一个目标
			{

				baise_sum++;

				str_show.Format(_T("%d"), baise_sum);
				SetDlgItemText(IDC_EDIT3, str_show);

			}
			if (result_vec[i].obj_id == 1 && lanse_lable == 2)
			{

				lanse_sum++;

				str_show.Format(_T("%d"), lanse_sum);
				SetDlgItemText(IDC_EDIT3, str_show);

			}
			if (result_vec[i].obj_id == 2 && qianlan_lable == 3)
			{

				qianlan_sum++;
				str_show.Format(_T("%d"), qianlan_sum);
				SetDlgItemText(IDC_EDIT3, str_show);
			}
			if (result_vec[i].obj_id == 3 && lvse_lable == 4)
			{

				lvse_sum++;

				str_show.Format(_T("%d"), lvse_sum);
				SetDlgItemText(IDC_EDIT3, str_show);
			}
			if (result_vec[i].obj_id == 4 && qianlv_lable == 5)
			{

				qianlv_sum++;

				str_show.Format(_T("%d"), qianlv_sum);
				SetDlgItemText(IDC_EDIT3, str_show);

			}
			if (result_vec[i].obj_id == 5 && zongse_lable == 6)
			{

				zongse_sum++;

				str_show.Format(_T("%d"), zongse_sum);
				SetDlgItemText(IDC_EDIT3, str_show);
			}
			if (result_vec[i].obj_id == 6 && zise_lable == 7)
			{

				zise_sum++;

				str_show.Format(_T("%d"), zise_sum);
				SetDlgItemText(IDC_EDIT3, str_show);

			}

		}
		if (k == 0)     //有目标时，每帧都要先将vec0.at(idex2)清零后再将本帧质心保存，以免上次保存的信息的干扰
		{
			for (int vec_num = 0; vec_num < 10; vec_num++)
			{

				vec0.at(idex2).at(vec_num) = Point(0, 0);

			}
		}

		vec0.at(idex2).at(k) = Point(mc[i].x, mc[i].y);   //保存本帧质心坐标

		k++;
		if (k > 10)     //因为定义的vec大小为10,所以每帧图像最多只能有10个目标
		{
			MessageBox(_T("单帧图像中目标个数超过上限！！！"));
			break;
		}
	}

	//若该帧没有目标，则将vec0.at(idex2)清零
	if (k == 0)
	{
		for (int vec_num = 0; vec_num < 10; vec_num++)
		{

			vec0.at(idex2).at(vec_num) = Point(0, 0);

		}

	}

}

vector<string> EXE::objects_names_from_file(string const filename) {
	ifstream file(filename);
	vector<string> file_lines;
	if (!file.is_open()) return file_lines;
	for (string line; getline(file, line);) file_lines.push_back(line);

	return file_lines;
}


void EXE::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//capture.open(0);
	capture.open("E:/30fps.avi");


	if (!capture.isOpened())
	{
		MessageBox(_T("无法连接摄像头！！！"));
		return;
	}
	
}


void EXE::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	
	switch (nIDEvent)
	{
	case 1:
	{
		ifstream ifs(names_file.c_str());//初始化检测器
		string line;
		while (getline(ifs, line)) obj_names.push_back(line);
		capture >> image;  //读取当前image = frame;				   
		resize(image, image, Size(width, height));
		vector<bbox_t> result_vec = detector.detect(image);
		detector.detect(image);
		draw_boxes(image, result_vec, obj_names);
		show_console_result(result_vec, obj_names);
		imshow("MyPicture", image);
	}
	break;
	
	
	CDialogEx::OnTimer(nIDEvent);
	}
}


void EXE::OnBnClickedButton3()                      //开始检测
{
	// TODO: 在此添加控件通知处理程序代码

	if (!capture.isOpened())
	{
		MessageBox(_T("摄像头已关闭，无法捕捉图像！！！"));
		return;
	}
	if (!color_sel)                             //确保选择剔除颜色后才可以工作
	{
		MessageBox(_T("请选择剔除颜色，并重新点击开始工作按钮！！！"));
		return;
	}
	else
	{
		button = true;                         //开始工作，即开始图像处理过程
		button_stop = false;


		CString str;
		GetDlgItemTextW(IDC_EDIT2, str);

		CString str1(_T("白色_x"));
		CString str2(_T("蓝色_x"));
		CString str3(_T("浅蓝色_x"));
		CString str4(_T("绿色_x"));
		CString str5(_T("浅绿色_x"));
		CString str6(_T("棕色_x"));
		CString str7(_T("紫色_x"));

		if (str == str1)
		{
			//MessageBox(str1);    //该行代码连续执行会导致内存占有率迅速增加直至崩溃
			baise_lable = 1;
		}
		else if (str == str2)
			//MessageBox(str2);      //真正使用时，要将所有MessageBox语句全部换成分类模型
			lanse_lable = 2;
		else if (str == str3)
			//MessageBox(str3);
			qianlan_lable = 3;
		else if (str == str4)
			//MessageBox(str4);
			lvse_lable = 4;
		else if (str == str5)
			//MessageBox(str5);
			qianlv_lable = 5;
		else if (str == str6)
			//MessageBox(str6);
			zongse_lable = 6;
		else if (str == str7)
			//MessageBox(str7);
			zise_lable = 7;




	}
	SetTimer(1, 50, NULL); //定时器，定时时间和帧率一致
}


void EXE::OnBnClickedButton4()                        //停止工作
{
	// TODO: 在此添加控件通知处理程序代码

	if (!capture.isOpened())
	{
		MessageBox(_T("没有打开摄像头！！！"));
		return;
	}
	button = false;       //停止图像处理
	button_stop = true;   //视频停止播放

	KillTimer(1);
	capture.release();//释放资源
}


void EXE::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	bottle_sum = 0;
	CString str_show;
	str_show.Format(_T("%d"), 0);
	SetDlgItemText(IDC_EDIT1, str_show);
	SetDlgItemText(IDC_EDIT3, str_show);

	color_sel = true;     //表示已经选择过颜色

	int nSel_1;


	// 获取组合框控件的列表框中选中项的索引   
	nSel_1 = m_cbx.GetCurSel();
	// 根据选中项索引获取该项字符串   
	m_cbx.GetLBText(nSel_1, col_sel);

	SetDlgItemText(IDC_EDIT2, col_sel);
}


void EXE::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}
