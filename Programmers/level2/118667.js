function solution(queue1, queue2) {

    let q_len = queue1.length;

    let q1_sum = 0;
    for(let i=0; i<queue1.length; i++) {
        q1_sum += queue1[i];
    }

    let q2_sum = 0;
    for(let i=0; i<queue2.length; i++) {
        q2_sum += queue2[i];
    }

    if((q1_sum + q2_sum) % 2 !== 0) {
        return -1;
    }

    let temp = Array(queue1.length).fill(0);

    for(let i=0; i<queue1.length; i++) {
        temp[i] = queue1[i]
    }

    queue1 = queue1.concat(queue2);
    queue2 = queue2.concat(temp);
    
    let q1_start = 0;
    let q1_end = q_len - 1;
    let q2_start = 0;
    let q2_end = q_len - 1;  

    let answer = 0;

    while(q1_sum !== q2_sum) {


        if(q1_end > q_len * 2 + 1 || q1_end < q1_start || q2_end < q2_start || q2_end > q_len * 2 + 1) {
            answer = -1;
            break;
        }

        if(q1_sum > q2_sum) {
            let q1_top = queue1[q1_start];
            q1_start += 1;
            q2_end += 1;
            q1_sum -= q1_top;
            q2_sum += q1_top;
        } else if(q1_sum < q2_sum) {
            let q2_top = queue2[q2_start];
            q2_start += 1;
            q1_end += 1;
            q1_sum += q2_top;
            q2_sum -= q2_top;
        }

        answer += 1;
    }

    console.log(answer)

    return answer;
}

solution([3, 3, 3, 3], [3, 3, 21, 3])