def largest_palindrome_product(n):
    if n < 1:
        return 0
    
    max_num = 10**n - 1  # Largest n-digit number (e.g., 999 for n=3)
    min_num = 10**(n - 1)  # Smallest n-digit number (e.g., 100 for n=3)
    max_palindrome = 0
    
    for i in range(max_num, min_num - 1, -1):
        if i * max_num < max_palindrome:
            break
        
        for j in range(max_num, i - 1, -1):
            product = i * j
            if product <= max_palindrome:
                break  
            
            if str(product) == str(product)[::-1]:  
                max_palindrome = product
    
    return max_palindrome if max_palindrome != 0 else None

n = 3
result = largest_palindrome_product(n)
print(f"Largest palindrome product of two {n}-digit numbers: {result}")