#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int rotateAndSmallest(vector<vector<int>>& arr, int r1, int c1, int r2, int c2) {
    int smallest = arr[r1][c1];
    int temp = arr[r1][c1];
    int r, c;
    
    for(r = r1; r < r2; r++) {
        arr[r][c1] = arr[r + 1][c1];
        
        smallest = min(smallest, arr[r][c1]);
    }
    
    for(c = c1; c < c2; c++) {
        arr[r2][c] = arr[r2][c + 1];
        
        smallest = min(smallest, arr[r2][c]);
    }
    
    for(r = r2; r > r1; r--) {
        arr[r][c2] = arr[r - 1][c2];
        
        smallest = min(smallest, arr[r][c2]);
    }
    
    for(c = c2; c > c1; c--) {
        arr[r1][c] = arr[r1][c - 1];
        
        smallest = min(smallest, arr[r1][c]);
    }
    
    arr[r1][c1 + 1] = temp;
    
    return smallest; 
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> arr(rows, vector<int>(columns));
    
    for(int r = 0; r < rows; r++)
        for(int c = 0; c < columns; c++)
            arr[r][c] = r * columns + (c + 1);
    
    for(int i = 0; i < queries.size(); i++) {
        int smallNumber = 
            rotateAndSmallest(arr, queries[i][0] - 1, queries[i][1] - 1, queries[i][2] - 1, queries[i][3] - 1);
        
        answer.push_back(smallNumber);
    }

    return answer;
}