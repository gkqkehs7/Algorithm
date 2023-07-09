function solution(book_time) {

    for(let i=0; i<book_time.length; i++) {
        let [start, end] = book_time[i];

        let [start_hour, start_min] = start.split(":");
        let [end_hour, end_min] = end.split(":");

        book_time[i][0] = parseInt(start_hour) * 60 + parseInt(start_min);
        book_time[i][1] = parseInt(end_hour) * 60 + parseInt(end_min) + 10;
    }


    let rooms = [];
    rooms.push(-1);

    book_time.sort((prev, next) => { 
        if(prev[0] === next[0]) {
            return prev[1] - next[1];
        } 

        return prev[0] - next[0]
     
    })

    for(let i=0; i<book_time.length; i++) {

        let newroom = true;

        let start = book_time[i][0];
        let end = book_time[i][1];

        for(let j=0; j<rooms.length; j++) {
            let prev_end = rooms[j];

            if(start >= prev_end) {
                rooms[j] = end;
                newroom = false;
                break;
            }
        }

        if(newroom) {
            rooms.push(end);
        }
    }

    return rooms.length    
}


console.log(solution([["08:00", "08:30"], ["08:00", "13:00"], ["12:30", "13:30"]]))