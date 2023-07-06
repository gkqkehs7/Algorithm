function check_o_bingo(board) {
    for(let i=0; i<3; i++) {
        if(board[i][0] === "O" && board[i][1] === "O" && board[i][2] === "O") {
            return true;
        }

        if(board[0][i] ===  "O" && board[1][i] ===  "O" && board[2][i] === "O") {
            return true;
        }
    }

    if(board[0][0] ===  "O" && board[1][1] ===  "O" && board[2][2] === "O") {
        return true;
    }

    if(board[0][2] ===  "O" && board[1][1] ===  "O" && board[2][0] === "O") {
        return true;
    }

    return false;
}

function check_x_bingo(board) {
    for(let i=0; i<3; i++) {
        if(board[i][0] === "X" && board[i][1] === "X" && board[i][2] === "X") {
            return true;
        }

        if(board[0][i] ===  "X" && board[1][i] ===  "X" && board[2][i] === "X") {
            return true;
        }
    }

    if(board[0][0] ===  "X" && board[1][1] ===  "X" && board[2][2] === "X") {
        return true;
    }

    if(board[0][2] ===  "X" && board[1][1] ===  "X" && board[2][0] === "X") {
        return true;
    }

    return false;
}


function solution(board) {

    let o_cnt = 0;
    let x_cnt = 0;
    let o_bingo = check_o_bingo(board);
    let x_bingo = check_x_bingo(board);

    for(let i=0; i<board.length; i++) {
        for(let j=0; j<board[i].length; j++) {
            if(board[i][j] === "O") {
                o_cnt += 1;
            } else if(board[i][j] === "X") {
                x_cnt += 1;
            } 
        }
    }

    console.log(o_cnt)
    console.log(x_cnt)
    console.log(o_bingo)
    console.log(x_bingo)

    if(o_cnt < x_cnt) {
        console.log("x개수가 o보다 많습니다")
        return 0;
    }

    if(o_cnt > x_cnt + 1) {
        console.log("o개수가 x보다 2개 이상 많습니다")
        return 0;
    }

    if(o_bingo == true && x_bingo == true) {
        console.log("둘다 빙고가 될 수 없습니다")
        return 0;
    } 

    if(o_bingo == true) {
        if(o_cnt <= x_cnt) {
            console.log("o가 빙고일때는 x개수가 o보다 적어야 합니다")
            return 0;
        }
    }

    if(x_bingo == true) {
        if(o_cnt > x_cnt) {
            console.log("x가 빙고일때는 o개수가 x보다 많으면 안됩니다")
            return 0;
        }
    }
 
    return 1;
}

console.log(solution(["...", "...", "..."]));

// o의 개수가 x개수보다 같거나 많아야 한다
// 만약 o가 빙고가 되었을때 이면 o 개수보다 x개수가 적어야 한다
// 만약 x가 빙고가 되었다면 o개수가 x개수보다 많으면 안된다
// 둘다 빙고가 되면 안된다
