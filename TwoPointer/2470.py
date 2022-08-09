import sys
input = sys.stdin.readline

n = int(input())

arr = list(map(int, input().split()))

arr.sort()
start = 0;
end = len(arr) - 1

min_target = 2000000000
mins = [arr[start], arr[end]]
while start < end:    
    temp = arr[start] + arr[end]
    
    if abs(temp) < abs(min_target):
        min_target = temp
        mins = [arr[start], arr[end]]
        
    if temp < 0:
        start += 1

    elif temp > 0:
        end -= 1

    elif temp == 0:
        break
    
print(*mins)