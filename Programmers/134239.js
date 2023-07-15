function solution(k, ranges) {

    let arr = [];
    let last = 0;
    while(k > 1) {
        let prev_k = k;

        if(k % 2 === 0) {
            k = k / 2;
        } else {
            k = k * 3 + 1;
        }

        arr.push((prev_k + k) / 2);
        last++;
    }


    let answer = []
    for(let i=0; i<ranges.length; i++) {
        const [start, offset] = ranges[i];

        const end = last + offset;
        let sum = 0;
        
        if(start > end) {
            answer.push(-1.0);
            continue;
        } 

        for(let j=start; j<last+offset; j++) {
            sum += arr[j];
        }
        answer.push(sum);
    }

    console.log(answer)
    return answer;
}

solution(5, [[0,0],[0,-1],[2,-3],[3,-3]])