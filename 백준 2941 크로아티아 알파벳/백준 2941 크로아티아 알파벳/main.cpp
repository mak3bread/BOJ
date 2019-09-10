#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int sum = s.length();
    for (int i = 0; i < s.length() - 1; i++) {
        if ((s[i] == 'c' || s[i] == 's' || s[i] == 'z') && s[i + 1] == '=') sum--;
        else if ((s[i] == 'c' || s[i] == 'd') && s[i + 1] == '-') sum--;
        else if (s[i] == 'd'&&s[i + 1] == 'z'&&s[i + 2] == '=') sum --;
        else if ((s[i] == 'l'|| s[i] == 'n')&&s[i + 1] == 'j') sum--;
    }
    cout << sum;
    return 0;
}
