package leetcode

import (
	"fmt"
	"testing"
)

func TestContainerWithMostWater(t *testing.T) {
	tests := []struct {
		input []int
		want  int
	}{
		{[]int{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49},
		{[]int{1, 1}, 1},
	}

	for i, tc := range tests {
		t.Run(fmt.Sprintf("maxArea=%d", i), func(t *testing.T) {
			got := maxArea(tc.input)
			if got != tc.want {
				t.Fatalf("got %v; want %v", got, tc.want)
			}
		})
	}
}
