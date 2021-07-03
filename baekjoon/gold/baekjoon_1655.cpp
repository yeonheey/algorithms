#include <queue>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int> > minpq; 
    priority_queue<int> maxpq;

    for(int i = 0; i < N; i++) {
        int number;
        cin >> number;

        //maxheap의 크기가 1만큼 더 커야함
        if(maxpq.size() == minpq.size()) 
            maxpq.push(number);
        else
            minpq.push(number);
        
        if(!maxpq.empty()&& !minpq.empty())
            if(maxpq.top() > minpq.top()) {
                int maxValue = maxpq.top();
                int minValue = minpq.top();

                maxpq.pop(); minpq.pop();

                maxpq.push(minValue);
                minpq.push(maxValue);
            }

        cout<< maxpq.top() << "\n";
    }

    return 0;
}