#include <iostream>
using namespace std;

int main(){
    
    int a,b;
    cin>>a>>b;
    
    int sum=0;
    
    int arr[1000]={0};
   
    int j=1;
    int k=0;

    for(int i=0;i<1000;i++){
        if(j==k){
            j++;
            k=0;
        }
      
            
            arr[i]=j;
        k++;
    
    }
    
    for(int i=a-1;i<b;i++){
        sum+=arr[i];
    }
    
    cout<<sum<<endl;
    
    

    return 0;
}
