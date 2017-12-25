#include "LBPfeature.h"

LBPfeature::LBPfeature(const Mat& src, Mat &dst, LBPtype LBP_type, int _radius)
{
	high = src.rows;
	width = src.cols;
	radius = _radius;
	if (LBP_type == Normal)
		LBP_Normal(src,dst);
	else if (LBP_type == Circle)
		LBP_Circle(src, dst, radius);
	else if (LBP_type == Uniform)
		LBP_Uniform(src, dst, radius);
}

void LBPfeature::LBP_Normal(const Mat& src, Mat &dst)
{
	Mat imageROI,ROI;
	uchar tt;

	for (int i = 1; i < high-1; i++)
	{
		const uchar* data = src.ptr<uchar>(i);

		for (int j = 1; j < width-1; j++)
		{
			imageROI = src(Range(i - 1, i + 2), Range(j - 1, j + 2));
			threshold(imageROI, ROI, data[j], 1, THRESH_BINARY);
			dst.at<uchar>(i, j) = bit_covert_uchar(ROI);
		}
	}
}

void LBPfeature::LBP_Circle(const Mat& src, Mat &dst, int _radius) 
{
}

void LBPfeature::LBP_Uniform(const Mat& src, Mat &dst, int _radius) 
{
}

uchar LBPfeature::bit_covert_uchar(const Mat&bitarray)
{
	uchar tt = 0;
	Mat bit_array = bitarray.reshape(0, 1);
	int center_point = ((radius * 2 + 1)*(radius * 2 + 1) - 1)/2 ;
	for (int k = 0; k < bit_array.cols; k++)
	{
		if (k != center_point)
		{
			const uchar *data = bit_array.ptr<uchar>(0);
			if (data[k] == 0)
				tt = (tt << 1);
			else if (data[k] == 1)
				tt = (tt << 1) + 1;
		}
	}
	return tt;
}

LBPfeature::~LBPfeature()
{
}
