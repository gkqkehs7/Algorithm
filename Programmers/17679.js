function solution(m, n, origin_board) {

    let board = Array(m).fill().map(() => {
        return Array(n).fill(0);
    })

    let visited = Array(m).fill().map(() => {
        return Array(n).fill(false);
    })

    let check =  Array(m).fill().map(() => {
        return Array(n).fill(0);
    })

    let bomb_count = 0;

    
    for(let i=0; i<m; i++) {
        for(let j=0; j<n; j++) {
            board[i][j] = origin_board[i][j];
            check[i][j] = board[i][j];
        }
    }

    function check_pang(x, y) {
        let now = board[x][y];

        if(x + 1 < m && y + 1 < n) {
            if(board[x+1][y] === now && board[x][y+1] === now && board[x+1][y+1] === now) {
                // console.log(now, board[x+1][y], board[x][y+1], board[x+1][y+1])

                if(check[x][y] !== -1) {
                    check[x][y] = -1
                    bomb_count++;
                }

                if(check[x+1][y] !== -1) {
                    check[x+1][y] = -1
                    bomb_count++;
                }
              
                if(check[x][y+1] !== -1) {
                    check[x][y+1] = -1
                    bomb_count++;
                }
              
                if(check[x+1][y+1] !== -1) {
                    check[x+1][y+1] = -1
                    bomb_count++;
                }
              
              
    
         
                return true;
            } 
            return false;
        }
        return false;
    }

    function dfs(x, y) {
        if(visited[x][y] === false && check_pang(x, y)) {

            visited[x][y] = true;

            if(check_pang(x+1, y)) {
                visited[x+1][y] = true;
                dfs(x+1, y); 
            }
    
            if(check_pang(x, y+1)) {
                visited[x][y+1] = true;
                dfs(x, y+1); 
            }
    
            if(check_pang(x+1, y+1)) {
                visited[x+1][y+1] = true;
                dfs(x+1, y+1); 
            }
        }
    }

    let answer = 0;

    while(true) {
        
        for(let i=0; i<m; i++) {
            for (let j=0; j<n; j++) {
                dfs(i, j);
            }      
        }

        // console.log(check)

        // 떨어뜨리기
        while(true) {
            let down_count = 0;
            for(let i=0; i<m-1; i++) {
                for(let j=0; j<n; j++) {
                    if(check[i][j] !== -1 && check[i+1][j] === -1) {
                        check[i+1][j] = check[i][j];
                        check[i][j] = -1;
                        down_count++;
                    }
                }
            }

            if(down_count === 0) {
                break;
            }
        }
        

        // console.log(check)

        if(bomb_count === 0) {
            break;
        }
        
        answer += bomb_count;

        bomb_count = 0;

        for(let i=0; i<m; i++) {
            for(let j=0; j<n; j++) {
                board[i][j] = check[i][j]
                visited[i][j] = false;
            }
        }
    }
   
    console.log(answer);
    
    return answer;
}

solution(4, 5, ["CCBDE", "AAADE", "AAABF", "CCBBF"])