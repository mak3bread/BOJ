#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int b[26];
    for(int i=0;i<26;i++){
        b[i]=-1;
    }
    int c[26]={0};
    for(int i=0;i<s.size();i++){
        for(int j=97;j<=122;j++){
            
            if((int)s[i]==j&&c[j-97]==0){
                b[j-97]=i;
                c[j-97]++;
                break;
            }
        }
    }
    for(int i=0;i<26;i++){
        cout<<b[i];
        if(i==25){
            cout<<'\n';
            break;
        }
        cout<<' ';
    }
    return 0;
}
