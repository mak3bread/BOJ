#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++){
        int R;
        cin>>R;
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++){
            int count =0;
            while(count<R){
                cout<<s[i];
                count++;
            }
        }
        cout<<'\n';
    }
    return 0;
}
