#include <iostream>
#include <vector>
#include <string>
#include "ImageProcessor.h"

int main() {
    std::string baseInputDir = "../../../Downloads/CIFAR-10-images";
    std::string baseOutputDir = "../../../Downloads/Processed-CIFAR-10-images";
    std::vector<std::string> subDirs = {"test", "train"};
    ImageProcessor processor;

    for (const auto& subDir : subDirs) {
        std::string inputSubDir = baseInputDir + "/" + subDir;
        std::string outputSubDir = baseOutputDir + "/" + subDir;

        processor.processImagesInDirectory(inputSubDir, outputSubDir);
    }

    return 0;
}