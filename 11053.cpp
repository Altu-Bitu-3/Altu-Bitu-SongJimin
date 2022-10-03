#include <iostream>
#include <algorithm>

using namespace std;
// 수열 중 i번째 숫자보다 작은 수가 앞에 존재하면,
// i번째 dp수열의 원소와 해당 작은수의 dp수열 원소 +1의 값중 큰것 선택
// 그 뒤 가장 큰 값을 출력한다
int main(){
    int n;
    int dp[1000] = {};
    int arr[1000] = {};

    //입력
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;//길이는 최소 1

        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j]) //작은 수가 앞에 있다면
            {
                dp[i] = max(dp[i], dp[j] + 1); //j번 dp + 1 이 현재 dp보다 커야 증가하는 수열이라고 판단가능
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, dp[i]); //가장 긴 길이찾기
    }
        
    cout << ans;
    
    return 0;
}
