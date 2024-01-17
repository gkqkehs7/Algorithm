function solution(board, skills) {
	const temp = Array(board.length + 1)
		.fill()
		.map(() => Array(board[0].length + 1).fill(0));

	for (const skill of skills) {
		let [type, r1, c1, r2, c2, degree] = skill;

		degree = type === 1 ? -degree : degree;

		temp[r1][c1] += degree;
		temp[r1][c2 + 1] += -degree;
		temp[r2 + 1][c1] += -degree;
		temp[r2 + 1][c2 + 1] += degree;
	}

	// 가로 방향 누적 합
	for (let i = 0; i < temp.length; i++) {
		for (let j = 1; j < temp[0].length; j++) {
			temp[i][j] += temp[i][j - 1];
		}
	}

	// 세로 방향 누적 합
	for (let i = 0; i < temp[0].length; i++) {
		for (let j = 1; j < temp.length; j++) {
			temp[j][i] += temp[j - 1][i];
		}
	}

	let answer = 0;

	for (let i = 0; i < board.length; i++) {
		for (let j = 0; j < board[i].length; j++) {
			board[i][j] += temp[i][j];

			if (board[i][j] > 0) answer += 1;
		}
	}

	return answer;
}

solution(
	[
		[5, 5, 5, 5, 5],
		[5, 5, 5, 5, 5],
		[5, 5, 5, 5, 5],
		[5, 5, 5, 5, 5],
	],
	[
		[1, 0, 0, 3, 4, 4],
		[1, 2, 0, 2, 3, 2],
		[2, 1, 0, 3, 1, 2],
		[1, 0, 1, 3, 3, 1],
	]
);
