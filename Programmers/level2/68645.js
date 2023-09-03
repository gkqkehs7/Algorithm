function solution(n) {

    let map = Array(n).fill().map(() => Array(n).fill(0));

    let start = 0;
    let end = n;
    let num = 1;
    let diff = 0;

    for(let i=1; i<=n; i++) {
        if(i % 3 === 0) { // 대각선 왼쪽 위 로 이동
            for(let j=end - 1; j >= start; j--) {
                // console.log(j, j - diff)
                map[j][j-diff] = num;
                num++;
            }

            // console.log('----')
            diff++;
            start++;
        } else if(i % 3 === 1) { // 아래로 이동
            for(let j=start; j<end; j++) {
                // console.log(j, diff)
                map[j][diff] = num;
                num++;
            }
            // console.log('----')
            start++;
        } else if(i % 3 === 2) { // 오른쪽 이동
            for(let j=start; j<end; j++) {
                // console.log(n-diff-1, j-diff);
                map[n-diff-1][j-diff] = num;
                num++;
            }
            // console.log('----')
            end--;
        }
    }
    
    console.log(map);

    let answer = [];
    for(let i=0; i<n; i++) {

        for(let j=0; j<n; j++) {
            if(map[i][j] !== 0) {
                answer.push(map[i][j])
            }
        }

    }

    console.log(answer);
    
    return answer;
}

solution(6)