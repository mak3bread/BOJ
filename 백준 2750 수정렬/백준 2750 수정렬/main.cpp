#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int i=0;
    
    int *arr=new int[N];
    
    for(i=0;i<N;i++){
        cin>>arr[i];
    }
    
    int min=0;
    
    for(int j=0;j<N;j++){
    for(i=0;i<N;i++){
        if(arr[j]<arr[i]){
            min=arr[j];
            arr[j]=arr[i];
            arr[i]=min;
        }
    }
    }
    
    for(i=0;i<N;i++){
        cout<<arr[i]<<endl;
    }
    
    return 0;
}
