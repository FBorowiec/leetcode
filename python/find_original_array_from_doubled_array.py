from typing import List


class Solution:
    @staticmethod
    def findOriginalArray(changed: List[int]) -> List[int]:
        """
        Exercise 2007.

        An integer array original is transformed into a doubled array changed by appending
        twice the value of every element in original, and then randomly shuffling the resulting array.
        Given an array changed, return original if changed is a doubled array.
        If changed is not a doubled array, return an empty array.
        The elements in original may be returned in any order.

        Constraints:
            1 <= changed.length <= 105
            0 <= changed[i] <= 105
        """
        original: List[int] = []

        if len(changed) % 2 == 1:
            return []

        changed = sorted(changed)
        changed_without_zeros: List[int] = [x for x in changed if x != 0]
        num_of_zeroes: int = len(changed) - len(changed_without_zeros)

        for c in changed_without_zeros:
            if c * 2 in changed_without_zeros:
                original.append(c)
                changed_without_zeros.remove(2 * c)

        if num_of_zeroes % 2 == 0:
            for i in range(0, num_of_zeroes - 1, 2):
                original.append(0)

        if len(original) < len(changed) / 2:
            return []

        return sorted(original)
