#pragma once
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
enum LBPtype { Normal, Circle, Uniform };
class LBPfeature
{
private:
	int radius;
	/*int neighbor;
	LBPtype type;
	*/
	int high;
	int width;
public:
	LBPfeature(const Mat& src, Mat &dst,LBPtype LBP_type, int radius=1);
	void LBP_Normal(const Mat& src, Mat &dst);
	void LBP_Circle(const Mat& src, Mat &dst, int _radius);
	void LBP_Uniform(const Mat& src, Mat &dst, int _radius);
	uchar bit_covert_uchar(const Mat&bit_array);
	~LBPfeature();
};

