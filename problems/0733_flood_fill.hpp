//UNSOLVED!
#ifndef LEETCODE_PROBLEMS_0733_FLOOD_FILL_HPP
#define LEETCODE_PROBLEMS_0733_FLOOD_FILL_HPP

#include <vector>

using Matrix = std::vector<std::vector<int>>;

namespace flood_fill
{

class Solution {
public:
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
  std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int newColor)
  {
    if ((image.size()<1 || image.size()>50) || (image[0].size()<1 || image[0].size()>50)) return image;
    if ((sr > (int)image.size() || sr < 0) || (sc > (int)image[0].size() || sr < 0)) return image;

    for (unsigned int i{0}; i<image.size(); ++i)
    {
      for (unsigned int j{0}; j<image[i].size(); ++j)
      {
        if (image[i][j] > 65535 || image[i][j] < 0) return image;
      }
    }
    return {{0}};
  }
};

}  // namespace flood_fill

#endif  // LEETCODE_PROBLEMS_0733_FLOOD_FILL_HPP
