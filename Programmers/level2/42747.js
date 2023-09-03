function solution(citations) {

    let n = citations.length;

    citations.sort((prev, next) => {
        return prev - next;
    })

    let start = 0;
    let end = citations.length;

    let answer = 0; 

    while(start <= end) {
        let hIdx = parseInt((start+end) / 2);
     
        let count = 0;
        for(let i=0; i<citations.length; i++) {
            if(citations[i] < hIdx) {
                count++;
            } else {
                break;
            }
        }
        
        if(hIdx <= n - count) { // h번 이상 인용된 논문
            answer = hIdx
            start = hIdx + 1;
        } else {
            end = hIdx - 1;
        }

    }

    console.log(answer);

    return answer;
}

solution([4, 4, 4])