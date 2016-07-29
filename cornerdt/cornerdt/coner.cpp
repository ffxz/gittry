//#include "stdafx.h"
#include "stdio.h"
#include "opencv2/opencv.hpp"

#include "cv.h"
#include "highgui.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;


int main()
{
	//printf("\n�������");
	/*IplImage* image = cvLoadImage("E:\\������\\g.jpg",-1);
	cvNamedWindow("image",1); //������ʾ����
	cvShowImage("image", image);
	cvWaitKey(0);

	cvReleaseImage(&image);//�ͷ�ͼ���ڴ�
	cvDestroyWindow("image");//���ٴ�����Դ

	return 0;*/
	Mat libingray;// = imread("E:\\������\\g.jpg", 0);;
	Mat libin = imread("E:\\������\\g.jpg");
	Mat cornerStrength, dstImage;
	namedWindow("image", CV_WINDOW_NORMAL);
	namedWindow("imagegray", CV_WINDOW_NORMAL);
	namedWindow("imagegray_cor", CV_WINDOW_NORMAL);
	imshow("image",libin);

	cvtColor(libin, libingray, CV_BGR2GRAY);//��ɫͼ���Ϊ�Ҷ�ͼ��
	imshow("imagegray",libingray);
	//����harris�ǵ���
	cornerHarris(libingray, cornerStrength, 2, 3, 0.01);
	//��ֵ�������õ���ֵ��ͼ��
	threshold(cornerStrength, dstImage, 0.00001, 255, THRESH_BINARY);
	imshow("imagegray_cor", dstImage);
	waitKey();
	return 0;


}