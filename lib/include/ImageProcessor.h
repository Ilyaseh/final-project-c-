//
// Created by ilyas on 12/2/2023.
//

#ifndef AUGMENTIMAGES_IMAGEPROCESSOR_H
#define AUGMENTIMAGES_IMAGEPROCESSOR_H

#include <string>

class ImageProcessor {
public:
    void processImagesInDirectory(const std::string& inputDir, const std::string& outputDir);
};

#endif //AUGMENTIMAGES_IMAGEPROCESSOR_H
