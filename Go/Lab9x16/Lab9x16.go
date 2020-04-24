package main //главный "вход" в прогу
import "fmt"

func min(x int, y int) int {
	if x >= y {
		return y
	} else {
		return x
	}
}

func max(x int, y int) int {
	if x >= y {
		return x
	} else {
		return y
	}
}

func module(x int) int {
	if x >= 0 {
		return x
	} else {
		return -x
	}
}

func mod(x int, y int) int {
	if x%y < 0 {
		return x%y + y
	} else {
		return x % y
	}
}

func check(x int, y int) bool { // в булл нет 1 и 0, only true и false
	if (x <= -y-10) && (x >= -y-20) {
		return true
	} else {
		return false
	}
}

func main() { // тут и так всё понятно

	// int, int16, int32, int64, uint16, uint32, uint64 - интегер и беззнаковый интегер
	// float32, float64 - флоат и дабл
	// complex64, complex128 - комплексные числа блеатт

	var (
		i = 0
		j = 0
		k = 0
		l = 0
	)
	var new_i, new_j, new_l int
	fmt.Scanln(&i, &j, &l)
	for k = 1; k < 50; k++ { // тута нет while и until, есть разные формы for

		new_i = module(i-l) + min(mod(j, 10), (l*mod(k, 10))) - 20
		new_j = mod(max((k-i), min(j, max(i-l, j-l))), 30)
		new_l = mod((l*l), 20) - mod(max(i, j), (k+1))

		if check(new_i, new_j) {
			fmt.Print("Hit, time = ", k, "\n\n")
			k = 55
		}

		i = new_i
		j = new_j
		l = new_l

	}
	if k == 51 {
		fmt.Print("Don`t hit, time =", 51, "\nx =", new_i, "\ny =", new_j, "\nDinamic parameter of moving =", new_l, "\n\n")
	}
}
