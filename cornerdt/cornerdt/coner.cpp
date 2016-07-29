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
	//printf("\n我是李斌");
	/*IplImage* image = cvLoadImage("E:\\大三下\\g.jpg",-1);
	cvNamedWindow("image",1); //创建显示窗口
	cvShowImage("image", image);
	cvWaitKey(0);

	cvReleaseImage(&image);//释放图像内存
	cvDestroyWindow("image");//销毁窗口资源

	return 0;*/
	Mat libingray;// = imread("E:\\大三下\\g.jpg", 0);;
	Mat libin = imread("E:\\大三下\\g.jpg");
	Mat cornerStrength, dstImage;
	namedWindow("image", CV_WINDOW_NORMAL);
	namedWindow("imagegray", CV_WINDOW_NORMAL);
	namedWindow("imagegray_cor", CV_WINDOW_NORMAL);
	imshow("image",libin);

	cvtColor(libin, libingray, CV_BGR2GRAY);//彩色图像变为灰度图像
	imshow("imagegray",libingray);
	//调用harris角点检测
	cornerHarris(libingray, cornerStrength, 2, 3, 0.01);
	//阈值操作，得到二值化图像
	threshold(cornerStrength, dstImage, 0.00001, 255, THRESH_BINARY);
	imshow("imagegray_cor", dstImage);
	waitKey();
	return 0;


}