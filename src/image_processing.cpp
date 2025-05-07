#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>
#include <filesystem>
#include <algorithm>
#include "image_processing.hpp"


void convertToGrayscale(const std::vector<std::vector<std::array<int, 3>>>& rgbImage,
                        std::vector<std::vector<int>>& grayscaleImage,
                        int rows, int cols,
                        GrayscaleMethod method) {
    grayscaleImage.resize(rows, std::vector<int>(cols, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int R = rgbImage[i][j][0];
            int G = rgbImage[i][j][1];
            int B = rgbImage[i][j][2];
            int gray = 0;
            switch (method) {
                case GrayscaleMethod::Lightness:
                    gray = (std::max({R, G, B}) + std::min({R, G, B})) / 2;
                    break;
                case GrayscaleMethod::Average:
                    gray = (R + G + B) / 3;
                    break;
                case GrayscaleMethod::Luminosity:
                    gray = static_cast<int>(0.21 * R + 0.72 * G + 0.07 * B);
                    break;
                case GrayscaleMethod::Desaturation:
                    gray = (std::max({R, G, B}) + std::min({R, G, B})) / 2;
                    break;
                case GrayscaleMethod::RedChannel:
                    gray = R;
                    break;
                case GrayscaleMethod::GreenChannel:
                    gray = G;
                    break;
                case GrayscaleMethod::BlueChannel:
                    gray = B;
                    break;
            }
            grayscaleImage[i][j] = gray;
        }
    }
}


