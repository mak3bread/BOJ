#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int R;
    cin>>R;

    printf("%.6lf\n",M_PI*(double)R*(double)R);
    printf("%.6lf\n",2.0*(double)R*(double)R);
    return 0;
}
