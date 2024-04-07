#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src(100, 100, CV_8UC3, Scalar::all(255));

	imshow("OpenCV Demo", src);
	waitKey(0);

	return 0;
}
