#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 8;
int n, m;
vector<int> num(SIZE);
vector<int> input(SIZE);
vector<bool> check(SIZE);

void backTracking(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < cnt; i++) {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int temp = 0;
    //input선언 시에 size를 안 정하면 오류가 나고, size를 정하면 0으로 초기화가 되어 오름차순 정리시 0으로 앞이 채워져
    //아래와 같이 for문을 작성했습니다. for 0부터 n까지로 작성하고 싶다면 어떻게 해야하나요?
    for (int i = SIZE - n; i < SIZE; i++) {
        if (!check[i] && input[i] != temp) {
            //앞서 검사했던 숫자와 중복된 숫자는 스킵하기
            num[cnt] = input[i];
            temp = num[cnt];
            check[i] = true;
            backTracking(cnt + 1);
            check[i] = false;
        }

    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    sort(input.begin(), input.end());

    backTracking(0);
    return 0;
}