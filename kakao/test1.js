function solution(friends, gifts) {

	const arr = Array(friends.length).fill().map(() => {
		return Array(friends.length).fill(0);
	})

	let people = {};

	for(let i=0; i<friends.length; i++) {
		people[friends[i]] = i;
	}
	

	// 선물 지수
	const present_ratio = Array(friends.length).fill(0);


	for(let i=0; i<gifts.length; i++) {
		const [sender, receiver] = gifts[i].split(" ");

		const sender_num = people[sender];
		const receiver_num = people[receiver];

		arr[sender_num][receiver_num] += 1;
		present_ratio[sender_num] += 1;
		present_ratio[receiver_num] -= 1;
	}

	// 정답
	const answer = Array(friends.length).fill(0);

	for(let i=0; i<arr.length; i++) {
		for(let j= i + 1; j<arr.length; j++) {
			const sender = i;
			const receiver = j;
		
			const sender_to_receiver = arr[i][j]; // sender -> receiver
			const receiver_to_sender = arr[j][i];

			if(sender_to_receiver === receiver_to_sender) { // 주고 받은 기록이 없거나 수가 같은 경우 (0, 0)도 포함
				if(present_ratio[sender] !== present_ratio[receiver]) { // 선물 지수가 다른 경우만
					if(present_ratio[sender] > present_ratio[receiver]) {
						answer[sender]++;
					} else {
						answer[receiver]++;
					}
				}

			} else {
				if(sender_to_receiver > receiver_to_sender) {
					answer[sender]++;
				} else {
					answer[receiver]++;
				}
			}
		}
	}

    return Math.max(...answer);
}

solution(["a", "b", "c", "d", "e"], ["c b", "c a", "c d", "e c", "c e"])