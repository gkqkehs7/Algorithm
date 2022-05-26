pin = list(map(int, input().split()))

n = pin[0]
m = pin[1]
d = [0] * 10001

nums = []

minum = 0;
for i in range(n):
    num = int(input())
    d[num] = 1;
    nums.append(num)
    
    if i == 0:
        minum = num
    else:
        minum = min(minum, num)
        
for j in range(minum, m+1):
    
    mini = 10001;
    for num in nums:
        if j-num >= 0:
            if d[j-num] != 0:
                mini = min(mini, d[j-num]) 
    
    
    d[j] = mini + 1;

