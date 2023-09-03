function solution(maps) {

    let map_wid = maps.length;
    let map_hei = maps[0].length;
    let start_x = 0;
    let start_y = 0;
    let end_x = 0;
    let end_y = 0;
    let laber_x = 0;
    let laber_y = 0;

    for(let i=0; i<maps.length; i++) {
        for(let j=0; j<maps[i].length; j++) {
            if(maps[i][j] === "S") {
                start_x = i;
                start_y = j;
            }
            
            if(maps[i][j] === "E") {
                end_x = i;
                end_y = j;
            }

            if(maps[i][j] === "L") {
                laber_x = i;
                laber_y = j;
            }
        }
    }

    let dx = [-1, 0, 1, 0];
    let dy = [0, 1, 0, -1];
    

    // 레버까지 가기
    let queue = [];
    let dp = new Array(101).fill(0).map(() =>
        new Array(101).fill(999999999)
    );

    dp[start_x][start_y] = 0;
    queue.push([start_x, start_y, 0]);
    
    let stop_answer = 999999999;
    let stop_x = -1;
    let stop_y = -1;

    while(queue.length > 0) {
        let [x, y, cost] = queue.shift();

        if(maps[x][y] === "L") {
            if(cost < stop_answer) {
                stop_answer = cost;
                stop_x = x;                
                stop_y = y;                
            }
        }   

        for(let i=0; i<4; i++) {
            let nx = x + dx[i];
            let ny = y + dy[i];
      
            if(nx >= 0 && nx < map_wid && ny >= 0 && ny < map_hei && maps[nx][ny] !== 'X') {
                if(cost + 1 < dp[nx][ny]) {
                    dp[nx][ny] = cost + 1;
                    queue.push([nx, ny, cost + 1]);
                }
            }
        }
    }

    if(stop_answer === 999999999) {
        return -1;
    }

    // 문까지 가기
    queue = [];
    dp = new Array(101).fill(0).map(() =>
        new Array(101).fill(999999999)
    );

    dp[stop_x][stop_y] = 0;
    queue.push([stop_x, stop_y, 0]);
    
    let end_answer = 999999999;
    
    while(queue.length > 0) {
        let [x, y, cost] = queue.shift();

        if(maps[x][y] === "E") {
            if(cost < end_answer) {
                end_answer = cost;               
            }
        }   

        for(let i=0; i<4; i++) {
            let nx = x + dx[i];
            let ny = y + dy[i];
      
            if(nx >= 0 && nx < map_wid && ny >= 0 && ny < map_hei && maps[nx][ny] !== 'X') {
                if(cost + 1 < dp[nx][ny]) {
                    dp[nx][ny] = cost + 1;
                    queue.push([nx, ny, cost + 1]);
                }
            }
        }
    }

    if(end_answer === 999999999) {
        return -1;
    }


    return stop_answer + end_answer;
}

console.log(solution(["LOOXS","OOOOX","OOOOO","OOOOO","EOOOO"]))