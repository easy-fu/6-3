#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("C:/Users/DELL/Desktop/0.jpg", 1);
	if (srcMat.empty()) return-1;
	const cv::Point2f pt1[] = {
								   cv::Point2f(150,150),
								   cv::Point2f(150,300),
								   cv::Point2f(350,300),
								   cv::Point2f(350,150),
	};
	const cv::Point2f pt2[] = {
								   cv::Point2f(200,150),
								   cv::Point2f(200,300),
								   cv::Point2f(340,270),
								   cv::Point2f(340,180),
	};
      cv::Mat perspective_matrix = cv::getPerspectiveTransform(pt1, pt2);
	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());
	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);
}