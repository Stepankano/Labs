package main

import "fmt"

func fmts(x int) {
	fmt.Print(x, "\n")
}

func main() {
	for i := 0; i < 100000; i++ {
		go fmts(i)
	}
}
