const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout,
});

const input = [];

rl.on('line', function (line) {
	input.push(line); // 변수에 값을 할당한다.
}).on('close', function () {
	var [n, m] = input
		.shift()
		.split(' ')
		.map((v) => parseInt(v));

	for (let i = 0; i < n; i++) {
		var [start_x, start_y, end_x, end_y, time] = input[i]
			.split(' ')
			.map((el) => parseInt(el));

		console.log(start_x, start_y, end_x, end_y, time);
	}

	for (let i = n; i < n + m; i++) {
		var [start_x, end_x] = input[i].split(' ').map((el) => parseInt(el));
		console.log(start_x, start_y);
	}

	process.exit(); // 프로세스 종료
});
