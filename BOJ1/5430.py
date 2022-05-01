import sys
from collections import deque

N = int(sys.stdin.readline().rstrip())

res = []
for n in range(N):
    command = sys.stdin.readline().rstrip()
    length = sys.stdin.readline().rstrip()
    str = sys.stdin.readline().rstrip()
    cursor = 0;

    deq = []
    if(len(str) == 2):
        deq = []
    else:
        str = str[1:]
        str = str[:-1]
        deq = deque(str.split(','))
        
    result = ""
    for cmd in command:
        if(cmd == "R"):
            if(cursor >= 0):
                cursor = -1;
            else:
                cursor = 0;
        else:
            if(len(deq) == 0):
                result = "error"
                break; 
            else:
                if(cursor < 0):
                    deq.pop()
                else:
                    deq.popleft()      
          
    if(result == "error"):
        res.append(result)
    else:
        if(len(deq) == 0):
            res.append("[]")
        else:
            if(cursor >=0):
                temp = ','.join(deq)
                temp = "[" + temp + "]"
                res.append(temp)
            else:
                deq = reversed(deq)
                temp = ','.join(deq)
                temp = "[" + temp + "]"
                res.append(temp)
                
for re in res:
    print(re)