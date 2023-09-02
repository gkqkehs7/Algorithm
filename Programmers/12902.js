function solution(n) {

    let dp = [0, 0, 3, 0, 11];

    for(let i=5; i<=n; i++) {
        if(i % 2 === 0) {
            dp[i] = 0;
            continue;
        }

        
        dp[i] = (dp[i-2] + dp[i-4] + 5) % 1000000007;
    }

    console.log(dp)

    return dp[n];
}


solution(10)