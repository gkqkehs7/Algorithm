function solution(maps) {

    let hei = maps.length;
    let wid = maps[0].length;

    let dx = [0, -1, 0, 1];
    let dy = [1, 0, -1, 0];

    let dp = Array(hei).fill().map(() => {
        return Array(wid).fill(999999999)
    })


    let queue = [[0,0]];
    dp[0][0] = 0;

    while(queue.length > 0) {

        let [x, y] = queue.shift();

        if(x === hei - 1 && y === wid - 1) {
            continue;
        }

        for(let i=0; i<4; i++) {
            let nx = x + dx[i];
            let ny = y + dy[i];

            if(nx < hei && nx >=0 && ny < wid && ny >= 0 && maps[nx][ny] !== 0) {
                if(dp[x][y] + 1 < dp[nx][ny]) {
                    dp[nx][ny] = dp[x][y] + 1;
                    queue.push([nx, ny]);
                }
            }
            
        }
    }

    if(dp[hei - 1][wid - 1] === 999999999) {
        return - 1;
    }
   
    return dp[hei - 1][wid - 1] + 1;
}