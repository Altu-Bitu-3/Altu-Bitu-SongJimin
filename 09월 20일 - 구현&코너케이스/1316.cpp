#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, answer = 0;
    cin >> n;
    while (n--) {
        string word;

        cin >> word;
        vector<char> arr(word.length(), 0);

        //인접한 알파벳이 다르면 배열에 넣기
        arr[0] = word[0];
        int k = 1;
        for (int i = 1; i < word.length(); i++) {
            if (word[i] != word[i - 1]) {
                arr[k] = word[i];
                k++;
            }
        }

        bool isGroup = true;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] == arr[j]) {
                    isGroup = false;
                    break;//배열에 중복된 문자가 있으면 개수 세지않기
                }
            }
        }
        //for문 모두 지나치면 개수 증가
        if (isGroup == true) {
            answer++;
        }

    }
    cout << answer;
    return 0;
}
