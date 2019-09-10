#include <iostream>
#include <stdio.h>
using namespace std;
int Fibb[1000];

int main()
{
    int n;
    scanf("%d", &n);
    
    // 피보나치 값을 저장해놓는 배열을 초기화
    for (int i = 0; i < n + 1; ++i)
    {
        Fibb[i] = -1;
    }
    Fibb[0] = 0;
    Fibb[1] = 1;
    
    for (int i = 2; i < n + 1; ++i)
    {
        Fibb[i] = Fibb[i - 1] + Fibb[i - 2];
    }
    
    printf("%d", Fibb[n]);
    
    return 0;
}

