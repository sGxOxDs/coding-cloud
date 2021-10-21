#include <stdio.h>
#include <climits>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
//#include <opencv2\imgproc\types_c.h>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
	Mat srcImage = imread(argv[1]);
	Mat midImage, dstImage;

	Canny(srcImage, midImage, 500, 100); // 邊緣檢測
	
	vector<Vec4i> lines;
	HoughLinesP(midImage, lines, 1, CV_PI / 180, 250, 200, 10); //儲存線稿
	Vec4i l = lines[0];
	for (size_t i = 0; i < lines.size(); i++)
	{
		auto la = (l[0] - l[2]) * (l[0] - l[2]) + (l[1] - l[3]) * (l[1] - l[3]);
		auto lb = (lines[i][0] - lines[i][2]) * (lines[i][0] - lines[i][2]) + (lines[i][1] - lines[i][3]) * (lines[i][1] - lines[i][3]);
		if (lb > la)
			l = lines[i];
	}
	//line(dstImage, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 3, LINE_AA);
	
	double x = fabs(l[0] - l[2]), y = fabs(l[1] - l[3]);
	double rate = x/sqrt(x*x+y*y);

	Point2f pc(srcImage.cols / 2., srcImage.rows / 2.);
	Mat r = getRotationMatrix2D(pc, rate * 180 / CV_PI, 1.0);

	warpAffine(srcImage, dstImage, r, srcImage.size());

	imwrite(argv[2], dstImage);

	return 0;
}


