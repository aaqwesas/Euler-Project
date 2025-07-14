def fibonacci_generator(n):
    a, b = 0, 1
    for _ in range(n):
        yield a
        a, b = b, a + b


count = 0
for i in fibonacci_generator(1000):
    if i > 4000000:
        break
    if i % 2 == 0:
        count += i


print(count)
