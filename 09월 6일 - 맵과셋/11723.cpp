#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


void cal(vector<int> &arr, string op) {
    int x;
    if (op == "add") {
        cin >> x;
        //S에 x가 없을때만 add 수행
        if (arr[x - 1] == 0) {
            arr[x - 1] = x;
        }
    } else if (op == "remove") {
        cin >> x;
        //S에 x가 있을때만 remove 수행
        if (arr[x - 1] != 0) {
            arr[x - 1] = 0;
        }
    } else if (op == "check") {
        cin >> x;
        //S에 x가 있다면 1 출력, 없다면 0 출력
        if (arr[x - 1] != 0) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    } else if (op == "toggle") {
        cin >> x;
        if (arr[x - 1] != 0) {
            //set에 x가 있으면
            arr[x - 1] = 0;
        } else {
            //없으면
            arr[x - 1] = x;
        }
    } else if (op == "all") {
        for (int i = 1; i <= 20; i++) {
            arr[i - 1] = i;
        }
    } else if (op == "empty") {
        fill(arr.begin(),arr.end(),0);
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string op;
    vector<int> arr(20, 0);
    //원소가 1~20까지고, 중복이 없으니, 크기가 20인 배열로 지정된 위치에 값을 저장,삭제한다.
    cin >> n;


    while (n--) {
        cin >> op;
        cal(arr, op);

    }
    return 0;
}
