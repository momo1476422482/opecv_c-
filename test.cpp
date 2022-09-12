#include <opencv2/opencv.hpp>
#include <iostream>
#include "test.h"

using namespace cv;
using namespace std;

/*Mat read_img(string input_path){
	Mat img=imread(input_path);
	return img;
}*/

//==============================================
Mat Rotate_image:: read_image(string input_path){
	Mat image=imread(input_path);
	return image;
}
//==================================================
float Rotate_image:: get_orientation(Mat image,Point p,int patch_size){
	//PCA pca(data, cv::Mat(), CV_PCA_DATA_AS_ROW, numOfComponents);
	Mat patch = image(Rect(p.x,p.y,15,15));
	Mat Sx;
	Sobel(patch, Sx, CV_32F, 1, 0, 3);

	Mat Sy;
	Sobel(patch, Sy, CV_32F, 0, 1, 3);

	Mat mag, ori;
	magnitude(Sx, Sy, mag);
	phase(Sx, Sy, ori, true);
	for(int i=0;i<=patch_size-1;i++){
		for(int j=0;j<=patch_size-1;j++){
			cout<<"ori"<<" " <<ori.at<float>(i,j);
		}
	}

	return 0.5;}
//=====================================
int main(int argc, char** argv)
{
 // Read the image file
    std::cout<<"hello";
    Mat image = imread("test.jpg");
    Rotate_image rim;
    Mat img=rim.read_image("test.jpg");
    rim.get_orientation(img,Point(150,300), 15);
   


/*
    Mat outimage;
    resize(image,outimage,Size(),0.75,0.75);
    //cout<<"image"<<image<<endl;
    imwrite("rrr.jpg",outimage);
    //Mat img2=read_img("test.jpg");*/
    return 0;

}
