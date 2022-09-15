from typing import List


class Solution:
    @staticmethod
    def partitionString(s: str) -> int:
        """
        Exercise 2405.

        Given a string s, partition the string into one or more substrings such
        that the characters in each substring are unique.
        That is, no letter appears in a single substring more than once.
        Return the minimum number of substrings in such a partition.
        Note that each character should belong to exactly one substring in a partition.

        Constraints:
            1 <= s.length <= 105
            s consists of only English lowercase letters.
        """
        partitions: List[str] = []
        new_partition: str = ""

        for c in s:
            if c not in new_partition:
                new_partition += c
            else:
                partitions.append(new_partition)
                new_partition = c
        partitions.append(new_partition)

        return len(partitions)
