#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin,s);
    int count=0;
//    int len=s.length();
//    //빈공간 32
//    s[len]='\n';

    for(int i=0;i<s.size();i++){
        if((int)s[i]==32&&i!=0&&i!=s.size()-1){
            count++;
        }
    }
    if(s.length()==1&&(int)s[0]==32){
        cout<<"0"<<'\n';
    }
    else{
    cout<<count+1<<'\n';
    }
    return 0;
}
