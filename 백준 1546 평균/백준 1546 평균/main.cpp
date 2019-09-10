#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int N;
    cin>>N;
    double *arr=new double[N];
    for(int i=0;i<N;i++){
        scanf("%lf",&arr[i]);
    }
  
    double max=arr[0];
    for(int i=0;i<N;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    for(int i=0;i<N;i++){
        arr[i]=arr[i]/max*100.00;
    }

    double sum=0;
    double avg=0;
    for(int i=0;i<N;i++){
        sum+=arr[i];
    }
    avg=sum/(double)N;
    printf("%.2lf",avg);
    delete [] arr;
    return 0;
}
