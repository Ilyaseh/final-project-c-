#ifndef AUGMENTIMAGES_AUGMENTIMAGES_H
#define AUGMENTIMAGES_AUGMENTIMAGES_H

#include <string>
#include <opencv2/opencv.hpp>

class AugmentImages {
public:
    static void processAndSaveImage(const std::string& inputPath, const std::string& outputPath);

private:
    static cv::Mat applyRandomCropping(const cv::Mat& image);
    static cv::Mat applyScaling(const cv::Mat& image);
    static cv::Mat applyFlipping(const cv::Mat& image);
    static cv::Mat applyGaussianNoise(const cv::Mat& image);
    static cv::Mat applyColorJittering(const cv::Mat& image);
};

#endif //AUGMENTIMAGES_AUGMENTIMAGES_H
