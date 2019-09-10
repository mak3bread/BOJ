#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int M,N;
    cin>>M>>N;
    int *arr=new int[N-M+1];
    
    for(int i=M;i<=N;i++){
        int count=0;
        for(int j=2;j<i;j++){
            if(i%j==0){count++;}
        }
        if(count==0){
            if(i==1){
                arr[i-M]=0;
            }
            else{
            arr[i-M]=i;
            }
        }
        else{
            arr[i-M]=0;
        }
    }
    int sum=0;
    
    for(int i=0;i<=N-M;i++){
        if(arr[i]!=0){
            sum+=arr[i];
        }
    }
    
    if(sum==0){cout<<-1<<'\n';}
    else{
        cout<<sum<<'\n';
        for(int i=0;i<=N-M;i++){
            if(arr[i]!=0){
                cout<<arr[i]<<'\n';
                break;
            }
    }
}
    delete []arr;
    return 0;
}
