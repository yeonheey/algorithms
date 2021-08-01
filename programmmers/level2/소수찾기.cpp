#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    else if(n == 2 || n == 3) return true;
    
    for(int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    
    return true;
}

int solution(string numbers) {
    set<int> primes;
    vector<char> digits(numbers.begin(), numbers.end());
    
    sort(digits.begin(), digits.end());
    
    do {
        for(int n = 1; n <= numbers.size(); n++) {
            int number = 0;
            
            for(int i = 0; i < n; i++) 
                number += pow(10, i) * (digits[i] - '0');
            
            if(isPrime(number)) 
                primes.insert(number);
        }
        
    } while(next_permutation(digits.begin(), digits.end()) );
    
    return primes.size();
}