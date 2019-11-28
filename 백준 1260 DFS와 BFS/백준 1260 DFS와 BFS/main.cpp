#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N,M,V;
vector<vector<int>> grap(1001,vector<int>(1001,0));
vector<int> v(1001,0);

void dfs(int x){
    if(v[x]==1)return;
    v[x]=1;
    cout<<x<<' ';
    for(int i=1;i<=N;i++){
        if(v[i]==1||grap[x][i]==0){continue;}
     dfs(i);
    }
}

void bfs(int x){
    queue<int>q;
    q.push(x);
    v[x]=0;
    while(!q.empty()){
        x=q.front();
        cout<<x<<' ';
        q.pop();
        for(int i=1;i<=N;i++){
            if(v[i]==0||grap[x][i]==0){continue;}
            q.push(i);
            v[i]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>N>>M>>V;
    
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        grap[a][b]=1;
        grap[b][a]=1;
    }
    
    dfs(V);
    cout<<'\n';
    bfs(V);
    cout<<'\n';
    
    return 0;
}
