import math


def lcm_range(n):
    return math.lcm(*range(1, n + 1))


print(lcm_range(20))
