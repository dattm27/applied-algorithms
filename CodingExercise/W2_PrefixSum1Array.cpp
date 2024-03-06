
#include<iostream>

using namespace std;
int main () {
    int n;
    long long s[100005];
    cin >> n;
    s[0] = 0;
    for (int i = 1 ; i <= n ;i++){
        int a;
        cin >> a;
        s[i] = s[i-1] +a;
    }
    int q;
    cin >> q;
    for(int k = 1 ; k<= q; k++){
        int i, j;
        cin >> i >> j;
        cout << s[j] - s[i-1] <<"\n";
    }
    return 0 ;
    
}