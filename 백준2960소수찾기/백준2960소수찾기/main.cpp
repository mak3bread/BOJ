#include <iostream>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    
    bool *num = new bool[N + 1];
    for (int i = 0; i <= N; i++){
        num[i] = true;
    }
    
    int erase_cnt = 0;

    if(K<=(N/2)){
        cout<<K*2<<endl;
        
    }
    
    else{
        for(int i=2;i<=N;i+=2){
            num[i]=false;
        }
        erase_cnt=N/2;
        
    for (int i = 3; i <= N; i++)
    {
        for (int j = 1; i*j <= N; j++)
        {
            if (num[i*j])
            {
                num[i*j] = false;
                erase_cnt++;
                if (erase_cnt == K)
                    cout << i*j << endl;
            }
        }
    }
    }
    delete[]num;
    
    return 0;
}

