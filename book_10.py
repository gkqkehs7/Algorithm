def solution(key, lock):
    
    def rotated(a):
        n = len(a)
        m = len(a[0])
        result = [[0]* n for _ in range(m)]

        for i in range(n):
            for j in range(m):
                result[j][n-i-1] = a[i][j]
        return result;
    
    def right(a):
        n = len(a)
        m = len(a[0])
        right = a;
        for i in range(n):
            new = right[i]
            del new[m-1]
            new.insert(0,0)
            right[i] = new
            
        return right;

    def left(a):
        n = len(a)
        m = len(a[0])
        left = a;
        for i in range(n):
            new = left[i]
            del new[0]
            new.append(0)
            left[i] = new
        return left;
    
    def down(a):
        n = len(a)
        m = len(a[0])
        down = a[0:n-1];
        down.insert(0,[0]*m)
        return down;

    def up(a):
        n = len(a)
        m = len(a[0])
        up = a[1:n];
        up.append([0]*m)
        return up;
    
