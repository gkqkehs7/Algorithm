# 이진 탐색은 무조건 반으로 가르는게 아니라
# 투포인터 형식으로 점점 정답에 가까워 지는것?
import sys
input = sys.stdin.readline


while True:
    try:
        x = int(input())
        x = x * 10000000

        n = int(input())

        legos = []
        for _ in range(n):
            legos.append(int(input()))
            
        legos.sort()
        start = 0
        end = len(legos) - 1
        
        flag = True
        while start < end:
            temp = legos[start] + legos[end]
            
            if temp == x:
                print('yes %d %d' %(legos[start], legos[end]))
                flag = False
                break
            
            if temp < x:
                start += 1
            elif temp > x:
                end -= 1
                
        if flag == True:
            print('danger')

    except:
        break