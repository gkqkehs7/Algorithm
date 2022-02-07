import sys

left = list(sys.stdin.readline().rstrip())
right = []

M = int(sys.stdin.readline());


for m in range(M):
    cmd = sys.stdin.readline().rstrip()
    
    if(cmd[0] == "P"):
        left.append(cmd[2])
    elif(cmd[0] == "L" and left != []):
        right.append(left.pop())
    elif(cmd[0] == "D" and right != []):
        left.append(right.pop())
    elif(cmd[0] == "B" and left != []):  
        left.pop()

print(''.join(left+list(reversed(right))))


# reverse() 함수는 값을 반환하지 않는다 따라서 reverse()를 사용하려 했다면,
# right.reverse() 한다음 left+right를 해주었어야했다.
# right.reverse의 return 값은 none이다

# 왜 != [] 은 되고 len(0)은 안되는가?