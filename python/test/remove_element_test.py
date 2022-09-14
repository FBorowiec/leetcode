import unittest
from typing import List

from python.remove_element import Solution


class RemoveElementTest(unittest.TestCase):
    def test_remove_element_1(self):
        nums = [3, 2, 2, 3]
        val = 3
        expected_output = [2, 2]

        output: int = Solution.removeElement(nums, val)

        nums.sort()

        self.assertEqual(output, len(expected_output))
        self.assertEqual(nums, expected_output)

    def test_remove_element_2(self):
        nums = [0, 1, 2, 2, 3, 0, 4, 2]
        val = 2
        expected_output = [0, 0, 1, 3, 4]

        output: List[int] = Solution.removeElement(nums, val)

        nums.sort()

        self.assertEqual(output, len(expected_output))
        self.assertEqual(nums, expected_output)
