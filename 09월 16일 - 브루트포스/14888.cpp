#include <iostream>
#include <vector>
#include <algorithm>

//각 경우에 연산 최대 10번 수행. 경우는 4^6 보다 작음( 4 중복 순열 6)
//>>연산은 4만회 정도이므로 브루트포스로 구할 수 있다.

using namespace std;
const int MAX = 1e9;
const int MIN = -1e9;

pair<int, int> getMaxAndMin(int n, vector<int> &num, vector<char> &opArr) {
    pair<int, int> max_min;
    int result;
    max_min.first = MIN;
    max_min.second = MAX;
    //처음에 오름차순 정렬 안하면 틀림
    sort(opArr.begin(), opArr.end());
    do {
        result = num[0];
        for (int i = 1; i < n; i++) {
            if (opArr[i - 1] == '+') {
                result += num[i];
            } else if (opArr[i - 1] == '-') {
                result -= num[i];
            } else if (opArr[i - 1] == '*') {
                result *= num[i];
            } else if (opArr[i - 1] == '/') {
                result /= num[i];
            }
        }
        if (result > max_min.first) {
            max_min.first = result;
        }
        if (result < max_min.second) {
            max_min.second = result;
        }
    } while (next_permutation(opArr.begin(), opArr.end()));
    return max_min;
}


int main() {
    int n;
    cin >> n;

    vector<int> num(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    vector<int> opCnt(4, 0);
    for (int i = 0; i < 4; i++) {
        cin >> opCnt[i];
    }

    //연산 기호를 배열에 나열하기
    vector<char> opArr;

    char op = '+';

    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            op = '+';
        } else if (i == 1) {
            op = '-';
        } else if (i == 2) {
            op = '*';
        } else if (i == 3) {
            op = '/';
        }

        for (int j = 0; j < opCnt[i]; j++) {
            opArr.push_back(op);
        }
    }

    cout << getMaxAndMin(n, num, opArr).first << "\n";
    cout << getMaxAndMin(n, num, opArr).second;


    return 0;
}