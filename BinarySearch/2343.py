import sys
input = sys.stdin.readline
n, m = map(int, input().split())

lectures= list(map(int, input().split()))

start = 1
end = sum(lectures)

answer = 0


while start <= end:
    mid = (start+end) // 2
    
    count = 1
    temp = 0
    
    cant = False
    for lecture in lectures:
        if temp +lecture <= mid:
            temp += lecture
        else:
            if lecture > mid:
                cant = True
                break
            else:
                temp = lecture
                count += 1
                
    if cant == True:
        start = mid + 1
    else:
        if count == m:
            answer = mid
            
        if count <= m:
            answer = mid
            end = mid - 1 
        else:
            start = mid + 1
        
print(answer)