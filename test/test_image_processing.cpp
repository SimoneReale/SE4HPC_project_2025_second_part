#include "image_processing.hpp"
#include <gtest/gtest.h>

TEST(GrayscaleTest, RedChannelConversion) {
    std::vector<std::vector<std::array<int, 3>>> image = {{{255, 0, 0}}};
    std::vector<std::vector<int>> result;
    convertToGrayscale(image, result, 1, 1, GrayscaleMethod::RedChannel);
    EXPECT_EQ(result[0][0], 255); // Red channel only
}

TEST(GrayscaleTest, LuminosityConversion) {
    std::vector<std::vector<std::array<int, 3>>> image = {{{255, 255, 255}}};
    std::vector<std::vector<int>> result;
    convertToGrayscale(image, result, 1, 1, GrayscaleMethod::Luminosity);
    EXPECT_EQ(result[0][0], 255); // White pixel, should remain max gray
}

TEST(GrayscaleTest, AverageConversion) {
    std::vector<std::vector<std::array<int, 3>>> image = {{{30, 90, 150}}};
    std::vector<std::vector<int>> result;
    convertToGrayscale(image, result, 1, 1, GrayscaleMethod::Average);
    EXPECT_EQ(result[0][0], (30 + 90 + 150) / 3); // Arithmetic mean
}
