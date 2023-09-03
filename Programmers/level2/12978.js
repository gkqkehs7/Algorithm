function solution(N, roads, K) {
   
    let dp = Array(N+1).fill().map(() => {
        return Array(N+1).fill(999999999);
    })
    
    for(let i=1; i<N; i++) {
        dp[i][i] = 0;
    }



    for(let i=0; i<roads.length; i++) {

        let [start, end, time] = roads[i];
        
        if(dp[start][end] > time) {
            dp[start][end] = time;
            dp[end][start] = time;
        }
    }
    

    for(let k=1; k<=N; k++) {
        for(let i=1; i<=N; i++) {
            for(let j=1; j<=N; j++) {
                dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }


    let answer = 0;
    for(let i=1; i<=N; i++) {
        if(dp[1][i] <= K) {
            answer++;
        }
    }

    return answer;
}

solution(6, [[1,2,1],[1,3,2],[2,3,2],[3,4,3],[3,5,2],[3,5,3],[5,6,1]], 4)