def nearest_power_of_base(n: float, base: float = 10):
    power = 1
    count = 0

    while n >= base:
        n /= base
        power *= base
        count += 1

    return power, count


def approximate_log(x: float, base: float = 10.0, precision: int = 50):
    ans = 0

    for current_precision in range(1, precision + 1):
        if x == 1:
            break

        p, n = nearest_power_of_base(x, base)
        ans += n * 10 ** (precision - current_precision + 1)

        x /= p
        x **= 10

    return ans / 10 ** precision
