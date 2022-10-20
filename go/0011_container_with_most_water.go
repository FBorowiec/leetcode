package leetcode

import (
	"math"
)

func maxArea(height []int) int {
	max_area := 0
	left := 0
	right := len(height) - 1

	for left < right {
		distance := right - left
		max_area = int(math.Max(float64(max_area), math.Min(float64(height[left]), float64(height[right]*distance))))
		if height[left] <= height[right] {
			left++
		} else {
			right--
		}
	}

	return max_area
}
