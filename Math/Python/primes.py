def primes(n):
	isPrime = [True] * (n + 1)
	isPrime[0] = False
	isPrime[1] = False

	i = 2
	while i * i <= n:
		if isPrime[i]:
			for j in range(i * i, n + 1, i):
				isPrime[j] = False

		i += 1

	return isPrime


def is_prime(n):
	if n == 2:
		return True
	elif n & 1 == 0 or n < 2:
		return False

	d = 3
	while d * d <= n:
		if n % d == 0:
			return False
		d += 2

	return True

def miller_rabin(n):
    """works for n<~10^18"""
    if n < 5 or n & 1 == 0 or n % 3 == 0:
        return 2 <= n <= 3
    s = ((n - 1) & (1 - n)).bit_length() - 1
    d = n >> s
    for a in [2, 325, 9375, 28178, 450775, 9780504, 1795265022]:
        p = pow(a, d, n)
        if p == 1 or p == n - 1 or a % n == 0:
            continue
        for _ in range(s):
            p = (p * p) % n
            if p == n - 1:
                break
        else:
            return False
    return True


