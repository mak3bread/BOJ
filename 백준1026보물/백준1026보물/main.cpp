#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;

    if(N>=1&&N<=50){
        int *A=new int[N];
        int *B=new int[N];
        int *C=new int[N];
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
            cin>>B[i];
            C[i]=B[i];
        }
    
        int temp=0;
       
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
               
                if(A[i]<A[j]){
                    temp=A[i];
                    A[i]=A[j];
                    A[j]=temp;
                }
            }
            
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
               
                if(C[i]>C[j]){
                    temp=C[i];
                    C[i]=C[j];
                    C[j]=temp;
                }
            }
            
        }

        int result=0;
        for(int i=0;i<N;i++){
            result+=A[i]*C[i];
        }

         cout<<result<<endl;
        delete [] A;
        delete [] B;
        delete [] C;
    }
   return 0;
}
