#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {

    vector<int> times;
    vector<int> bus_times;

    int start_time = 540;
    bus_times.push_back(start_time);

    for(int i = 0; i < n - 1; i++) {
        bus_times.push_back(start_time + t * (i + 1));
    }

    // timetable 숫자로 변경
    for(int i=0; i<timetable.size(); i++) {
        string time = timetable[i];

        size_t pos = time.find(":");
        string hour_str = time.substr(0, pos);
        string min_str = time.substr(pos + 1);

        int hour = stoi(hour_str);
        int min = stoi(min_str);

        int total_time = hour * 60 + min;

        times.push_back(total_time);
    }

    sort(times.begin(), times.end());

    int answer = 0;
    int count = 0;
    for(int i=0; i<bus_times.size(); i++) {

        int temp = 0;
        int last = 0;
        for(int j = count; j < times.size(); j++) {
            if(bus_times[i] >= times[j] && temp < m) {
                cout << bus_times[i] << "시 " << times[j] << "탑승" << "\n";
                last = times[j];
                count++;
                temp++;
            }
        }

        // 마지막 버스일때
        if(i == bus_times.size() - 1) {
            if(temp < m) {
                answer = bus_times[i];
            } else if (temp == m) {
                answer = last - 1;
            }
        }
    }

    int hour_num = answer / 60;
    int min_num = answer % 60;

    string answer_hour;
    string answer_min;

    if(hour_num < 10) {
        answer_hour = "0" + to_string(hour_num);
    } else {
        answer_hour = to_string(hour_num);
    }

    if(min_num < 10) {
        answer_min = "0" + to_string(min_num);
    } else {
        answer_min = to_string(min_num);
    }

    cout << answer_hour + ":" + answer_min;
    return answer_hour + ":" + answer_min;
}

int main() {
    vector<string> v = { "23:59","23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59" };
    solution(10, 60, 45, v);
}