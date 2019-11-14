#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
//#include"mouse.cpp"

using namespace cv;
using namespace std;

Mat srcImage;
Rect roiRect;
Point startPoint;
Point endPoint;
Point tempPoint;

bool downFlag = false;
bool upFlag = false;

void MouseEvent(int event, int x, int y, int flags, void* data) {

	if (event == EVENT_LBUTTONDOWN)
	{
		downFlag = true;
		startPoint.x = x;
		startPoint.y = y;
	}

	if (event == EVENT_LBUTTONUP)
	{
		upFlag = true;
		endPoint.x = x;
		endPoint.y = y;
	}

	if (downFlag == true && upFlag == false)
	{

		tempPoint.x = x;
		tempPoint.y = y;
	}

	//Mat tempImage = srcImage.clone();
	//rectangle(tempImage, startPoint, tempPoint, Scalar(255, 0, 0), 2, 3, 0);
	//imshow("Roi img", tempImage);

	if (downFlag == true && upFlag == true)
	{
		roiRect.width = abs(startPoint.x - endPoint.x);
		roiRect.height = abs(startPoint.y - endPoint.y);
		roiRect.x = min(startPoint.x, endPoint.x);
		roiRect.y = min(startPoint.y, endPoint.y);
		Mat roiMat(srcImage, roiRect);
		imshow("ROI", roiMat);
		downFlag = false;
		upFlag = false;

	}

	waitKey(0);

}



int main()
{
	srcImage = imread("D:\\1.jpg");
	if (!srcImage.data)
	{
		return -1;
	}
	imshow("original image", srcImage);
	setMouseCallback("original image", MouseEvent,0);
	
	waitKey(0);
  	return 0;
}