function timeToMinute(time) {
    let [hour, minute] = time.split(":");

    return parseInt(hour) * 60 + parseInt(minute);
}


function solution(m, musicinfos) {

    let answer_len = 0;
    let answer = '';

    for(let i=0; i<musicinfos.length; i++) {
        let musicinfo = musicinfos[i];
        let [startTime, endTime, name, song] = musicinfo.split(",");

        let time = timeToMinute(endTime) - timeToMinute(startTime)
        console.log(startTime, endTime, name, song, time)

        let total_song = "";
        if(song.length < time) {
            total_song = total_song + song.slice(0, time - song.length);
        } else if(song.length > time) {
            total_song = song.slice(0, time);
        } else {
            total_song = song; 
        }

        console.log(total_song, m);
        if(total_song.includes(m)) {
            console.log("includes!")
            if(total_song.length > answer_len) {
                answer_len = total_song.length;
                answer = name;
            }
        }
    }

    if(answer_len === 0) {
        return "(None)"
    }

    return answer;
}

solution("CC#BCC#BCC#BCC#B", ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"])