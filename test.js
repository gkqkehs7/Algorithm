let arr = [0.0045, 0.0145, 0.0245, 0.0545, 0.0745, 0.1145]

for(let i=0; i<arr.length; i++){
	arr[i] = (arr[i] * 9.8);
}

let v = [1000, 2000, 3000, 4000, 5000, 6000]

let arr2 = []
for(let i=0; i<v.length; i++) {
	arr2.push((Math.pow(v[i],2) * 0.0132 * 8.85 * Math.pow(10, -12)) / (2 * Math.pow(0.004, 2)))
}

for(let i=0; i<6; i++) {
	console.log(Math.abs(arr[i] - (arr2[i] * 10)) / arr[i]) 
}
