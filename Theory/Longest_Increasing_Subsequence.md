### 최장 증가 부분 수열 알고리즘
#### LIS(Longest Increasing Subsequence)란?
원소가 n개인 배열의 일부 원소를 골라내서 만든 부분 수열 중,
<br />
각 원소가 이전 원소보다 크다는 조건을 만족하고 그 길이가 최대인 부분 수열을 뜻한다.
<br />
<br />
##### 예시)
    배열 {6, **2** , **5** , 1, **7** , 4, **8** , 3} → {2, 5, 7, 8} 이 LIS가 된다.
<br />

##### 최장 증가 부분 수열의 길이를 푸는 간단한 방법 : DP
```c++
for(int i = 0; i < n; i++) {
    dp[i]  = 1;
    for(int j = 0; j < i; j++) {
        if(arr[j] < arr[i]) {
            dp[i] = max(dp[i], dp[j] + 1);
        }
    }
}
```
<br />
주어진 배열에서 인덱스를 한칸씩 증가시키면서 확인한다.  
<br />
그리고 내부 반복문으로 i보다 작은 인덱스들을 하나씩 살펴보면서 현재 인덱스의 값(arr[i]) 보다 작은 것이 있으면 dp[i]를 갱신해준다.
<br />

갱신기준)
* (1) j 번째 인덱스에서 끝나는 LIS의 마지막에 arr[i] 추가했을 때의 LIS 길이
* (2) 추가하지 않고 기존 dp[i] 값
* (1)과 (2) 중 더 큰 값으로 dp[i]를 갱신한다.

주의 점) 
* 시간복잡도 : O(n^2) 
* 입력 값이 100개 정도 이하 일때 사용

<br />

##### 최장 증가 부분 수열을 푸는 방법: Binary Search
입력값이 많을 때 시간 복잡도를 줄이기 위해서 사용한다. → O(n logn)
<br />
DP와 동일하게 배열에서 인덱스를 한 칸씩 증가하면서 그 숫자가 들어갈 위치를 이분 탐색을 통해 넣는다.
<br />
숫자를 해당 위치에 넣어 완성된 배열이 곧 LIS 이다.
<br />

```c++
int binarySerach(int left, int right, int target) {
    int mid;
    
    while(left <= right) {
        mid = (left + right) / 2;
        
        if(list[mid] < target) 
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return mid;
}

int main() {
    int arr[];
    int dp[]; // LIS 저장하는 배열
    
    dp[0] = arr[0];
    int j = 0; // LIS의 인덱스
    
    for(int i = 0; i < n; i++) {
        if(dp[j] < arr[i]) {
            list[++j] = arr[i];
        }
        else {
            int idx = binarySearch(0, j, arr[i]);
            list[idx] = arr[i];
        }
    }
    
    cout << j + 1 << "\n";
    
    return 0;
}
```
