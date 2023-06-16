#!/usr/bin/python3
def is_palindrome(num):
    # Convert number to string and check if it reads the same forwards and backwards
    return str(num) == str(num)[::-1]

def find_largest_palindrome():
    largest_palindrome = 0

    for i in range(100, 1000):
        for j in range(100, 1000):
            product = i * j
            if is_palindrome(product) and product > largest_palindrome:
                largest_palindrome = product

    return largest_palindrome

# Find the largest palindrome
largest_palindrome = find_largest_palindrome()
print("Largest palindrome:", largest_palindrome)
