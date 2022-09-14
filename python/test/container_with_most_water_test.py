import unittest
from typing import List

from python.container_with_most_water import Solution


class ContainerWithMostWaterTest(unittest.TestCase):
    def test_max_area_1(self):
        height: List[int] = [1, 8, 6, 2, 5, 4, 8, 3, 7]
        expected_output = 49

        output: int = Solution.maxArea(height)

        self.assertEqual(output, expected_output)

    def test_max_area_2(self):
        height: List[int] = [1, 1]
        expected_output = 1

        output: int = Solution.maxArea(height)

        self.assertEqual(output, expected_output)
