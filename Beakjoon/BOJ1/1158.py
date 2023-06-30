N, K = input().split()

N = int(N)
K = int(K)
arr = [n+1 for n in range(N)]

res = []

cursor = 0

for n in range(N):
    if(len(arr) == 1):
        res.append(arr[0])
        break;
    cursor = cursor + K;
    while(cursor > len(arr)):
        cursor = cursor - len(arr)
    res.append(arr.pop(cursor-1))

    cursor = cursor -1;
    
print("<", end='')
print(*res, sep=', ', end='')
print(">")