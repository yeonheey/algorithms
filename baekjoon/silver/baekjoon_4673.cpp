#include <iostream>

using namespace std;

bool haveGenerator[10001] = {false, };

int sumOfNumber(int number) {
    int sum = number;
    
    while(number > 0) {
        sum += number % 10;
        number /= 10;
    }
    
    return sum;
}

int main() {
    for(int num = 1; num < 10000; num++) {
        int sum = sumOfNumber(num);
        
        if(sum < 10000) haveGenerator[sum] = true;
    }
    
    for(int i = 1; i < 10000; i++) {
        if (haveGenerator[i] == false) 
            cout << i << "\n";
    }
    
    return 0;
}