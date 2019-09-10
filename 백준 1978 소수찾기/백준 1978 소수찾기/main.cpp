#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    int sum=0;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        int count=0;
        for(int j=2;j<=a;j++){
            if(a%j==0){count++;}
        }
        if(count==1){
            sum++;
        }
    }
    cout<<sum<<'\n';
    
    return 0;
}
