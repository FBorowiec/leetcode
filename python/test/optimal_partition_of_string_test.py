import unittest

from python.optimal_partition_of_string import Solution


class OptimalPartitionOfStringTest(unittest.TestCase):
    def test_partition_string_1(self):
        input: str = "abacaba"
        expected_output: int = 4

        output: int = Solution.partitionString(input)

        self.assertEqual(output, expected_output)

    def test_partition_string_2(self):
        input: str = "ssssss"
        expected_output: int = 6

        output: int = Solution.partitionString(input)

        self.assertEqual(output, expected_output)

    def test_partition_string_3(self):
        input: str = "yzubfsiypfrepcfftiov"
        expected_output: int = 4

        output: int = Solution.partitionString(input)

        self.assertEqual(output, expected_output)
