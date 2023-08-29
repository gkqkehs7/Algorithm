function solution(n) {
    const dp = Array.from({length:n}).fill(0); // n길이의 dp배열을 생성
    dp[0] = 1, dp[1] = 1; // 0번과 1번에 1 대입
    
  	for (let i=2; i<=n; i++) {
        dp[i] = (dp[i-2] + dp[i-1])%1234567;
    }
    
    return dp[n];
}