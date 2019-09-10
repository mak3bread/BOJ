#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;
    unsigned long result=1;
   
   
        for(int i=1;i<=N;i++){
            result*=i;
        }
        cout<<result<<'\n';

    
    return 0;
}
