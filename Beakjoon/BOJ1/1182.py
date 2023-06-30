from itertools import combinations

num, res = input().split()
num = int(num)
res = int(res)

arr = list(map(int, input().split()))
count = 0;

for i in range(num):
    temp = list(combinations(arr, i+1))
    for tem in temp:
        s = list(tem)
        if(sum(s) == res):
            count = count + 1;
print(count)

