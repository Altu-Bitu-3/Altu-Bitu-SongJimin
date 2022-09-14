#include <iostream>
#include <vector>

using namespace std;

void stringToArray(string s, vector<int> &arr) { //뒤에서 부터 저장해서 남는 앞자리에 0채우기

    for (int i = 0; i < s.length(); i++) {
        arr[arr.size() - 1 - i] = s.at(s.length() - 1 - i) - 48;
        //문자>> 숫자로 바꾸기 위해 -48
    }
}

void add(vector<int> arrA, vector<int> arrB, int size) {
    vector<int> result(size);
    int sum = 0, carry = 0;
    for (int i = size - 1; i >= 0; i--) {
        sum = arrA.at(i) + arrB.at(i) + carry;
        carry = 0;
        if (sum >= 10) {
            carry++;
            sum -= 10;
        }
        result[i] = sum;
    }
    //출력
    //올림이 없어서 맨앞에 0하나 남는 경우 제외하고 출력
    if (result[0] == 0) {
        for (int i = 1; i < size; i++) {
            cout << result[i];
        }
    } else {
        for (int i = 0; i < size; i++) {
            cout << result[i];
        }
    }


}

int main() {

    string a, b; //입력값이 너무 크므로 두 정수를 문자열로 저장한다.
    cin >> a >> b;

    //(길이가 더 긴 스트링의 길이 +1)=최종 합산 값의 길이를 크기로 가지는 두개의 배열 생성, 문자열 배열로 저장
    // 054321, 00321 처럼 각 숫자를 저장
    // 뒷자리 부터 각 자리수 덧셈

    int size = a.length() + 1;
    if (a.length() < b.length()) {
        size = b.length() + 1;
    }

    vector<int> arrA(size, 0), arrB(size, 0);

    stringToArray(a, arrA);
    stringToArray(b, arrB);
    add(arrA, arrB, size);


    return 0;
}
