#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<int>> map(501,vector<int>(501,0));
    vector<bool> visit(501,false);
    
    int count=0;
    int N,M;
    cin>>N;
    cin>>M;
    
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        map[a][b]=map[b][a]=1;
    }
    
    for(int i=2;i<=N;i++){
        if(map[1][i]==1||map[i][1]==1){
            for(int j=1;j<=N;j++){
                if(map[i][j]==1||map[j][i]){
                    visit[i]=visit[j]=true;
                }
            }
        }
    }
    
    for(int i=2;i<=N;i++){
        if(visit[i]){
            count++;
        }
    }
    
    cout<<count<<'\n';
    
    visit.clear();
    for(int i=0;i<501;i++){
        map[i].clear();
    }
    map.clear();
    
    return 0;
}
