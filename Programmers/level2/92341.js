function cal(fees, total_time) {
    const [basic_time, basic_money, plus_time, plus_money] = fees;

    if(total_time <= basic_time) {
        return basic_money;
    }

    total_time = total_time - basic_time;

    return basic_money + Math.ceil(total_time / plus_time) * plus_money
}


function solution(fees, records) {

    let arr = [];
    let times = [] // 값 있는지 여부 / 나간지 여부 / 들어온 시간 / 총 시간

    for(let i=0; i<10000; i++) {
        times.push([-1, -1, 0, 0]);
    }

    for(let i=0; i<records.length; i++) {
        let [time_str, car_str, type] = records[i].split(" ");

        let [hour, minute] = time_str.split(":");
        let time = parseInt(hour * 60) + parseInt(minute);
    
        let car_num = parseInt(car_str);

        if(times[car_num][0] === -1) {
            console.log(time, car_num, "in");

            times[car_num][0] = 1;
            times[car_num][1] = -1; 
            times[car_num][2] = time; 
        

        } else {
            if(type === "IN") { // 나갔다 다시 들어온놈
                console.log(time, car_num, "in");
                times[car_num][1] = -1;
                times[car_num][2] = time;
            } else if(type === "OUT") {
                console.log(time, car_num, "out");
                times[car_num][1] = 1;
                times[car_num][3] = times[car_num][3] + time - times[car_num][2];
            }
          
        }
    }

    let last_time = 1439;
    let answer = [];

    for(let i=0; i<10000; i++) {
        if(times[i][0] === 1) {

            if(times[i][1] === -1) {
                times[i][3] += last_time - times[i][2];
            }

            answer.push(cal(fees, times[i][3]))
            
        }
    }

    console.log(answer)
    return answer;
}


solution([180, 5000, 10, 600], ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"])