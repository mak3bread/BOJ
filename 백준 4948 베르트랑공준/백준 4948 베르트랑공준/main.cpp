//c++ 344ms
//#include <iostream>
//using namespace std;
//
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    while(1){
//        int n;
//        cin>>n;
//        if(n==0){break;}
//        if(n==1){cout<<1<<'\n';}
//
//        else{
//        bool arr[300000];
//        arr[0]=arr[1]=true;
//
//        for(int i=2;i<=300000;i++){
//            if(arr[i]==false){
//                for(int j=i+i;j<=300000;j+=i){
//                    arr[j]=true;
//                }
//            }
//        }
//            int cnt=0;
//            for(int i=n+1;i<2*n;i++){
//                if(arr[i]==false){
//                    cnt++;
//                }
//            }
//            cout<<cnt<<'\n';
//        }
//    }
//    return 0;
//}


//c 336ms

#include <iostream>

int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0){break;}
        if(n==1){printf("1\n");}
        
        else{
            bool arr[300000];
            arr[0]=arr[1]=true;
            
            for(int i=2;i<=300000;i++){
                if(arr[i]==false){
                    for(int j=i+i;j<=300000;j+=i){
                        arr[j]=true;
                    }
                }
            }
            int cnt=0;
            for(int i=n+1;i<2*n;i++){
                if(arr[i]==false){
                    cnt++;
                }
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}

