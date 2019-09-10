//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int main(){
//
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    int T;
//    cin>>T;
//
//    if(T<=100){
//        for(int j=0;j<T;j++){
//
//        int N;
//        cin>>N;
//        if(N>=1&&N<=100){
//            char a[N][1001];
//            char O[1001];
//            char X[1001];
//
//
//            int cnt=0;
//
//            for(int i=0;i<N;i++){
//                cin>>a[i];
//            }
//            cin>>O;
//            cin>>X;
//            char answer[N][strlen(X)];
//
//            bool corr[N];
//            for(int i=0;i<N;i++){
//                corr[i]=true;
//            }
//
//            for(int i=0;i<N;i++){
//
//                if(strlen(a[i])!=strlen(O)){
//                    corr[i]=false;
//                    continue;
//                }
//                    for(int t=0;t<strlen(a[i]);t++){
//                    for(int k=t+1;k<strlen(a[i]);k++){
//                        if(O[t]==O[k]){
//                            if(a[i][t]!=a[i][k]){
//                                corr[i]=false;
//                                continue;
//                            }
//                        }
//                        if(a[i][t]==a[i][k]){
//                            if(O[t]!=O[k]){
//                                corr[i]=false;
//                            }
//                        }
//                    }
//                    }
//
//                }
//            for(int i=0;i<N;i++){
//                if(corr[i]==false){cnt++;}
//            }
//            if(cnt==N){
//                cout<<"IMPOSSIBLE"<<'\n';
//                continue;
//            }
//            for(int i=0;i<N;i++){
//                if(corr[i]==false){continue;}
//                for(int k=i+1;k<N;k++){
//                    if(corr[k]==false){continue;}
//                    for(int t=0;t<strlen(a[i]);t++){
//                        if(a[i][t]!=a[k][t]){
//                            O[t]='?';
//                        }
//                    }
//                }
//            }
//            for(int i=0;i<N;i++){
//                if(corr[i]==false){
//                    continue;
//                }
//
//                for(int k=0;k<strlen(X);k++){
//                    for(int t=0;t<strlen(a[i]);t++){
//                        if(X[k]==a[i][t]){
//                            answer[i][k]=O[t];
//                            break;
//                        }
//                        else if(X[k]!=a[i][t]){
//                            answer[i][k]='?';
//                        }
//                    }
//                }
//            }
//            bool imp=false;
//            for(int i=0;i<N;i++){
//                if(corr[i]==false){continue;}
//                for(int k=0;k<strlen(answer[i]);k++){
//                    if(answer[i][k]!='?'){
//                        imp=true;
//                    }
//                }
//            }
//            if(imp==false){
//                cout<<"IMPOSSIBLE"<<'\n';
//                continue;
//            }
//            char result[strlen(X)];
//            for(int i=0;i<N;i++){
//                if(corr[i]==false){continue;}
//                for(int k=0;k<strlen(X);k++){
//                result[k]=answer[i][k];
//                }
//                break;
//            }
//            cout<<result<<'\n';
//            }
//        }
//        }
//    return 0;
//}
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>//memset함수를 사용하기 위해 include. ex)memset(chk,0,sizeof(chk))
using namespace std;
struct match{//구조체선언. 매칭된문자들을 벡터에 저장해줌.
    char a[26];
    
    match(char arr[])
    {
        
        for(int i=0;i<26;i++)
        {
            a[i]=arr[i];
        }
    }
    
};
vector<match> v;//벡터 변수 전역으로 선언.
void compare(string encod,string uncod)//매칭시키기 위해 배열을 두개 받음. encod는 암호화된문장 uncod는 해독한문장.
{
    if(encod.length()!=uncod.length())//문자열의 길이가 같지 않으면 바로 리턴.
        return;
    int temp[26]={0,};
    char com[26];
    char com2[26];
    memset(com,0,26*sizeof(char));//com배열을 0으로 초기화.
    memset(com2,0,26*sizeof(char));
    for(int i=0;i<encod.length();i++)
    {
        if(com[encod[i]-'a']==0)//만약com[encod[i]]원소가 비어있으면.
            com[encod[i]-'a']=uncod[i];
        else if(com[encod[i]-'a']!=0) {//만약해당하는 인덱스의 원소가 비어있지않다면? 즉 있는데 또넣으면?  1대1 매칭불가능.
            if(com[encod[i]-'a']!=uncod[i])
                return;
        }
    }
    for(int i=0;i<encod.length();i++)
    {
        if(com2[uncod[i]-'a']==0)//만약com[encod[i]]원소가 비어있으면.
            com2[uncod[i]-'a']=encod[i];
        else if(com2[uncod[i]-'a']!=0) {//만약해당하는 인덱스의 원소가 비어있지않다면? 즉 있는데 또넣으면?  1대1 매칭불가능.
            if(com2[uncod[i]-'a']!=encod[i])
                return;
        }
    }
    
    v.push_back(com);
    
    
}
void compare2(string sol,string uncod)//해독할문장에 매칭 시켜주는 함수.
{
    char to_sol[26];
    char un_cod[26];
    int temp[26];
    memset(temp,0,26*sizeof(int));
    memset(to_sol,'?',26*sizeof(char));
    memset(un_cod,0,26*sizeof(char));
    for(int i=0;i<v.size();i++)//v에 들어잇는 배열들을 다 탐색.
    {
        for(int j=0;j<26;j++)
        {
            for(int k=0;k<uncod.length();k++)
            {
                if(v[i].a[j]==uncod[k])
                {
                    if(un_cod[uncod[k]-'a']==0)
                    {
                        un_cod[uncod[k]-'a']=(char)(j+97);
                        to_sol[j]=uncod[k];
                    }
                    else if(un_cod[uncod[k]-'a']!=0){
                        if(un_cod[uncod[k]-'a']!=char(j+97))
                        {
                            to_sol[j]='?';
                            to_sol[un_cod[uncod[k]-'a']-'a']='?';
                        }
                    }
                }
            }
        }
    }
    int count=0;
    for(int i=0;i<26;i++)
    {
        if(to_sol[i]!='?')
            count++;
    }
    if(count==25)
    {
        int index;
        for(int i=0;i<26;i++)
        {
            if(to_sol[i]!='?')
                temp[(int)to_sol[i]-97]=1;
            if(to_sol[i]=='?')
                index=i;
        }
        for(int i=0;i<26;i++)
        {
            if(temp[i]==0)
                to_sol[index]=(char)(i+97);
        }
    }
    for(int i=0;i<sol.length();i++)
    {
        cout<<to_sol[sol[i]-'a'];
    }
    
}
int main(void)
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int N;
        cin>>N;
        string str[N],uncod,sol;//해독된 문장,해독할 문장.
        for(int j=0;j<N;j++)
        {
            cin>>str[j];
        }
        cin>>uncod;
        cin>>sol;
        for(int j=0;j<N;j++)
        {
            compare(str[j],uncod);
        }
        if(v.size()==0)
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        compare2(sol,uncod);
        v.clear();
        cout<<endl;
    }
}

