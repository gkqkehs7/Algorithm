import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

lis = [arr[0]]

def find(target):
    start = 0
    end = len(lis) - 1
    
    while start <= end:
        mid = (start+end) // 2
        
        if target == lis[mid]:
            return mid
        elif target < lis[mid]:
            end = mid -1
        elif target > lis[mid]:
            start = mid + 1
    
    return start

    
for item in arr:
    if item > lis[-1]:
        lis.append(item)
    else:
        lis[find(item)] = item
        
        
print(len(lis))