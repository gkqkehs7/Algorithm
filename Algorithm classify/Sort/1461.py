from re import A
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

signed = []
unsigned = []

arrs = list(map(int ,input().split()))

for arr in arrs:
    if arr >= 0:
        signed.append(arr)
    else:
        unsigned.append(-arr)
        
signed.sort(reverse=True)

unsigned.sort(reverse=True)


answer = 0
remain = 0

if signed and unsigned:
    if signed[0] > unsigned[0]: 
        for i in range(0,len(unsigned),m):
            answer += unsigned[i]

        for i in range(0,len(signed),m):
            answer += signed[i]
            
        answer = answer * 2 - signed[0]
    else:
        for i in range(0,len(signed),m):
                answer += signed[i]

        for i in range(0,len(unsigned),m):
            answer += unsigned[i]
        
        answer = answer * 2 - unsigned[0]
elif not signed:
    for i in range(0,len(unsigned),m):
        answer += unsigned[i]
    
    answer = answer * 2 - unsigned[0]
elif not unsigned:
    for i in range(0,len(signed),m):
        answer += signed[i]
        
    answer = answer * 2 - signed[0]

print(answer)