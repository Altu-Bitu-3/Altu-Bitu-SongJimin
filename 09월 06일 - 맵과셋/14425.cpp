#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m, cnt = 0;
    set<string> s;
    string str;
    cin >> n >> m;
    while (n--) {
        cin >> str;
        s.insert(str);
    }
    while (m--) {
        cin >> str;
        if (s.find(str) != s.end()) { //집합에 해당 문자열 있으면
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}