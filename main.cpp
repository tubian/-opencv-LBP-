#include<opencv2/opencv.hpp>
#include"LBPfeature.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

int main()
{
	Mat img = cv::imread("C:/Users/HUA/Desktop/data/att_faces/s1/1.pgm", IMREAD_GRAYSCALE);
	Mat img2 = cv::imread("C:/Users/HUA/Desktop/data/shape_sample/pip.bmp", IMREAD_GRAYSCALE);
	namedWindow("image");
	imshow("image", img);
	int radius;
	radius = 1;
	Mat dst=Mat::zeros(img.rows,img.cols,CV_8UC1);

	LBPfeature lbp(img,dst,Normal);
	imshow("dst", dst);

	while (1)
		cv::waitKey(0);
}