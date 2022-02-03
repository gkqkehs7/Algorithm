N = input().split()
arr = list(map(int, input().split()))
arr.sort()

M = input().split()
arr2 = list(map(int, input().split()))

def binarySearch(array, target, start, end):
    if(start > end):
        return print(0) 
    mid= (start+end) //2
    if array[mid] == target:
        return print(1);
    elif array[mid] > target:
        return binarySearch(array, target, start, mid-1)
    else:
        return binarySearch(array, target, mid+1, end);
 

for data in arr2:
    binarySearch(arr, data, 0, len(arr)-1)
