#include <iostream>
using namespace std;

int main(){
    
    string arr;
    cin>>arr;
    

    
    
    for(int i=0;i<arr.length();i++){
        int temp;
        for(int j=0;j<arr.length();j++){
        if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            
        }
        }
    }
    
    for(int i=0;i<arr.length();i++){
        cout<<arr[i];
    }
    
    cout<<endl;
    return 0;
}
