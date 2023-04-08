package main

import "fmt"

var (
	// 括号映射表
	brackets = map[string]string{
		")": "(",
		"]": "[",
		"}": "{",
	}
	// 左括号集合
	leftBrackets = map[string]bool{
		"(": true,
		"[": true,
		"{": true,
	}
	// 右括号集合
	rightBrackets = map[string]bool{
		")": true,
		"]": true,
		"}": true,
	}
)

func isValid(s string) bool {
	if len(s) == 0 {
		return true
	}
	stack := make([]string, 0, len(s))
	for ch := range s {
		if leftBrackets[string(s[ch])] {
			stack = append(stack, string(s[ch]))
		} else if rightBrackets[string(s[ch])] {
			if len(stack) == 0 {
				return false
			}
			if brackets[string(s[ch])] != stack[len(stack)-1] {
				return false
			}
			stack = stack[:len(stack)-1]
		} else {
			return false
		}
	}
	return len(stack) == 0
}

func main() {
	if isValid("(]") {
		fmt.Println("true")
	} else {
		fmt.Println("false")
	}
}
