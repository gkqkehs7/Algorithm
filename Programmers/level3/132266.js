function solution(n, roads, sources, destination) {

    const visited = new Array(n+1).fill(Infinity)

    const connect = new Array(n+1).fill(0).map(() => [])

    for(let i=0; i<roads.length; i++) {
        const [start, end] = roads[i];

        connect[start].push(end);
        connect[end].push(start);
    }

    const q = [destination]
    visited[destination] = 0

    while(q.length) {
        const cur = q.shift()
        // 갈 수 있는 다음 길
        for(const next of connect[cur]) {
            // 가보지 않은 길이라면, 그렇기에 초기에 모든 값을 Infinity로 설정
            if(visited[cur]+1 < visited[next]) {
                visited[next] = visited[cur]+1
                q.push(next)
            }
        }
    }

    return sources.map(a => visited[a] === Infinity ? -1 : visited[a])
}

solution(3, [[1, 2], [2, 3]], [2, 3], 1)