#include <iostream>
#include <cstring>


using namespace std;

int main(){
    int arr[26]={0};
    char b[27]={"abcdefghijklmnopqrstuvwxyz"};
    
    char c[27]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    
    
    char a[1000000];
    cin>>a;
    
   

    for(int i=0;i<strlen(a);i++){
        
        for(int j=0;j<26;j++){
            
            if(a[i]==b[j]||a[i]==c[j]){
             
                arr[j]++;
            }
            
        }
    }
    int max=arr[0];
    int max_num=0;
    
    for(int i=1;i<26;i++){
        if(max<arr[i]){
            max=arr[i];
            max_num=i;
        }
    }
    
    int count=0;
    
    for(int i=0;i<26;i++){
        if(max==arr[i]){
            count++;
        }
        
    }

    if(count>=2){
        cout<<"?";
    }
    else{
        cout<<c[max_num];
    }
    
    
    return 0;
}
