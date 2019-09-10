#include <iostream>
#include <cstring>


using namespace std;

int main(){
    int arr[26]={0};
    char b[27]={"abcdefghijklmnopqrstuvwxyz"};
    
        char c[27]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    
    
    char *a=new char;
    cin>>a;
    
    int size=strlen(a);
    
    cout<<size<<endl;
    
    for(int i=0;i<strlen(a);i++){

        for(int j=0;j<26;j++){
        
            if(a[i]==b[j]||a[i]==c[j]){
                cout<<j;
                arr[j]++;
            }

        }
    }


    int temp=0;

    cout<<endl;
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(arr[i]>arr[j]){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=arr[j];
            }
        }
    }

    for(int i=0;i<26;i++){
        cout<<arr[i];
    }

    cout<<endl;


    return 0;
}
