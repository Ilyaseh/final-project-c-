#ifndef AUGMENTIMAGES_PROCESSIMAGE_H
#define AUGMENTIMAGES_PROCESSIMAGE_H

#include <string>
#include <opencv2/opencv.hpp>

class ProcessImage {
public:
    static void processAndSaveImage(const std::string& inputPath, const std::string& outputPath);

private:
    static cv::Mat applyRandomCropping(const cv::Mat& image);
    static cv::Mat applyScaling(const cv::Mat& image);
    static cv::Mat applyFlipping(const cv::Mat& image);
    static cv::Mat applyGaussianNoise(const cv::Mat& image);
    static cv::Mat applyColorJittering(const cv::Mat& image);

};

#endif //AUGMENTIMAGES_PROCESSIMAGE_H
