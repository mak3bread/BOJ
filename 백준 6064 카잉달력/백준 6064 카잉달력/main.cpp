//#include <iostream>
//using namespace std;
//
//long LCM(long a,long b){
//    long gcd=0;
//    long x=0,y=0;
//    if(a>b){
//         x=a;
//         y=b;
//    }
//    if(b>a){
//        x=b;
//        y=a;
//    }
//    if(a==b){
//        return a;
//    }
//    while(y!=0){
//
//        gcd=x%y;
//        x=y;
//        y=gcd;
//    }
//   long lcm=a*b/x;
//    return lcm;
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    int T;
//    cin>>T;
//
//    for(int i=0;i<T;i++){
//    long M,N,x,y;
//    cin>>M>>N>>x>>y;
//        long lcm=LCM(M,N);
//        long ans=0;
//        if(x==y){
//            cout<<x<<'\n';
//        }
//        else{
//            if(x>M||y>N){
//                cout<<-1<<'\n';
//            }
//            else{
//                long i=2;
//                long j=M+x;
//                while(lcm>j){
//                    if(j%M==x&&j%N==y){
//                        ans=j;
//                        break;
//                    }
//                    j=M*i+x;
//                    i++;
//                }
//                if(ans==0){
//                    cout<<-1<<'\n';
//                }
//                else{
//                    cout<<ans<<'\n';
//                }
//            }
//        }
//    }
//    return 0;
//}


#include <iostream>
#include <algorithm>
using namespace std;

int M, N, x, y;

//최대 공약수
int GCD(int a, int b)
{
    if (a % b == 0)
        return b;
    
    return GCD(b, a % b);
}

//최소 공배수
int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); //실행속도 향상
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++)
    {
        cin >> M >> N >> x >> y;
        
        int maxYear = LCM(M, N);
        
        while (1)
        {
            if (x > maxYear || (x - 1) % N + 1 == y)
                break;
            
            x += M; //M으로 나눈 나머지가 X
        }
        
        if (x > maxYear)
            cout << -1 << "\n";
        else
            cout << x << "\n";
    }
    return 0;
}
