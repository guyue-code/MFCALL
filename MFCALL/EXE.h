#pragma once
#include "afxwin.h"
#define OPENCV
#define GPU

// EXE �Ի���

#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include "yolo_v2_class.hpp" //���ö�̬���ӿ��е�ͷ�ļ�

using namespace std;
using namespace cv;



class EXE : public CDialogEx
{
	DECLARE_DYNAMIC(EXE)

public:
	EXE(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~EXE();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
	bool button;      //����ͼ����������
	bool button_stop;   //������Ƶ�������
	bool color_sel;     //������������ɫѡ��
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox m_cbx;
	CString col_sel;
	vector<vector<Point>> vec0;    //���ڱ�����֡ͼ������������
	vector<Point> vec1, vec2;
	int last;
	int idex1, idex2;
	int baise_lable;     //��ɫ��ǩ
	int lanse_lable;      //��ɫ��ǩ
	int qianlan_lable;       //ǳ��ɫ��ǩ
	int lvse_lable;      //��ɫ��ǩ
	int qianlv_lable;     //ǳ��ɫ��ǩ
	int zongse_lable;     //��ɫ��ǩ
	int zise_lable;       //��ɫ��ǩ
	int baise_sum;        //��ɫ͸������
	int lanse_sum;         //��ɫ����
	int qianlan_sum;
	int lvse_sum;
	int qianlv_sum;
	int zongse_sum;
	int zise_sum;
	int bottle_sum;     //ͳ����Ƶ������ƿ�ܸ���
	afx_msg void OnBnClickedButton5();
};
