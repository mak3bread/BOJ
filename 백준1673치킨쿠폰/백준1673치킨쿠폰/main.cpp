#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n,k,temp;
    
    while(cin>>n>>k){
    int sum=n;
    
    while(n/k>0){
        temp=n/k;
        sum+=temp;
        n%=k;
        n+=temp;
    }
    cout<<sum<<"\n";
    }
    return 0;
}
