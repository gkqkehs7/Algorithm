function solution(n, k, cmds) {

    let stack = [];
    const numbers = Array.from({ length: n }, (_, index) => index);
    let idx = k;

    for(const cmd of cmds) {
        console.log(idx)
        if(cmd[0] === 'U') {
            let input = cmd[2];
            idx += parseInt(input);
        } else if(cmd[0] === 'D') {
            let input = cmd[2];
            idx -= parseInt(input);
        } else if(cmd[0] === 'C') {
            stack.push(idx);
            if(idx === n - 1) { // 삭제된 행이 마지막 행이 경우
                idx -= 1;
            } else {
                idx += 1;
            }

            idx++;
        } else if(cmd[0] === 'Z') {
            stack.pop();
        }
    }

    let deleted = Array(n).fill(false);

    for(const idx of stack) {
        deleted[idx] = true;
    }

    let answer = '';

    for(const del of deleted) {
        if(del) {
            answer += 'X'
        } else {
            answer += '0'
        }
    }

    console.log(answer);

    return answer;
}

solution(8, 2, ["D 2","C","U 3","C","D 4","C","U 2","Z","Z"])