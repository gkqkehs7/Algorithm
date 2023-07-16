function solution(toppings) {
    
    let types = new Map();
    let foward_arr = [];
    let count = 0;

    // [1, 2, 1, 3, 1, 4, 1, 2]
    for(let i=0; i<toppings.length; i++) {
        if(types.has(toppings[i])) {
        
        } else {
            types.set(toppings[i], 1);
            count++;
        }
    }

    console.log(count)
    console.log(types)



}

solution([1, 2, 1, 3, 1, 4, 1, 2]);