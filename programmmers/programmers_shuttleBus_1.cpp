//[1차]셔틀버스
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int change_min(string time, int add_time = 0) {
    int min_time = stoi(time.substr(0, 2)) * 60;
    min_time += stoi(time.substr(3, 2));
    
    return min_time + add_time;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int size = timetable.size();
    
    sort(timetable.begin(), timetable.end());
    
    vector<int> bus_time;
    for(int i = 0; i < n; i++) 
        bus_time.push_back(change_min("09:00", t * i));
    
    int point = 0;
    int con_time = 0;
    for(int i = 0; i < n; i++) { //각각 버스에 탈 수 있는 인원 확인
        int on_bus = 0;
        
        for(int j = point; j < size; j++) 
        {
            int arrive = change_min(timetable[j]);
            
            if(arrive <= bus_time[i])  //탈 수 있음
            {
                point++; on_bus++;
                
                if(on_bus == m) break;
            }
        }
        
        //last bus
        if(i == n - 1) 
        {
            if(on_bus == m)
                con_time = change_min(timetable[point - 1]) - 1;
            else
                con_time = bus_time[i];
        }
        
        if(bus_time[i] >= 24*60) break; //이미 퇴근
    }
    
    int hour = con_time / 60;
    int minute = con_time % 60;
    
    if(hour < 10) answer += "0";
    answer+= to_string(hour) + ":";
    
    if(minute < 10) answer += "0";
    answer += to_string(minute);
    
    return answer;
}