import random
import math

target = 600851475143




def is_prime(n, k=5):
    """Miller-Rabin primality test."""
    if n <= 1:
        return False
    elif n <= 3:
        return True
    elif n % 2 == 0:
        return False

    d = n - 1
    s = 0
    while d % 2 == 0:
        d //= 2
        s += 1
    
    for _ in range(k):
        a = random.randint(2, n - 2)
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        for __ in range(s - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

def pollards_rho(n):
    """Pollard's Rho factorization algorithm."""
    if n % 2 == 0:
        return 2
    if n % 3 == 0:
        return 3
    if n % 5 == 0:
        return 5
    
    while True:
        c = random.randint(2, n - 1)
        f = lambda x: (pow(x, 2, n) + c) % n
        x, y, d = 2, 2, 1
        
        while d == 1:
            x = f(x)
            y = f(f(y))
            d = math.gcd(abs(x - y), n)
        
        if d != n:
            return d

def factor(n):
    """Recursive factorization using Pollard's Rho."""
    factors = []
    def _factor(n):
        if n == 1:
            return
        if is_prime(n):
            factors.append(n)
            return
        d = pollards_rho(n)
        _factor(d)
        _factor(n // d)
    _factor(n)
    return sorted(factors)

# Example usage
n = 600851475143
print(f"Prime factors of {n}: {factor(n)}")