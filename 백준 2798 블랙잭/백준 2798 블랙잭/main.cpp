#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N,M;
    cin>>N>>M;
    
    int *arr=new int[N];
    
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
   
    int count=0;
    int sum=0;
    int max=arr[0]+arr[1]+arr[2];
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){continue;}
            for(int k=0;k<N;k++){
                sum=0;
                if(i==k||j==k){continue;}
                sum+=arr[i]+arr[j]+arr[k];
                if(sum<=M&&count==0){
                    max=sum;
                    count++;
                }
                if(sum<=M&&max<=sum){
                    max=sum;
                }
            }
        }
    }
    
    cout<<max<<'\n';
    delete []arr;
    return 0;
}
