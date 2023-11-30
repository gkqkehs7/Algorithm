function combinations(arr) {
    let result = [];
  
    function combine(current, start) {
      for (let i = start; i < arr.length; i++) {
        current.push(arr[i]);
        if (current.length === Math.ceil(arr.length / 2)) {
          result.push(current.slice());
        } else {
          combine(current, i + 1);
        }
        current.pop();
      }
    }
  
    combine([], 0);
    return result;
}

function compare(A_dice, B_dice) {

    // console.log(A_dice, B_dice)
    let win = 0;
    let draw = 0;
    let lose = 0;

    for(let i=0; i<A_dice.length; i++) {
        for(let j=0; j<B_dice.length; j++) {
            if(A_dice[i] > B_dice[j]) {
                win++;
            } else if(A_dice[i] === B_dice[j]) {
                draw++;
            } else {
                lose++;
            }
        }
    }

    return [win, draw, lose];
}

function solution(dice) {
    const arr = Array.from({ length: dice.length }, (_, index) => index);

    const comb = combinations(arr);

    let max_win = 0;
    let max_comb;

    for(let i=0; i<comb.length; i++) {
        const A_dices = comb[i];
        const B_dices = comb[comb.length - i - 1];

        const a_arr = Array(dice[0].length).fill(0);
        for(const A_dice_idx of A_dices) {
           for(let i=0; i < dice[A_dice_idx].length; i++) {
                a_arr[i] += dice[A_dice_idx][i];
           }
        }

        const b_arr = Array(dice[0].length).fill(0);
        for(const B_dice_idx of B_dices) {
            for(let i=0; i < dice[B_dice_idx].length; i++) {
                b_arr[i] += dice[B_dice_idx][i];
           }
        }

        const [win, draw, lose] = compare(a_arr, b_arr);

        if(win > max_win) {
            max_win = win;
            max_comb = A_dices;
        }
    }

    let answer = max_comb.map(element => element + 1);
    return answer;
}

solution([[40, 41, 42, 43 ,44, 45], [43,43,42,42,41,41], [1,1,80,80,80,80], [70,70,1,1,70,70]])