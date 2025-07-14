def sum_multiples(k, N):
    """Returns the sum of multiples of k below N."""
    m = (N - 1) // k
    return k * m * (m + 1) // 2


N = 1000
print(sum_multiples(3, N) + sum_multiples(5, N) - sum_multiples(15, N))
