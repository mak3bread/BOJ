#include <iostream>
using namespace std;

int main(){
    
    int N,M;
    cin>>N>>M;
    
    int **arr=new int*[N];
    
    for(int i=0;i<N;i++){
        arr[i]=new int[M];
    }
    
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    
    int K;
    cin>>K;
    
    int a,b,x,y;
   
    
    for(int i=0;i<K;i++){
         int sum=0;
        cin>>a>>b>>x>>y;
        for(int j=a-1;j<x;j++){
            for(int k=b-1;k<y;k++){
                sum+=arr[j][k];
            }
        }
        cout<<sum<<endl;
    }
    
    
    for(int i=0;i<N;i++){
        delete[] arr[i];
        
    }
    delete[] arr;
    
    return 0;
}
