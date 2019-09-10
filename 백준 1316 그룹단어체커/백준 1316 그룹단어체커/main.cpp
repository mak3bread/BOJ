#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    int result =n;
    
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int alpha[26]={0};
        bool a=true;
        for(int j=1;j<s.length();j++){
            alpha[s[j-1]-97]++;
            if(s[j-1]!=s[j]){
                if(alpha[s[j]-97]!=0){
                         a=false;
                         break;
                         }
            }
        }
        
        if(a==false){result--;}

    }
    cout<<result<<'\n';
    return 0;
}
