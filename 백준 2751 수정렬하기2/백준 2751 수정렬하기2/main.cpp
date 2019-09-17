//stl?!
//#include <iostream>
//#include <list>
//using namespace std;
//
//int main(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    int N;
//    cin>>N;
//    list<int> lt;
//
//    for(int i=0;i<N;i++){
//        int a;
//        cin>>a;
//        lt.push_front(a);
//    }
//    lt.sort();
//
//    list<int>::iterator it;
//
//    for(it=lt.begin();it!=lt.end();it++){
//        cout<<*it<<'\n';
//    }
//    return 0;
//}

//merge sort
#include <iostream>
#include <algorithm>

using namespace std;

int N;

int arr[1000000];

int temp[1000000];

void juanmerge(int first, int mid, int last) {
    int i, j, k, idx;
    
    i = first;
    j = mid + 1;
    k = first;
    
    while (i <= mid && j <= last) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    
    if (i > mid) {
        for (idx = j; idx <= last; idx++) {
            temp[k++] = arr[idx];
        }
    }
    else {
        for (idx = i; idx <= mid; idx++) {
            temp[k++] = arr[idx];
        }
    }
    
    for (int idx = first; idx <= last; idx++) {
        arr[idx] = temp[idx];
    }
}

void merge_sort(int first, int last) {
    
    if (first < last) {
        int mid = (first + last) / 2;
        merge_sort(first, mid);
        merge_sort(mid + 1, last);
        juanmerge(first, mid, last);
    }
}

int main(void)
{
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
        
        //cin >> arr[i];
        
        scanf("%d", &arr[i]);
    
    merge_sort(0, N - 1);
    
    for (int i = 0; i < N; i++)
        printf("%d\n", arr[i]);
    
    return 0;
}
