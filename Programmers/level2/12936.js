function get_order(n) {
    if(n === 1) return 1;

    return n * get_order(n-1);
}


function solution(n, k) {
    
    let total = get_order(n-1);

    let number = parseInt(k / total) + 1;

    let order = k % total;

    let visited = Array(n+1).fill(false);

    visited[number] = true;

    let arr = [number];

    let count = 0;

    let answer = [];

    let find = false

    function back_tracking(depth) {
        if(find) return;

        if(depth === n - 1) {
            count++;

            if(count === order) {
                answer = [...arr];
                find = true;
                return;
            }
       
        }

        for(let i = 1; i <= n; i++) {
            if(visited[i] === false) {
                visited[i] = true;
                arr.push(i);
                back_tracking(depth + 1);

                if(find) return;

                arr.pop(i);
                visited[i] = false;
            }
        }
    }

    back_tracking(0);

    return answer
}

console.log(solution(3, 5))