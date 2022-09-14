#include "gtest/gtest.h"

#include "cpp/0733_flood_fill.hpp"

namespace {

class FloodFillTest : public ::testing::Test {
  void SetUp() override {}
};

TEST_F(FloodFillTest, DISABLED_3x3Image_ThenFlooded) {
  Matrix input_img{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  Matrix expected_img{{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
  int sr{1}, sc{1}, new_color{2};

  flood_fill::Solution sol{};
  auto res = sol.floodFill(input_img, sr, sc, new_color);

  for (size_t i{0}; i < expected_img.size(); ++i) {
    ASSERT_EQ(res[i], expected_img[i]);
  }
}

TEST_F(FloodFillTest, WrongImageDimensions_ThenNotFlooded) {
  Matrix input_img{std::vector<std::vector<int>>({std::vector<int>(51, 1)})};
  Matrix expected_img = input_img;
  int sr{1}, sc{1}, new_color{2};

  flood_fill::Solution sol{};
  auto res = sol.floodFill(input_img, sr, sc, new_color);

  for (size_t i{0}; i < expected_img.size(); ++i) {
    ASSERT_EQ(res[i], expected_img[i]);
  }
}

TEST_F(FloodFillTest, WrongStartingPixel_ThenNotFlooded) {
  Matrix input_img{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  Matrix expected_img = input_img;
  int sr{12}, sc{1}, new_color{2};

  flood_fill::Solution sol{};
  auto res = sol.floodFill(input_img, sr, sc, new_color);

  for (size_t i{0}; i < expected_img.size(); ++i) {
    ASSERT_EQ(res[i], expected_img[i]);
  }
}

TEST_F(FloodFillTest, WrongPixelInTheImage_ThenNotFlooded) {
  Matrix input_img{{1, 1, 1}, {1, 1, 0}, {1, 65535 + 1, 1}};
  Matrix expected_img = input_img;
  int sr{1}, sc{1}, new_color{2};

  flood_fill::Solution sol{};
  auto res = sol.floodFill(input_img, sr, sc, new_color);

  for (size_t i{0}; i < expected_img.size(); ++i) {
    ASSERT_EQ(res[i], expected_img[i]);
  }
}

}  // namespace
