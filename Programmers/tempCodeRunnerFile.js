function solution(citations) {

    let n = citations.length;

    citations.sort((prev, next) => {
        return prev - next;
    })

    let start = 0;
    let end = citations.length - 1;

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

        console.log(hIdx, count)
        
        if(hIdx <= n - count) {
            answer = hIdx
            start = hIdx + 1;
        } else {
            end = hIdx - 1;
        }

    }

    console.log(answer);

    return answer;
}

solution([3, 0, 6, 1, 5])