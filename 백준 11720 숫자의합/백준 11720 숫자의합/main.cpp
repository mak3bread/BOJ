#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;
    string s;
    cin>>s;
    int result=0;
    for(int i=0;i<N;i++){
        result+=(int)s[i]-48;
    }
    cout<<result<<'\n';
    
    return 0;
}
