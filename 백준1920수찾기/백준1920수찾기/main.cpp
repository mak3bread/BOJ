#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;

int search(int start, int end, int find) {
    int s = start;
    int e = end;
    int mid;
    while(s <= e) {
        mid = (s + e) / 2;
        if (a[mid] == find) return 1;
        else if (a[mid] > find) e = mid - 1;
        else if (a[mid] < find) s = mid + 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        a.push_back(q);
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int ser;
        cin >> ser;
        cout << search(0, n-1, ser) << '\n';
    }
    return 0;
}
