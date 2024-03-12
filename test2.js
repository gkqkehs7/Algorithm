function dfs(start, graph, visited, depth, friend) {
	if (depth >= 2) return friend;

	for (let i = 0; i < graph[start].length; i++) {
		let next = graph[start][i];

		if (visited[next] < 101) {
			if (visited[next] == 0) {
				friend++;
			}

			visited[next] += 1;

			friend = dfs(next, graph, visited, depth + 1, friend);
		}
	}

	return friend;
}

function solution(N, relation) {
	var answer = [];

	let graph = Array(N + 1)
		.fill()
		.map(() => []);

	relation.forEach((el) => {
		const [a, b] = el;

		graph[a].push(b);
		graph[b].push(a);
	});

	for (let i = 1; i <= N; i++) {
		const visited = Array(N + 1).fill(false);

		visited[i] = 1;

		let friendNum = dfs(i, graph, visited, 0, 0);

		answer.push(friendNum);
	}

	console.log(answer);

	return answer;
}

solution(4, [
	[1, 2],
	[2, 3],
	[3, 4],
	[1, 3],
]);
