function solution(k, tangerine) {

    let nums = {};

    for(let i=0; i<tangerine.length; i++) {
        if(tangerine[i] in nums) {
            nums[tangerine[i]] += 1;
        } else {
            nums[tangerine[i]] = 1;
        }
    }

    let new_nums = [];
    for (const key in nums) {
        const value = nums[key];
        new_nums.push(value);
    }

    new_nums.sort((prev, next) => { 
        return next - prev;
    })

    // console.log(nums);
    // console.log(new_nums);

    console.log(new_nums)
    let count = 0;
    let answer = 0;
    for(let i=0; i<new_nums.length; i++) {

        count += new_nums[i];
        answer++;

        if(count >= k) {
            break;
        }
    }

    return answer;
}

solution(6, [1, 3, 2, 5, 4, 5, 2, 3])