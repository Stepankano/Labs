package main

import (
	"fmt"
)

func counter() int {
	var af string
	var number int = 1
	for {
		fmt.Scan(&af)
		if af == " " || af == "\n" {
			return number
		} else {
			number += 1
		}
	}
	// works perfect with non-stop threads of data((((
	// else non-stop output(
}

func main() {
	var key string
	var (
		min    = 0
		number = 999999999
		junk   = 0
	)
	for {
		if key == " " || key == "\n" {
		} else {
			junk = counter()
			if junk == number {
				min += 1
			}
			if junk < number {
				min = 1
				number = junk
			}
		}

		fmt.Print(min, number)

	}
}
