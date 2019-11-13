#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main() {
	VideoCapture capture;
	capture.open("D:\\images\\1.mp4");

	if (!capture.isOpened())
	{
		cout << "fail to open video" << endl;
	}

	long nTotalFrame = capture.get(CV_CAP_PROP_FRAME_COUNT);
	cout << "nTotalFrame=" << nTotalFrame << endl;

	int frameHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
	int frameWidth = capture.get(CV_CAP_PROP_FRAME_COUNT);
	cout << "frameHeight=" << frameHeight << endl;
	cout << "frameWidth=" << frameWidth << endl;

	cv::Mat frameimg;
	long nCount = 1;
	while (true) {
		cout << "current frame:" << nCount << endl;
		capture >> frameimg;
		if (!frameimg.empty())
		{
			imshow("frameimg", frameimg);
		}
		else
		{
			break;
		}

		if (char(waitKey(1)) == 'q')
		{
			break;
		}
		nCount++;
	}

	capture.release();
	return 0;
}