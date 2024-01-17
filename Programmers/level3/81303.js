function solution(n, k, cmds) {
	const Node = function (index, prev) {
		this.index = index;
		this.prev = prev;
		this.next;
	};

	let root = new Node(0);
	let currentNode = root;
	let prev = root;

	for (let i = 1; i < n; i++) {
		const newNode = new Node(i, prev);
		prev.next = newNode;
		prev = newNode;

		if (i === k) {
			currentNode = newNode;
		}
	}

	const delete_node = [];

	cmds.map((cmd) => {
		const [command, count] = cmd.split(' ');

		let i = 0;

		if (command === 'U') {
			let i = 0;
			while (i < count) {
				currentNode = currentNode.prev;
				i++;
			}
		} else if (command === 'D') {
			let i = 0;
			while (i < count) {
				currentNode = currentNode.next;
				i++;
			}
		} else if (command === 'C') {
			delete_node.push(currentNode);

			const prev = currentNode.prev;
			const next = currentNode.next;

			if (prev && next) {
				prev.next = next;
				next.prev = prev;
				currentNode = next;
			} else if (prev) {
				prev.next = null;
				currentNode = prev;
			} else if (next) {
				next.prev = null;
				currentNode = next;
			}
		} else {
			const least_delete_node = delete_node.pop();
			const prev = least_delete_node.prev;
			const next = least_delete_node.next;

			if (prev) {
				prev.next = least_delete_node;
			}

			if (next) {
				next.prev = least_delete_node;
			}
		}
	});

	let answer = Array(n).fill('O');

	delete_node.map((node) => {
		answer[node.index] = 'X';
	});

	return answer.join('');
}

solution(8, 2, ['D 2', 'C', 'U 3', 'C', 'D 4', 'C', 'U 2', 'Z', 'Z']);
