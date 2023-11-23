function solution(n, results) {
    
    let dp = Array(n+1).fill().map(() => {
        return Array(n+1).fill(0);
    });
   
    for(let i=0; i<results.length; i++) {
        const [winner, loser] = results[i];

        dp[winner][loser] = 1; 
    }
    
    for(let k=1; k<=n; k++) {
        for(let i=1; i<=n; i++) {
            for(let j=1; j<=n; j++) {
                if(dp[i][j] === 0 && dp[i][k] === 1 && dp[k][j] === 1){
                    dp[i][j] = 1;
                }
            }
        }
    }

    var answer = 0;
    
    for(let i=1; i<=n; i++) {
        
        // 이긴 사람수
        let count = 0;
        for(let j=1; j<=n; j++) {
            if(dp[i][j] === 1){
                count++;
            }
        }

        // 진 사람수
        for(let j=1; j<=n; j++) {
            if(dp[j][i] === 1){
                count++;
            }
        }

        if(count === n - 1) answer++;
    }

    console.log(answer);

    return answer;
}

solution(5, [[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]])