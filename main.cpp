#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "ProcessImage.h"

namespace fs = std::filesystem;

int main() {
    std::string baseInputDir = "../CIFAR-10-images";
    std::string baseOutputDir = "../Processed-CIFAR-10-images";
    std::vector<std::string> subDirs = {"test", "train"};

    for (const auto& subDir : subDirs) {
        std::string inputSubDir = baseInputDir + "/" + subDir;
        std::string outputSubDir = baseOutputDir + "/" + subDir;

        // Iterate over all files in the subdirectory
        for (const auto& entry : fs::recursive_directory_iterator(inputSubDir)) {
            if (entry.is_regular_file() && entry.path().extension() == ".jpg") {
                std::string inputPath = entry.path().string();

                // Construct the output path
                fs::path relativePath = fs::relative(entry.path(), inputSubDir);
                std::string outputPath = outputSubDir + "/" + relativePath.string();

                // Ensure the specific output directory exists (including subclass folders)
                fs::create_directories(outputPath.substr(0, outputPath.find_last_of('/')));

                ProcessImage::processAndSaveImage(inputPath, outputPath);
            }
        }
    }

    return 0;
}
