#include <iostream>
// strlen 함수를 사용하기 위해서 해당 헤더를 불러와야 합니다.
#include <cstring>

using namespace std;
int main() {
    char arr[81];
    int sum = 0;
    int score = 0;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> arr;
        for (int i = 0; i < strlen(arr); i++) {
            if (arr[i] == 'O') {
                score++;
                sum += score;
            }
            else
                score = 0;
        }
        cout << sum << endl;
        sum = 0;
        score = 0;
    }
    return 0;
} 
