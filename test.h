#ifndef TEST_H
#define TEST_H
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;


class Rotate_image{
	private :
		Mat image;
	public:
		Rotate_image(){};
		Mat read_image(string input_path);
		float get_orientation(Mat image,Point p,int patch_size);};
#endif
