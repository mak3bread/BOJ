#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
   unsigned long long A,B,C;
    cin>>A>>B>>C;
   
    if(B>=C){
        cout<<-1<<'\n';
    }
    else{
   unsigned long long result=A/(C-B);
   cout<<result+1<<'\n';
    }
    return 0;
}
