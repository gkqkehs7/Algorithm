

function solution(edges) {

    const graph = Array(15).fill().map(() => []);

    let max_node = 0;
    for(const edge of edges) {
        const [start, end] = edge;

        max_node = Math.max(max_node, start);
        max_node = Math.max(max_node, end);

        graph[start].push(end);
    }

    let root = 0;
    let donut = 0;
    let stick = 0;
    let eight = 0;
    for(let i=1; i<=max_node; i++) {
        const visited = Array(15).fill(0);
        visited[i] = 1;

        function dfs(start) {
            if(visited[start] === 2) {
                return;
            }

            for(let j=0; j<graph[start].length; j++) {
                const next = graph[start][j];
                if(visited[next] < 2) {
                    visited[next] += 1;
                    dfs(next);
                }   
            }
        }

        dfs(i);

        console.log("i:",i, visited)

        let one_num = 0;
        let two_num = 0;
        for(let j=0; j<visited.length; j++) {
            if(visited[i] === 1){
                one_num += 1;
            } else if(visited[i] === 2) {
                two_num += 1;
            }
        }

        if(visited[i] === 1) {
            if(graph[i].length > 1) {
                // 얘가 루트
                root = i;
            } else {  // 막대
                stick += 1;
            }
        } else if(two_num > 1) {
            donut += 1;
        } else {
            eight += 1;
        }
   
    }      

    var answer = [root, donut, stick, eight];

    console.log(answer)
    return answer;
}



solution([[4,11], [1,12], [8,3], [12, 7], [4, 2], [7, 11], [4, 8], [10, 11],  [3, 5], [11, 1], [5, 3], [3, 8]])