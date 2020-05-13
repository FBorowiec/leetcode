/**
 * An image is represented by a 2-D array of integers,
 * each integer representing the pixel value of the image (from 0 to 65535).
 * Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill,
 * and a pixel value newColor, "flood fill" the image.
 *
 * To perform a "flood fill", consider the starting pixel,
 * plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel,
 * plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel),
 * and so on.
 *
 * Replace the color of all of the aforementioned pixels with the newColor.
 *
 * At the end, return the modified image.
 */
#include <vector>

using Matrix = std::vector<std::vector<int>>;

namespace flood_fill
{

class Solution {
public:
  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor)
  {
    if ((image.size()<1 || image.size()>50) || (image[0].size()<1 || image[0].size()>50)) return image;
    if ((sr > image.size() || sr < 0) || (sc > image[0].size() || sr < 0)) return image;

    for (int i{0}; i<image.size(); ++i)
    {
      for (int j{0}; j<image[i].size(); ++j)
      {
        if (image[i][j] > 65535 || image[i][j] < 0) return image;
      }
    }
    return {{0}};
  }
};

}  // namespace flood_fill

// TEST---------------------------------------------------------------------------------------------------------------|
#include "gtest/gtest.h"

namespace
{

class FloodFillTest : public ::testing::Test
{
  void SetUp() override
  {}
};

TEST_F(FloodFillTest, 3x3Image_ThenFlooded)
{
  Matrix input_img{{1,1,1}, {1,1,0}, {1,0,1}};
  Matrix expected_img{{2,2,2}, {2,2,0}, {2,0,1}};
  int sr{1}, sc{1}, new_color{2};

  flood_fill::Solution sol{};
  auto res = sol.floodFill(input_img, sr, sc, new_color);

  for(size_t i{0}; i<expected_img.size(); ++i)
  {
    ASSERT_EQ(res[i], expected_img[i]);
  }
}

TEST_F(FloodFillTest, WrongImageDimensions_ThenNotFlooded)
{
  Matrix input_img{std::vector<std::vector<int>>({std::vector<int>(51, 1)})};
  Matrix expected_img = input_img;
  int sr{1}, sc{1}, new_color{2};

  flood_fill::Solution sol{};
  auto res = sol.floodFill(input_img, sr, sc, new_color);

  for(size_t i{0}; i<expected_img.size(); ++i)
  {
    ASSERT_EQ(res[i], expected_img[i]);
  }
}

TEST_F(FloodFillTest, WrongStartingPixel_ThenNotFlooded)
{
  Matrix input_img{{1,1,1}, {1,1,0}, {1,0,1}};
  Matrix expected_img = input_img;
  int sr{12}, sc{1}, new_color{2};

  flood_fill::Solution sol{};
  auto res = sol.floodFill(input_img, sr, sc, new_color);

  for(size_t i{0}; i<expected_img.size(); ++i)
  {
    ASSERT_EQ(res[i], expected_img[i]);
  }
}

TEST_F(FloodFillTest, WrongPixelInTheImage_ThenNotFlooded)
{
  Matrix input_img{{1,1,1}, {1,1,0}, {1,65535+1,1}};
  Matrix expected_img = input_img;
  int sr{1}, sc{1}, new_color{2};

  flood_fill::Solution sol{};
  auto res = sol.floodFill(input_img, sr, sc, new_color);

  for(size_t i{0}; i<expected_img.size(); ++i)
  {
    ASSERT_EQ(res[i], expected_img[i]);
  }
}

}  // namespace
