const visited = Array(N + 1).fill(false);

function dfs(start, graph, depth, friend) {
	if (depth >= 2) return friend;

	for (let i = 0; i < graph[start].length; i++) {
		let next = graph[start][i];

		if (!visited[next]) {
			visited[next] = true;

			friend++;

			friend = dfs(next, graph, depth + 1, friend);
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
		visited[i] = true;

		let friendNum = dfs(i, graph, visited, 0, 0);

		answer.push(friendNum);

		for (let i = 1; j <= N; j++) {
			visited[i] = false;
		}
	}

	console.log(answer);

	return answer;
}

solution(6, [
	[1, 2],
	[4, 2],
	[1, 3],
	[4, 5],
	[2, 6],
]);
