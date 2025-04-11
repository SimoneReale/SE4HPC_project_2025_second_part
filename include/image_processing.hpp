#pragma once
#include <vector>
#include <array>

enum class GrayscaleMethod {
    Lightness,
    Average,
    Luminosity,
    Desaturation,
    RedChannel,
    GreenChannel,
    BlueChannel
};

void convertToGrayscale(const std::vector<std::vector<std::array<int, 3>>>& rgbImage,
                        std::vector<std::vector<int>>& grayscaleImage,
                        int rows, int cols,
                        GrayscaleMethod method);
