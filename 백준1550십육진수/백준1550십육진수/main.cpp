#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    char num[6]={0};
    cin>>num;
   
    int size=0;
    int result=0;
   
    for(int i=0;i<6;i++){
        if(num[i]!=0){
            size++;
        }
    }
   
    for(int i=0;i<size;i++){
        if((int)num[i]>=65){
            result+=((int)num[i]-55)*pow(16,size-i-1);
        }
        else{
            result+=((int)num[i]-48)*pow(16,size-i-1);
        }
    }
    
    cout<<result<<endl;
   
    
    return 0;
}
