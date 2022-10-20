import unittest
from typing import List

from python.find_original_array_from_doubled_array import Solution


class ContainerWithMostWaterTest(unittest.TestCase):
    def test_find_original_array_1(self):
        input: List[int] = [1, 3, 4, 2, 6, 8]
        expected_output = [1, 3, 4]

        output: int = Solution.findOriginalArray(input)

        self.assertEqual(output, expected_output)

    def test_find_original_array_2(self):
        input: List[int] = [6, 3, 0, 1]
        expected_output = []

        output: int = Solution.findOriginalArray(input)

        self.assertEqual(output, expected_output)

    def test_find_original_array_3(self):
        input: List[int] = [1]
        expected_output = []

        output: int = Solution.findOriginalArray(input)

        self.assertEqual(output, expected_output)

    def test_find_original_array_4(self):
        input: List[int] = [0]
        expected_output = []

        output: int = Solution.findOriginalArray(input)

        self.assertEqual(output, expected_output)

    def test_find_original_array_5(self):
        input: List[int] = [0, 0, 0, 0]
        expected_output = [0, 0]

        output: int = Solution.findOriginalArray(input)

        self.assertEqual(output, expected_output)

    def test_find_original_array_6(self):
        input: List[int] = [0, 3, 2, 4, 6, 0]
        expected_output = [0, 2, 3]

        output: int = Solution.findOriginalArray(input)

        self.assertEqual(output, expected_output)
