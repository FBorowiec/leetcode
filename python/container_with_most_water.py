from typing import List


class Solution:
    @staticmethod
    def maxArea(height: List[int]) -> int:
        """
        Exercise 0011.

        You are given an integer array height of length n.
        There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
        Find two lines that together with the x-axis form a container, such that the container contains the most water.
        Return the maximum amount of water a container can store.
        Notice that you may not slant the container.

        Constraints:
            n == height.length
            2 <= n <= 105
            0 <= height[i] <= 104
        """
        max_area: int = 0
        left: int = 0
        right: int = len(height) - 1

        while left < right:
            distance = right - left
            max_area = max(max_area, min(height[left], height[right]) * distance)
            if height[left] <= height[right]:
                left += 1
            else:
                right -= 1

        return max_area
