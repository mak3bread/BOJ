#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M,N;
    cin>>M>>N;
   
    bool arr[1000001];
    arr[0]=arr[1]=true;
    
    for(int i=2;i<=1000000;i++){
        if(arr[i]==false){
            for(int j=i+i;j<=1000000;j+=i){
                arr[j]=true;
            }
        }
    }
    
    for(int i=M;i<=N;i++){
        if(arr[i]==false){
        cout<<i<<'\n';
        }
    }
    
    return 0;
}
