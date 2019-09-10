#include <iostream>
#include <string.h>

using namespace std;

int main(void) {
   
    int N;
    cin >> N;
    char arr[N][51];
    char result[51] ={0,};
    
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    int len = strlen(arr[0]);
  
    
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < N-1; j++) {
            if(arr[j][i] != arr[j+1][i]) {
                result[i] = '?';
                break;
            }
        }
        if(result[i] == 0)
            result[i] = arr[0][i];
    }
    
    cout<<result<<'\n';
    
    return 0;
}
