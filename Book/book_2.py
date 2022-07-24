import sys
input = sys.stdin.readline

arr = input()


numbers = []

for ar in arr:
    numbers.append(ar)
    
numbers.pop(-1)
print(numbers)    
