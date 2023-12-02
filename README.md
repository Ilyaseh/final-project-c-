## CIFAR-10 Augment and Predict
Augmented CIFAR-10 dataset with OpenCV in C++, trained a CNN model in Python using Tensorflow, and used Frugally_Deep in C++ for predictions on new data.

## Developers:
- Ilyas el Haroui
  - GitHub Page: [https://github.com/Ilyaseh](https://github.com/Ilyaseh)
- Alan Zhang
  - GitHub Page: [https://github.com/alanZhang0813](https://github.com/alanZhang0813)


## Table of Contents
1. [Introduction](#introduction)
2. [Workflow](#workflow)
3. [Requirements and Installation](#requirements-and-installation)
   
## Introduction <a name="introduction"></a>
This project demonstrates the integration of C++ and Python in creating and utilizing a Convolutional Neural Network (CNN) for image classification. 
It involves data augmentation of the CIFAR-10 dataset using OpenCV in C++, building a CNN model in Python using Tensorflow, and employing the Frugally_Deep library in C++ for model predictions.

## Workflow <a name="workflow"></a>
1. **Data Augmentation with OpenCV in C++**: 
   - Augment the CIFAR-10 dataset to counter overfitting.
   - Image transformations include:
     - 1.1. **Random Cropping**: Altering image boundaries.
     - 1.2. **Scaling**: Resizing images.
     - 1.3. **Flipping**: Mirroring images horizontally or vertically.
     - 1.4. **Gaussian Noise**: Adding random pixel noise.
     - 1.5. **Color Jittering**: Varying brightness, contrast, and saturation.

2. **CNN Model Creation in Python**:
   - Develop the CNN model using Tensorflow in Python.
   - Train the model on the augmented dataset.

3. **Model Inference with Frugally_Deep in C++**:
   - Export the trained CNN model from Python to C++ using Frugally_Deep.
   - Use the Frugally_Deep library to perform a forward pass with the data and predict outcomes.

## Requirements and Installation <a name="requirements-and-installation"></a>
- C++17 compatible compiler.
- OpenCV (https://github.com/opencv/opencv).
- Python with Tensorflow installed.
- Frugally_Deep library.
