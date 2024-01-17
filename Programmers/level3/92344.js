const arr = [1, 2, 3, 4, 5];

const prefix_sum = Array(arr.length).fill(0);

prefix_sum[0] = arr[0];

for (let i = 1; i < prefix_sum.length; i++) {
	prefix_sum[i] = arr[i] + prefix_sum[i - 1];
}

console.log(prefix_sum); // [ 1, 3, 6, 10, 15 ]

console.log('1부터 3까지의 합: ', prefix_sum[3] - prefix_sum[0]); // 9
console.log('2부터 4까지의 합: ', prefix_sum[4] - prefix_sum[1]); // 12
console.log('0부터 3까지의 합: ', prefix_sum[3]); // 10
