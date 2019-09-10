#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string dal;
    cin>>dal;
    
    int sum=0;
    //번호2 3초
    
    for(int i=0;i<dal.size();i++){
        if(dal[i]=='A'||dal[i]=='B'||dal[i]=='C'){
            sum+=3;
            continue;
        }
        if(dal[i]=='D'||dal[i]=='E'||dal[i]=='F'){
            sum+=4;
            continue;
        }
        if(dal[i]=='G'||dal[i]=='H'||dal[i]=='I'){
            sum+=5;
            continue;
        }
        if(dal[i]=='J'||dal[i]=='K'||dal[i]=='L'){
            sum+=6;
            continue;
        }
        if(dal[i]=='N'||dal[i]=='M'||dal[i]=='O'){
            sum+=7;
            continue;
        }
        if(dal[i]=='P'||dal[i]=='Q'||dal[i]=='R'||dal[i]=='S'){
            sum+=8;
            continue;
        }
        if(dal[i]=='T'||dal[i]=='U'||dal[i]=='V'){
            sum+=9;
            continue;
        }
        if(dal[i]=='W'||dal[i]=='X'||dal[i]=='Y'||dal[i]=='Z'){
            sum+=10;
            continue;
        }
    }
    cout<<sum<<'\n';
    return 0;
}
