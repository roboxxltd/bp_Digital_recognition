#include "number.hpp"

namespace number
{
    Detector::Detector(int num) {
        char img_;
        char img_name[50];
        for (int i = 1; i < num; ++i){
            std::sprintf(img_name, "/home/xx/code/number/number_img/%d.png", i);
            cv::Mat src_img = cv::imread(img_name);
            cv::Mat gray_img, thre_img;
            cv::cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);
            cv::threshold(gray_img, thre_img, 80, 255, cv::THRESH_BINARY);
            src_img_[i] = thre_img.clone();
        }
    }
    Detector::Detector() {}
    Detector::~Detector() {}

    int Detector::detectionNum(cv::Mat _src_img, int _armor_type) {
        cv::Mat gray_img, thre_img;
        if (_armor_type) {
            cv::Rect roi = cv::Rect(_src_img.cols * 0.25, 0, _src_img.cols * 0.5, _src_img.rows);
            _src_img = _src_img(roi);
        }
        cv::resize(_src_img, _src_img, cv::Size(src_img_[1].cols, src_img_[1].rows));
        cv::cvtColor(_src_img, gray_img, cv::COLOR_BGR2GRAY);
        cv::threshold(gray_img, thre_img, 80, 255, cv::THRESH_BINARY);
        int min = src_img_[1].cols * src_img_[1].rows;
        int num = 0;
        for (int i = 1; i < sizeof(src_img_) / sizeof(cv::Mat); ++i) {
            cv::Mat final_img;
            cv::absdiff(src_img_[i], thre_img, final_img);
            std::vector<std::vector<cv::Point>> contours;
            std::vector<cv::Vec4i> hierarchys;
            cv::findContours(final_img, contours, hierarchys, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE);
            
            int area = 0;
            for (size_t j = 0; j < contours.size(); ++j) {
                area += cv::contourArea(contours[j]);
            }
            
            if (area < min) {
                min = area;
                num = i;
            }
        }
        return num;
    }
} // namespace number
