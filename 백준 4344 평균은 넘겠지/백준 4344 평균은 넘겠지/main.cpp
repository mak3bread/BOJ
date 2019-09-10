#include <iostream>
using namespace std;

int main(){
    int C;
    scanf("%d",&C);
   
    for(int i=0;i<C;i++){
        int N;
        scanf("%d",&N);
        double *arr=new double[N];
        double sum=0;
        for(int j=0;j<N;j++){
            scanf("%lf",&arr[j]);
            sum+=arr[j];
        }
        double avg=sum/(double)N;
        double count=0;
        for(int j=0;j<N;j++){
            if(avg<arr[j]){count++;}
        }
        double result=count/(double)N*(double)100;
        printf("%.3lf%%\n",result);
       
    }
    return 0;
}
