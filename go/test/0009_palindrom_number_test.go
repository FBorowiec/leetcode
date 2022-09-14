package palindrome_number

import (
	"fmt"
	"testing"
)

func TestIsPalindrome(t *testing.T) {
	tests := []struct {
		input int
		want  bool
	}{
		{1, true},
		{121, true},
		{123, false},
		{-121, false},
		{10, false},
		{1234554321, true},
	}

	for i, tc := range tests {
		t.Run(fmt.Sprintf("isPalindrome=%d", i), func(t *testing.T) {
			got := isPalindrome(tc.input)
			if got != tc.want {
				t.Fatalf("got %v; want %v", got, tc.want)
			}
		})
	}
}
