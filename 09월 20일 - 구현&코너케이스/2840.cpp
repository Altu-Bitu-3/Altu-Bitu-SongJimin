#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<char> wheel(n, '?'); //초기화

    int index;

    for (int i = 0; i < k; i++) {
        int count;
        char value;
        cin >> count >> value;
        if (i == 0) {
            wheel[0] = value;
            index = 0;
            continue;
        }
        index = (count + index) % n;

        //이미 다른 값이 들어있으면 오류
        if (wheel[index] != '?' && wheel[index] != value) {
            cout << "!";
            return 0;
        } else {
            wheel[index] = value;
        }

    }
    //같은 문자가 여러개 들어있으면 오류
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (wheel[i] != '?' && wheel[i] == wheel[j]) {
                cout << "!";
                return 0;
            }
        }
    }
    //출력
    for (int i = 0; i < n; i++) {
        cout << wheel[index];
        index--;
        if (index == -1) index = n - 1;
    }
    return 0;
}