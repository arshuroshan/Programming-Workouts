func smallestNumber(num string, t int64) string {
	target, ok := factorize(t)
	if !ok {
		return "-1"
	}

	required := minimizeFactors(target)
	if factorLength(required) > len(num) {
		return buildNumber(required)
	}

	current := factorString(num)
	firstZero := strings.IndexByte(num, '0')
	if firstZero < 0 {
		firstZero = len(num)
		if containsFactors(current, target) {
			return num
		}
	}

	for i := len(num) - 1; i >= 0; i-- {
		digit := int(num[i] - '0')
		current = removeFactors(current, digit)

		if i > firstZero {
			continue
		}

		remainingSlots := len(num) - i - 1

		for next := digit + 1; next <= 9; next++ {
			remaining := target
			remaining = removeCount(remaining, current)
			remaining = removeDigitFactors(remaining, next)

			factors := minimizeFactors(remaining)
			requiredSlots := factorLength(factors)

			if requiredSlots <= remainingSlots {
				ones := remainingSlots - requiredSlots
				return num[:i] +
					strconv.Itoa(next) +
					strings.Repeat("1", ones) +
					buildNumber(factors)
			}
		}
	}

	required = minimizeFactors(target)
	ones := len(num) + 1 - factorLength(required)

	return strings.Repeat("1", ones) + buildNumber(required)
}

type factorSet [4]int

var digitFactors = [10]factorSet{
	{},
	{},
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{2, 0, 0, 0},
	{0, 0, 1, 0},
	{1, 1, 0, 0},
	{0, 0, 0, 1},
	{3, 0, 0, 0},
	{0, 2, 0, 0},
}

var primes = [4]int{2, 3, 5, 7}

func factorize(t int64) (factorSet, bool) {
	var result factorSet

	for i, prime := range primes {
		for t%int64(prime) == 0 {
			t /= int64(prime)
			result[i]++
		}
	}

	return result, t == 1
}

func factorString(num string) factorSet {
	var result factorSet

	for _, char := range num {
		digit := int(char - '0')
		factors := digitFactors[digit]

		for i := 0; i < 4; i++ {
			result[i] += factors[i]
		}
	}

	return result
}

func minimizeFactors(f factorSet) [8]int {
	var result [8]int

	eights := f[0] / 3
	remaining2 := f[0] % 3

	nines := f[1] / 2
	remaining3 := f[1] % 2

	fours := remaining2 / 2
	twos := remaining2 % 2

	sixes := 0

	if twos == 1 && remaining3 == 1 {
		twos = 0
		remaining3 = 0
		sixes = 1
	}

	if remaining3 == 1 && fours == 1 {
		twos = 1
		sixes = 1
		remaining3 = 0
		fours = 0
	}

	result[0] = twos
	result[1] = remaining3
	result[2] = fours
	result[3] = f[2]
	result[4] = sixes
	result[5] = f[3]
	result[6] = eights
	result[7] = nines

	return result
}

func buildNumber(factors [8]int) string {
	var result strings.Builder

	for digit := 2; digit <= 9; digit++ {
		result.WriteString(
			strings.Repeat(strconv.Itoa(digit), factors[digit-2]),
		)
	}

	return result.String()
}

func factorLength(factors [8]int) int {
	total := 0

	for _, count := range factors {
		total += count
	}

	return total
}

func containsFactors(have, need factorSet) bool {
	for i := 0; i < 4; i++ {
		if have[i] < need[i] {
			return false
		}
	}

	return true
}

func removeFactors(f factorSet, digit int) factorSet {
	return removeDigitFactors(f, digit)
}

func removeDigitFactors(f factorSet, digit int) factorSet {
	result := f
	removed := digitFactors[digit]

	for i := 0; i < 4; i++ {
		result[i] -= removed[i]

		if result[i] < 0 {
			result[i] = 0
		}
	}

	return result
}

func removeCount(a, b factorSet) factorSet {
	result := a

	for i := 0; i < 4; i++ {
		result[i] -= b[i]

		if result[i] < 0 {
			result[i] = 0
		}
	}

	return result
}