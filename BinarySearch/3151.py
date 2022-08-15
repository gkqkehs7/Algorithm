import sys
input = sys.stdin.readline

n = int(input())
students = list(map(int, input().split()))
students.sort()

answer = 0

for i in range(n-2):
    start, end = i, n-1
    
    target = students[i]
    
    while start < end:
        temp = students[start] + students[end]
        
        if temp + target == 0:
            flag = False
            answer += 1
            if students[start] == students[start+1]:
                flag = True
                start += 1
            if students[end] == students[end - 1]:
                flag = True
                end -= 1
            if flag == False:
                start += 1
                end -= 1
        elif temp + target < 0:
            start += 1
        elif temp + target > 0:
            end -= 1

print(answer)
    