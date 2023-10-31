#include<iostream>
#include"opencv2/opencv.hpp"
#include <omp.h>

int main(){
    cv::Mat image=cv::imread("C:/Projects/Project_Image_to_greyscale/src/download.jpeg");
    if(image.empty()){
        std::cout<<"Error reading image"<<std::endl;
        return 1;
    }

    cv::Mat greyscaleImage(image.rows,image.cols,CV_8UC1);
    #pragma omp parallel for
    for(int i=0; i<greyscaleImage.rows;i++){
        for(int j=0;j<greyscaleImage.cols;j++){
            cv::Vec3b pixel=image.at<cv::Vec3b>(i,j);
            uchar grayvalue=static_cast<uchar>(0.299*pixel[2]+0.587*pixel[1]+0.114*pixel[0]);
            greyscaleImage.at<uchar>(i,j)=grayvalue;
        }
    }
    
    cv::Mat negativeImage(image.rows,image.cols,CV_8UC1);
    #pragma omp parallel for
    for(int i=0;i<negativeImage.rows;i++){
        for(int j=0;j<negativeImage.cols;j++){
            cv::Vec3b pixel=image.at<cv::Vec3b>(i,j);
            uchar negativePixel=static_cast<uchar>((255-pixel[2]),(255-pixel[1]),(255-pixel[0]));
            negativeImage.at<uchar>(i,j)=negativePixel;
        }
    }


    imwrite("negative.jpeg",negativeImage);
    imwrite("greyscale.jpeg",greyscaleImage);
    
    return 0;
}