function solution(triangle) {

    let hei = triangle.length;

    let dp = Array(triangle.length + 1).fill().map(() => {
        return Array(triangle.length + 1).fill(0)
    })


    dp[0][0] = triangle[0][0];

    for(let i=1; i<triangle.length; i++) {
        for(let j=0; j<triangle[i].length; j++) {

            let now = triangle[i][j]

            if(j === 0) {
                dp[i][j] = dp[i-1][j] + now;
                continue;
            }
       
            dp[i][j] = Math.max(dp[i-1][j-1] + now, dp[i-1][j] + now);
        }
    }

    return Math.max(...dp[hei - 1])
}