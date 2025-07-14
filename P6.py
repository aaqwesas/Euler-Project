start = 1
end = 100


a = end * (end + 1) * (2 * end + 1) // 6

square_of_sum = end * (start + end) // 2


b = pow(square_of_sum, 2)


result = b - a

print(result)
