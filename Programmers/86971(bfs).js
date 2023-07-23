function solution(n, wires) {
   
    let answer = 99999999;
    
    for(let i=0; i<wires.length; i++) {
        
        let graph = Array(n + 1).fill().map(() => [])

        for(let j=0; j<wires.length; j++) {
            if(i === j) {
                continue;
            }

            let [a, b] = wires[j];

            graph[a].push(b);
            graph[b].push(a);
        }

        let queue =[];
        queue.push(1);
        let visited = Array(n+1).fill(false);
        visited[1] = true;

        while(queue.length > 0) {
            let now = queue.shift();

            for(let k=0; k<graph[now].length; k++) {
                let next = graph[now][k];
            
                if(visited[next] === false) {
                    queue.push(next);
                    visited[next] = true;
                }
            }
        }

        let temp = 0;
        for(let k=1; k<visited.length; k++) {
            if(visited[k] === true) {
                temp++;
            }
        }
        answer = Math.min(answer, Math.abs(n - 2 * temp))
    }

    console.log(answer)
    return answer
}


solution(9, [[1,3],[2,3],[3,4],[4,5],[4,6],[4,7],[7,8],[7,9]])