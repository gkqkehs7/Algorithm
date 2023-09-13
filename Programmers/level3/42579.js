function solution(genres, plays) {

    // 각 곡의 순위를 매겨야 한다.
    let genre_hash = {};
    let genre_num = 0;
    for(let i=0; i<genres.length; i++) {
        let genre = genres[i];
    
        if(!genre_hash.hasOwnProperty(genre)) {
            genre_hash[genre] = genre_num;
            genre_num++;
        }
    }
    // console.log(genre_hash)

    let songs = Array(genre_num).fill(0);

    for(let i=0; i<genres.length; i++) {
        let genre = genres[i];
        let play = plays[i];

        songs[genre_hash[genre]] += play
    }

    for(let i=0; i<genre_num; i++) {
        songs[i] = [songs[i], i]
    }

    songs.sort((prev, next) => {
        return next[0] - prev[0]
    })

    let ranks = {};

    for(let i=0; i<genre_num; i++) {
        ranks[songs[i][1]] = i;
    }


    // console.log(ranks)

    let song_ranks = Array(genre_num).fill([]);
    for(let i=0; i<plays.length; i++) {
        let genre = genres[i];
        let play = plays[i];

        let rank = ranks[genre_hash[genre]];

        song_ranks[rank] = [...song_ranks[rank], [play, i]]
    }

    for(let i=0; i<song_ranks.length; i++) {
        song_ranks[i].sort((prev, next) => {
            return next[0] - prev[0]
        })
    }


    // console.log(song_ranks)
    let answer = [];

    for(let i=0; i<song_ranks.length; i++) {

        if(song_ranks[i].length < 2) {
            for(let j=0; j<song_ranks[i].length; j++) {
                answer.push(song_ranks[i][j][1])
            }
        } else {
            for(let j=0; j<2; j++) {
                answer.push(song_ranks[i][j][1])
            }
        }
       
    }

    // console.log(answer)

    return answer;
}

solution(["classic", "pop", "classic", "classic", "pop"], [500, 600, 150, 800, 2500])