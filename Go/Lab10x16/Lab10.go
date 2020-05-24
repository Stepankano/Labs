package main

import "fmt"

func fibo(x int) int {
	if x < 0 {
		panic("Ti durachok")
	}
	if x == 0 {
		return 0
	} else {
		if x == 1 {
			return 1
		} else {
			return x * fibo(x-1)
		}
	}
}

func main() {
	var num int
	for {
		fmt.Scan(&num)
		fmt.Print(fibo(num), "\n")
	}
}
