//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    int N,K;
//    cin>>N>>K;
//
//    if(N>=1&&N<=500&&K>=1&&K<=N){
//        int *arr=new int[N];
//        int sum=0;
//        int m=0;
//        for(int i=0;i<N;i++){
//            cin>>arr[i];
//            sum+=arr[i];
//        }
//        m=sum/N;
//
//        double sum_v=0;
//        double min=0;
//        for(int i=K;i<=N;i++){
//            for(int j=0;j<i+j;j++){
//            sum_v+=pow(arr[i]-m,2);
//            }
//        }
//        double v=sum_v/(double)3;
//
//        cout<<v<<'\n';
//
//        delete []arr;
//    }
//
//
//    return 0;
//}
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
#include<climits>
#include<queue>
#include<cfloat>
#include<iomanip>
using namespace std;

int main(void)
{
    
    int n, k;
    cin >> n >> k;
    int a[500];
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    double std = 0;
    double rst=0;
    double sum = 0;
    double avg = 0;
    
    for (int i = k; i <= n; i++) // k 이상
    {
        for (int j = 0; j < n - i + 1 ; j++)
        {
            for (int l = j; l < j+i; l++)
            {
                sum += a[l];
            }
            
            avg = sum / i;
            
            for (int l = j; l < j+i; l++)
            {
                std += pow(a[l] - avg, 2);
            }
            
            std /= i;
            
            if (i==k && j==0) rst = std;
            else rst = min(std, rst);
            
            std = 0;
            sum = 0;
        }
        
    }
    
    cout <<setprecision(11)<<sqrt(rst);
    
}

