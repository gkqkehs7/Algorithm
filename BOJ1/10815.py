N = int(input());

datas = list(map(int, input().split()));
datas.sort()

M = int(input());

def binarySearch(array, target, start, end):
    if(start > end):
        return 0;
    mid = (start+end) //2
    if array[mid] == target:
        return 1;
    elif array[mid] > target:
        return binarySearch(array, target, start, mid-1)
    else:
        return binarySearch(array, target, mid+1, end);
 
results = []

compares = list(map(int, input().split()))

for compare in compares:
    results.append(binarySearch(datas, compare, 0, len(datas)-1))
    
print(*results, sep=' ')