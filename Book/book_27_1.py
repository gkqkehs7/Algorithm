pin = list(map(int, input().split()))

arr = list(map(int, input().split()))

target = pin[1]

def left_binary_search(arr, start, end, target):
        
    if start > end: return None;
    
    mid = (start+end) // 2;
    
    if arr[mid] == target:
        if mid-1 != 0 and arr[mid-1] == target:
            return left_binary_search(arr, start, mid-1 , target)
        else: 
            return mid;
        
    elif target < arr[mid]:
        mid -= 1;
        return left_binary_search(arr, start, mid, target)

    else: 
        mid += 1;
        return left_binary_search(arr, mid, end, target)
    
left_target = left_binary_search(arr, 0, len(arr)-1, target)

def right_binary_search(arr, start, end, target):
        
    if start > end: return None;
    
    mid = (start+end) // 2;
    
    if arr[mid] == target:
        if mid+1 != len(arr) -1 and arr[mid+1] == target:
            return right_binary_search(arr, mid+1, end , target)
        else: 
            return mid;
        
    elif target < arr[mid]:
        mid -= 1;
        return right_binary_search(arr, start, mid, target)

    else: 
        mid += 1;
        return right_binary_search(arr, mid, end, target)
    
right_target = right_binary_search(arr, 0, len(arr)-1, target)

if right_target == None or left_target == None:
    print(-1)
else:    
    print(right_target - left_target + 1)