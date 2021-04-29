#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
	vector<int> sortedList;
    queue<int> printer;

    int size = priorities.size();

    for(int i = 0; i < size; i++)
        printer.push(i);
    
    //sortedList priority에 따라 넣기
    while(!printer.empty())
    {
        int currentIndex = printer.front();
        printer.pop();

        if( priorities[currentIndex] != *max_element(priorities.begin(), priorities.end()) )
        {
            printer.push(currentIndex);
            continue;
        }

        sortedList.push_back(currentIndex);
        priorities[currentIndex] = 0;
    }
    
    //printList에서 location찾기
    for(int i = 0; i < size; i++)
        if(sortedList[i] == location)
            return i + 1;

    //없는 경우
    return -1;
}