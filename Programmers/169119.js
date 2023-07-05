function solution(board) {  
    
    let board_wid = board[0].length;
    let board_hei = board.length;

    let robot_x = 0;
    let robot_y = 0;

    for(let i=0; i<board.length; i++) {
        for(let j=0; j<board[i].length; j++) {
            if(board[i][j] === "R") {
                robot_x = i;                
                robot_y = j;      
                break;          
            }
        }
    }

    // 배열 및 값 초기화
    let answer = 999999999;
    let dp = new Array(101).fill(0).map(() =>
        new Array(101).fill(0).map(() => new Array(4).fill(999999999))
    );
        
    let queue = [];
    let dx = [-1, 0, 1, 0];
    let dy = [0, 1, 0, -1];

    for(let i=0; i<4; i++) {
        dp[robot_x][robot_y][i] = 0;
        queue.push([robot_x, robot_y, i, 0]);
    }


    while(queue.length > 0) {
        let [x, y, direct, cost] = queue.shift();

        console.log(x, y);

        if(board[x][y] === "G") {
            if(cost < answer) {
                answer = cost;
                continue;
            }
        }

        while(x >= 0 && x < board_hei && y >= 0 && y < board_wid && board[x][y] !== "D") {
            x = x + dx[direct];
            y = y + dy[direct];

            if(x < 0 || x >= board_hei || y < 0 || y >= board_wid || board[x][y] === "D") {
                x = x - dx[direct];
                y = y - dy[direct];
                break;
            }
        }

        for(let i=0; i<4; i++) {
            if(cost + 1 < dp[x][y][i]) {
                dp[x][y][i] = cost + 1;
                queue.push([x, y, i, cost + 1])
            }
        }
    }


    if(answer === 999999999) {
        answer = -1;
    }
    return answer;
}

console.log(solution([".D.R", "....", ".G..", "...D"]));