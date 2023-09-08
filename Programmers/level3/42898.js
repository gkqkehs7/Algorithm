function solution(m, n, puddles) {
    const MOD = 1_000_000_007;
    // n행 m열 배열 생성
    const dp = Array.from({ length: n }, () => Array(m).fill(0));
  
    dp[0][0] = 1;
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < m; j++) {
        if (i === 0 && j === 0) continue;
          // 인덱스 값을 기준으로 보기에 사실상 x === j, y === i의 좌표와 같은 맥락
          // 물 웅덩이에 빠진 경우 해당 경로 값 0으로 초기화
        if (puddles.some(([x, y]) => x === j + 1 && y === i + 1)) {
          dp[i][j] = 0;
        } else {
          // x, y이동에 필요한 걸음 % MOD(문제에서 제시)
          dp[i][j] = ((i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0)) % MOD;
        }
      }
    }
  
      // 우측 하단까지 필요한 경로 수 반환
    return dp[n - 1][m - 1];
  }