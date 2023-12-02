#include "AugmentImages.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <random>

// Main function to process and save the image
void AugmentImages::processAndSaveImage(const std::string& inputPath, const std::string& outputPath) {
    cv::Mat image = cv::imread(inputPath);
    if (image.empty()) {
        std::cerr << "Could not read the image at " << inputPath << std::endl;
        return;
    }

    // Random number generator for selecting augmentation and deciding if to augment
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> augmentDecision(0, 1);
    std::uniform_int_distribution<> augmentationType(0, 4);

    bool augmentImage = augmentDecision(gen) == 1;

    cv::Mat processedImage = image;

    // Apply a random augmentation to the image if augmentImage is true
    if (augmentImage) {
        int augmentation = augmentationType(gen);

        switch (augmentation) {
            case 0:
                processedImage = applyRandomCropping(image);
                break;
            case 1:
                processedImage = applyScaling(image);
                break;
            case 2:
                processedImage = applyFlipping(image);
                break;
            case 3:
                processedImage = applyGaussianNoise(image);
                break;
            case 4:
                processedImage = applyColorJittering(image);
                break;
            default:
                processedImage = image;
                break;
        }
    }

    if (!cv::imwrite(outputPath, processedImage)) {
        std::cerr << "Failed to save the image at " << outputPath << std::endl;
    }
}

// Applies random cropping to the image
cv::Mat AugmentImages::applyRandomCropping(const cv::Mat& image) {
    int cropWidth = image.cols / 2;
    int cropHeight = image.rows / 2;

    // Generate random starting points
    int x = rand() % (image.cols - cropWidth);
    int y = rand() % (image.rows - cropHeight);

    cv::Rect roi(x, y, cropWidth, cropHeight);

    // Crop and return the image
    return image(roi);
}

// Applies scaling to the image
cv::Mat AugmentImages::applyScaling(const cv::Mat& image) {
    cv::Mat scaledImage;
    cv::resize(image, scaledImage, cv::Size(), 2, 2);
    return scaledImage;
}

// Applies flipping to the image along the horizontal axis
cv::Mat AugmentImages::applyFlipping(const cv::Mat& image) {
    cv::Mat flippedImage;
    cv::flip(image, flippedImage, 1);
    return flippedImage;
}

// Applies Gaussian noise to the image
cv::Mat AugmentImages::applyGaussianNoise(const cv::Mat& image) {
    cv::Mat noise(image.size(), image.type());
    cv::randn(noise, 0, 25);
    cv::Mat noisyImage;
    cv::add(image, noise, noisyImage);
    return noisyImage;
}

// Applies color jittering to the image
cv::Mat AugmentImages::applyColorJittering(const cv::Mat& image) {
    cv::Mat jitteredImage = image.clone();

    // Adjust brightness and contrast randomly up to 50% higher
    float contrastFactor = 1.0f + static_cast<float>(rand()) / RAND_MAX * 0.5f; // 1.0 to 1.5
    float brightnessFactor = static_cast<float>(rand()) / RAND_MAX * 50; // 0 to 50
    jitteredImage.convertTo(jitteredImage, -1, contrastFactor, brightnessFactor);

    // Adjust saturation
    cv::Mat hsvImage;

    // Convert BGR to HSV color space
    cv::cvtColor(jitteredImage, hsvImage, cv::COLOR_BGR2HSV);
    std::vector<cv::Mat> hsvChannels;
    cv::split(hsvImage, hsvChannels);

    // Generate a random factor to adjust the saturation (making it 0% to 50% more intense)
    float saturationFactor = 1.0f + static_cast<float>(rand()) / RAND_MAX * 0.5f;

    // Apply the saturation factor to the saturation channel (enhancing or reducing color intensity)
    hsvChannels[1] *= saturationFactor;
    cv::merge(hsvChannels, hsvImage);

    // Convert the HSV image back to the BGR color space for further processing/display
    cv::cvtColor(hsvImage, jitteredImage, cv::COLOR_HSV2BGR);

    return jitteredImage;
}

