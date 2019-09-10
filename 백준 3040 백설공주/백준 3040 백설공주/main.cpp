#include <iostream>
using namespace std;

int main(){
    int a[9]={0};
    
    
    for(int i=0;i<9;i++){
        cin>>a[i];
    }
    
    int sum=0;
    int count=0;
    
    for(int i=0;i<9;i++){
        sum+=a[i];
    }
    int b[7]={0};
    int arr_count=0;
    
    for(int i=0;i<9;i++){
        arr_count=0;
        for(int j=0;j<9;j++){
            if(i==j)
                continue;
            if((sum-(a[i]+a[j]))==100){
                count++;
                
                for(int k=0;k<9;k++){
                    if(k==i||k==j){
                        continue;
                    }
                    
                        b[arr_count]=a[k];
                        arr_count++;
                    
                }
            }
        }
    }
    if(count==2){
        for(int i=0;i<7;i++){
            cout<<b[i]<<endl;
        }
    }
 return 0;
}
