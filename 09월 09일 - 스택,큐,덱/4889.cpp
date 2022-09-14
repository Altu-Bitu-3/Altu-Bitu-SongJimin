#include <iostream>
#include <stack>

using namespace std;
// 스택에 들어있는게 없는데 닫힌 괄호가 와서 팝을 해야할때 연산
// 문자열 끝까지 돌았을때, 스택 크기의 절반 만큼 연산 (스택의 크기가 홀수인 경우는 안정될수없음)

int stableCnt(string &s) {
    int cnt = 0;
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') {
            st.push('{');
        } else if (s[i] == '}') {
            if (st.empty()) {
                cnt++;
                st.push('{');
            } else {
                st.pop();
            }

        }
    }
    if (!st.empty()) {
        cnt += st.size() / 2;
    }
    return cnt;
}

int main() {
    string s;
    int i = 1;

    while (getline(cin, s)) {
        if (s[0] == '-') {
            break;
        }
        cout << i << ". " << stableCnt(s) << "\n";
        i++;
    }


    return 0;
}