package main

import "fmt"

/**
 * Inspiration source :
 * https://www.youtube.com/watch?v=crBSPYJLjOE
 */
func sum(numbers ...int) int {
	result := 0

	n := len(numbers)

	for i := 0; i < n / 2; i++ {
		result += numbers[i] + numbers[n - (i + 1)]
	}

	if len(numbers) % 2 == 1 {
		result += numbers[n / 2]
	}

	return result
}

func main() {
	/**
	 * Test Cases
	 */
	
	arr1 := []int{1, 2, 3}

	var arr2 []int
	for i := 1; i <= 100; i++ {
		arr2 = append(arr2, i)
	}

	fmt.Println(sum(arr1...)) // Should be 6
	fmt.Println(sum(arr2...)) // Should be 5050
}