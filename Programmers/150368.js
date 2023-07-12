function buy_plus_emoticon(user_data, emoticons, sale_ratio) {

    const [ratio, money] = user_data;

    let total_money = 0;
    for(let i=0; i<emoticons.length; i++) {
        if(sale_ratio[i] >= ratio) {
            total_money += (emoticons[i] * (100 - sale_ratio[i])) / 100;
        }
    }

    if(total_money >= money) { // plus 이모티콘 구매
        return -1;
    }
    
    return total_money; 
}

function solution(users, emoticons) {

    const ratios = [10, 20, 30, 40];
    const sale_ratios = [];
  
    function comb(currentCombination, currentIndex) {
      if (currentIndex === emoticons.length) {
        sale_ratios.push(currentCombination);
        return;
      }
  
      for (let i = 0; i < ratios.length; i++) {
        const newValue = ratios[i];
        const newCombination = currentCombination.concat(newValue);
        comb(newCombination, currentIndex + 1);
      }
    }

    comb([], 0);

    let results = [];

    for(const sale_ratio in sale_ratios) {

        let result = { plus: 0, money: 0 };
        for(const user in users) {
            const money = buy_plus_emoticon(users[user], emoticons, sale_ratios[sale_ratio])

            if(money == -1) {
                result.plus += 1;
            } else {
                result.money += money;
            }
        }

        results.push(result);
    }

    results.sort((a,b) => {
        if(a.plus === b.plus) {
            return b.money - a.money;
        }

        return b.plus - a.plus 
    })

    return [results[0].plus, results[0].money]

}

solution([[40, 10000], [25, 10000]], [7000, 9000]);