#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    
    string pw_key;
    cin>>pw_key;
 
    
    for(int i=0;i<s.length();i++){
        if((int)s[i]==32){
            cout<<s[i];
            continue;
        }
        int a=(int)pw_key[i%pw_key.length()]%96;
        if((int)s[i]-a<=96){
            s[i]=(int)s[i]-a+26;
            cout<<s[i];
            continue;
        }
        s[i]=s[i]-a;
        cout<<s[i];
    }
    
    return 0;
}
