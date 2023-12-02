//
// Created by ilyas on 12/2/2023.
//

#include "ImageProcessor.h"
#include <filesystem>
#include "AugmentImages.h"

namespace fs = std::filesystem;

void ImageProcessor::processImagesInDirectory(const std::string& inputDir, const std::string& outputDir) {
    for (const auto& entry : fs::recursive_directory_iterator(inputDir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".jpg") {
            std::string inputPath = entry.path().string();

            fs::path relativePath = fs::relative(entry.path(), inputDir);
            std::string outputPath = outputDir + "/" + relativePath.string();

            fs::create_directories(outputPath.substr(0, outputPath.find_last_of('/')));

            AugmentImages::processAndSaveImage(inputPath, outputPath);
        }
    }
}
