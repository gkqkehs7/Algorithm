const person = {
	firstName: "Kim",
	lastName: "min woo",

	myName: function() {
		return `${this.firstName} ${this.lastName}`
	}
}

console.log(Object.getOwnPropertyDescriptors(person));
// {
//     firstName: {
//       value: 'Kim',
//       writable: true,
//       enumerable: true,
//       configurable: true
//     },
//     lastName: {
//       value: 'min woo',
//       writable: true,
//       enumerable: true,
//       configurable: true
//     },
//     myName: {
//       value: [Function: myName],
//       writable: true,
//       enumerable: true,
//       configurable: true
//     },
//  }