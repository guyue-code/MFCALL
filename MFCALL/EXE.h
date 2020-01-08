#pragma once
#include "afxwin.h"
#define OPENCV
#define GPU

// EXE 对话框

#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include "yolo_v2_class.hpp" //引用动态链接库中的头文件

using namespace std;
using namespace cv;



class EXE : public CDialogEx
{
	DECLARE_DYNAMIC(EXE)

public:
	EXE(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~EXE();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton3();

	void draw_boxes(Mat mat_img, vector<bbox_t> result_vec, vector<string> obj_names,
		int current_det_fps, int current_cap_fps);

	vector<string> objects_names_from_file(string const filename);
	void show_console_result(vector<bbox_t> const result_vec, vector<string> const obj_names, int frame_id = -1);


	
	afx_msg void OnBnClickedButton4();
	bool button;      //控制图像处理进行与否
	bool button_stop;   //控制视频播放与否
	bool color_sel;     //区分下拉框颜色选择
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_cbx;
	CString col_sel;
	vector<vector<Point>> vec0;    //用于保存两帧图像中质心坐标
	vector<Point> vec1, vec2;
	int last;
	int idex1, idex2;
	int baise_lable;     //白色标签
	int lanse_lable;      //蓝色标签
	int qianlan_lable;       //浅蓝色标签
	int lvse_lable;      //绿色标签
	int qianlv_lable;     //浅绿色标签
	int zongse_lable;     //棕色标签
	int zise_lable;       //紫色标签
	int baise_sum;        //白色透明总数
	int lanse_sum;         //蓝色总数
	int qianlan_sum;
	int lvse_sum;
	int qianlv_sum;
	int zongse_sum;
	int zise_sum;
	int bottle_sum;     //统计视频中饮料瓶总个数
	afx_msg void OnBnClickedButton5();
};
