#include<opencv2/opencv.hpp>  
#include<iostream>  
#include<vector>  
#include<string>  
#include <windows.h>
#include"contrib.hpp"

using namespace std;
using namespace cv;


int main()
{
	Directory dir;

	string path1 = "D:\\1";
	string  exten1 = "*.png";

	vector<string> filenames = dir.GetListFiles(path1, exten1, false);

	int size = filenames.size();

	for (int i = 0; i < size; i++)
	{
		cout << filenames[i] << endl;
	}
	system("pause");
	return 0;
}