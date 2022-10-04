#include <iostream>
//입출력헤더
#include <vector>
//벡터 헤더
#include <algorithm>
//max사용을 위한 헤더

using namespace std;
//std라이브러리 사용

/*
* 동적프로그래밍을 이용하여 값을 업데이트
* 더미 인덱스를 사용하여 예외 없이 한 번에 처리
* max(): 두 개 이상의 값을 비교할 때는 {}로 묶기
*/

int maxCandy(int n, int m, vector<vector<int>>dp) //maxCandy 함수 선언
{
    // 동적 계획법으로 사탕의 개수 계산
    for (int i = 1; i <= n; i++) {
        //i를 n까지 증가시키며 반복
        for (int j = 1; j <= m; j++) {
            //j증가시키며 반복
            dp[i][j] += max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }); // 가장 큰 값으로 업데이트
        }
    }
    return dp[n][m]; //가장 큰 값 리턴
}

int main()
{
    // 입력
    int n, m;//n,m선언
    cin >> n >> m;//n,m 입력받기
    vector<vector<int>> maze(n + 1, vector<int>(m + 1, 0)); // 0으로 초기화한 벡터 선언
    //벡터 채우기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maze[i][j];
        }
    }
    // 연산 & 출력
    cout << maxCandy(n, m, maze);
    return 0;
}
