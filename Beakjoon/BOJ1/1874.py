import sys

N = int(sys.stdin.readline().rstrip())

cursor_arr = [n+1 for n in range(N)]

cursor = 0;

res = ["+"]
for n in range(N):
    target = int(sys.stdin.readline().rstrip())
    
    if(cursor == -1):
        res.append("+")
        cursor = cursor +1
        
    while(cursor_arr[cursor] < target):
        res.append("+")
        cursor = cursor + 1;
        
    if(cursor_arr[cursor] == target):
        res.append("-")
        cursor_arr.pop(cursor)
    
        cursor = cursor -1;       

if len(cursor_arr) != 0:
    print("NO")
else:
    for re in res:
        print(re)