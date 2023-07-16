function solution(elements) {

    let dp = Array(1000001).fill(0);

    let len = elements.length;
    elements = elements.concat(elements);
    let answer = 0;


    for(let i=0; i<elements.length; i++) {
        let start = i;
        let sum = 0;
        

        for(let j=start; j<start+len; j++) {
            sum += elements[j];
            if(dp[sum] === 0) {
            
                dp[sum] = 1;
                answer += 1;
            }
        }       
 
    }

    return answer;
}

solution([7,9,1,1,4])