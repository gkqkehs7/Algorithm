N = int(input())

num =[]*10000001

for _ in range(N) : 
    num.append(int(input()))
    
num.sort()

for data in num:
    print(data)
