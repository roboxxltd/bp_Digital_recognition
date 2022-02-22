#pragma once
#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

namespace number
{
    class Detector
    {
    private:
        cv::Mat src_img_[8];
    public:
        int detectionNum(cv::Mat _src_img, int _armor_type);
        Detector(int num);
        Detector();
        ~Detector();
    };
    
    
        
} // namespace number
