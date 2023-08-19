function timeToMinute(time) {
    let [hour, minute] = time.split(":");

    return parseInt(hour) * 60 + parseInt(minute);
}


function solution(m, musicinfos) {

    let answer_len = 0;
    let answer = '';

    m = m
    .replace(/(C#)/g, "c")
    .replace(/(D#)/g, "d")
    .replace(/(F#)/g, "f")
    .replace(/(G#)/g, "g")
    .replace(/(A#)/g, "a");

    for(let i=0; i<musicinfos.length; i++) {
        let musicinfo = musicinfos[i];
        let [startTime, endTime, name, song] = musicinfo.split(",");

        let time = timeToMinute(endTime) - timeToMinute(startTime)
        // console.log(startTime, endTime, name, song, time)

        let total_song = "";
        if(song.length < time) {
            let attach_count = parseInt(time / song.length);
            let temp = attach_count;

            while(temp--) {
                total_song = total_song += song;
            }

            total_song += song.slice(0, parseInt(time % song.length));

        } else if(song.length > time) {
            total_song = song.slice(0, time);
        } else {
            total_song = song; 
        }
       
        if(total_song === "") {
            continue;
        }

        total_song = total_song
        .replace(/(C#)/g, "c")
        .replace(/(D#)/g, "d")
        .replace(/(F#)/g, "f")
        .replace(/(G#)/g, "g")
        .replace(/(A#)/g, "a");

        // let isSame = total_song.indexOf(m);

        if(total_song.includes(m)) {
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

console.log(solution("ABCDEFG", ["12:00,12:00,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]))