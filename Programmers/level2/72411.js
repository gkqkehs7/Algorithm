const combination = function (arr, selectNumber) {
    const results = [];
    if (selectNumber === 1) return arr.map((value) => [value]); 
  
    arr.forEach((fixed, index, origin) => {
      const rest = origin.slice(index + 1); 
      const combinations = combination(rest, selectNumber - 1); 
      const attached = combinations.map((combination) => [fixed, ...combination]); 
      results.push(...attached);
    });
  
    return results; 
  };

function solution(orders, course) {

    let words = {}

    for(let i=0; i<orders.length; i++) {
        let str_arr = orders[i].split('')

        str_arr.sort()

        for(let j=2; j<=str_arr.length; j++) {
            let result = combination(str_arr, j);

            for(let k=0; k<result.length; k++) {
                let result_str = result[k].join("");

                if(words.hasOwnProperty(result_str)) {
                    words[result_str] += 1;
                } else {
                    words[result_str] = 1;
                }
            }
            
        }
    }

    let courses = {};

    for(let i=0; i<course.length; i++) {
        courses[course[i].toString()] = [];
    }

    console.log(words)

    for(const key in words) {
        let key_len = key.length
        let value = words[key];

        if(value >= 2) {
            if(courses.hasOwnProperty(key_len.toString())) {
                if(courses[key_len.toString()].length === 0) {
                    courses[key_len.toString()].push({ key: key, value: value });
                } else {
                    if(courses[key_len.toString()][0].value < value) {
                        courses[key_len.toString()] = [{ key: key, value: value }];
                    } else if(courses[key_len.toString()][0].value === value) {
                        courses[key_len.toString()].push({ key: key, value: value });
                    }
                }
            } 
        }
        
    }


    console.log(courses)

    let answer = [];
    
    for(const key in courses) {
        for(let i=0; i<courses[key].length; i++) {
            answer.push(courses[key][i].key)
        }
    }

    answer.sort();

    return answer;
}


solution(["XYZ", "XWY", "WXA"], [2,3,4])