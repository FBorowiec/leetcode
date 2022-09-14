package palindrome_number

import (
	"strconv"
)

/*
 * Given an integer x, return true if x is palindrome integer.
 * An integer is a palindrome when it reads the same backward as forward.
 *     For example, 121 is a palindrome while 123 is not.
 * Constraint
 *     -231 <= x <= 231 - 1
 */
func isPalindrome(x int) bool {
	x_str := strconv.Itoa(x)
	x_len := len(x_str)

	for i := 0; i < x_len/2; i++ {
		if x_str[i] != x_str[x_len-i-1] {
			return false
		}
	}

	return true
}
