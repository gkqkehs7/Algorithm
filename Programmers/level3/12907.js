function solution(n, money) {
    const dp = Array.from({length : n + 1}, () => 0);
    dp[0] = 1;

    for(const currency of money){
        for(let i = currency; i <= n; i += 1){
            dp[i] += dp[i - currency];
        };
    };
    return dp[n];
}