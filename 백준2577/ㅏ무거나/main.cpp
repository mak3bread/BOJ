#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a[10]={0};
    int A,B,C;
    cin>>A>>B>>C;
    int result=A*B*C;
    string b=to_string(result);
    
    for(int i=0;i<b.length();i++){
        for(int j=0;j<10;j++){
            if((int)b[i]-48==j){
                a[j]++;
                break;
            }
        }
    }
    for(int i=0;i<10;i++){
        cout<<a[i]<<'\n';
    }
    
    return 0;
}
