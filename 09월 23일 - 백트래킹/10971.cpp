#include <iostream>
//c++ 입출력헤터
#include <vector>
//vector헤더

using namespace std;
//std라이브러리 사용
const int INF = 1e8;
//행렬의 각 원소는 1e6을 최댓값으로 가지고, 도시의 수 n의 최댓값은 10이므로 10개도시를 방문했을때 최대 비용은 -> 1e7

vector<bool> visited;
//방문 검사 배열
vector<vector<int>> matrix;
//비용 행렬
int n, ans = INF;
//최소 비용 저장 위해 미리 최댓값으로 초기화

void backtracking(int cnt, int cur_city, int cost) {
    //파라미터로 도시방문횟수, 현재도시, 비용을 받는 backtracking함수
    if (cost >= ans) {
        //비용이 현재까지 검사한 최소비용보다 크다면
        return;
        //리턴, 함수 종료
    }
    if (cnt == n) {
        //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) {
            //현재도시에서 0번 도시로의 비용이 0이 아니라면 -> 출발점으로 복귀 가능
            ans = min(ans, cost + matrix[cur_city][0]);
            //최소 비용 결정하기
        }
        return;
        //종료
    }
    for (int i = 0; i < n; i++) {
        //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) {
            //길이 있고, 아직 방문하지 않은 도시라면
            visited[i] = true;
            //방문함으로 표시
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]);
            //방문 도시 개수 하나 올리고, 방금 방문한 도시로 부터 다시 출발, 현재까지 비용 합에 비용 더해주기
            visited[i] = false;
            //그 다음 탐색을 위해 방문여부 false로 바꿔주기
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {

    //입력
    cin >> n;
    //도시 개수 입력받기
    visited.assign(n, false);
    //방문 여부 체크 배열 false로 초기화
    matrix.assign(n, vector<int>(n, 0));
    //비용 행렬 값 모두 0으로 초기화
    for (int i = 0; i < n; i++) {
        //row 증가시키며 반복
        for (int j = 0; j < n; j++) {
            //col 증가시키며 반복
            cin >> matrix[i][j];
            //행렬의 각 원소에 비용값 입력 받기
        }
    }

    //연산
    visited[0] = true;
    //0번 도시에서만 시작, 0번도시 방문함
    backtracking(1, 0, 0);
    //1개도시 방문상태, 현재 도시는 0번, 비용은 0 을 인자로하여 함수 호출.

    //출력
    cout << ans;
    //최소비용 출력
    return 0;
    //프로그램 종료
}