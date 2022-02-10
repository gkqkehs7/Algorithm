import sys

N = int(sys.stdin.readline().rstrip())

def isVps(str):
    left = 0;
    right = 0;
    for i in range(len(str)):
        if(left < right):
            return "NO"
        if(str[i] == "("):
            left = left + 1;
        else:
            right = right + 1
            
            
    if(left == right):
        return "YES"
    else:
        return "NO"

res = []

for n in range(N):
    str = sys.stdin.readline().rstrip()
    res.append(isVps(str))
    
    
for re in res:
    print(re)
    
