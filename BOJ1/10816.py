import sys

N = int(sys.stdin.readline().rstrip())

arr = list(map(int, input().split() ))
arr.sort()

M = int(sys.stdin.readline().rstrip())
 
def binarySearch(array, target, start, end):
    if(start > end):
        return 0;
    mid = (start+end) //2
    if array[mid] == target:
        return target;
    elif array[mid] > target:
        return binarySearch(array, target, start, mid-1)
    else:
        return binarySearch(array, target, mid+1, end);

arr2 = list(map(int, input().split() ))

for data in arr2:
    res = binarySearch(arr, data ,0, len(arr))
    
    
            
    