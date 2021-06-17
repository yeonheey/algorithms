class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result(n, "");
        
        for(int i = 3; i <= n; i+=3)
            result[i - 1].append("Fizz");
        
        for(int i = 5; i <= n; i+=5)
            result[i - 1].append("Buzz");
        
        for(int i = 0; i <= n; i++)
            if(i % 3 != 0 && i % 5 != 0) 
                result[i - 1] = to_string(i);
        
        return result;
    }
};