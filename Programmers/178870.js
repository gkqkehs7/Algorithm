function solution(sequence, k) {
    
    let start = 0;
    let end = 0;
    let sum = sequence[0];
    
    let diff = 1000001;
    let answer_start = 0;
    let answer_end = 0;
    
    while(end < sequence.length) {
                
        if(sum == k) {
            if(end - start < diff) {
                answer_start = start;
                answer_end = end;
                diff = end - start;
            } 
            end = end + 1;
            sum += sequence[end];
        } else if(sum < k) {
            end = end + 1;
            sum += sequence[end];
        } else if(sum > k) {
            sum -= sequence[start];
            start = start + 1;
        }
    }
    
    var answer = [];
    answer.push(answer_start);
    answer.push(answer_end);
    return answer;
}

