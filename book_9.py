def solution(s):
    answer = 0

    for i in range(len(s)):
        compress = i+1; #압축할 단위
        prev = s[:compress]
        cursor = compress;
        count = compress;
        same = False;
        same_count = 0;
        while True:
            if(compress > len(s) - cursor):
                if(same==True):
                    count += 1;
                    count += len(s) - cursor;
                    same_count += 1;
                if(i == 0):
                    answer = count;
                else:
                    answer = min(answer,count)
                break;
            
            if(prev == s[cursor:cursor+compress]):
                same=True;
                cursor += compress;
            
            else:
                if(same == True):
                    same=False;
                    count += 1;
                prev = s[cursor:cursor+compress]
                cursor += compress;
                count += compress;
    return answer

print(solution('xxxxxxxxxxyyy'))


def test(s):
    
    for step in range(1, len(s)):
        compressed = ""
        prev = s[0:step] #압축할 단위
        count = 1; #겹치는 개수
        
        for j in range(step, len(s), step):
            if prev == s[j:j+step]:
                count += 1;
            else:
                compressed += str(count) + prev if count >= 2 else prev
                prev = s[j:j+step]
                count = 1;
        compressed += str(count) + prev if count >= 2 else prev
        
test('aabbccc')