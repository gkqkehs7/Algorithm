import sys
from collections import deque

str = sys.stdin.readline().rstrip()

deq = []
if(len(str) == 2):
    deq = []
else:
    str = str[1:]
    str = str[:-1]
    deq = deque(str.split(','))
    
deq = reversed(deq)
    
res = ','.join(deq)
print(res)