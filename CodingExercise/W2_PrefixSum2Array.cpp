#include<stdio.h>
#include<iostream>
using namespace std;
int main () {
    freopen("input.inp", "r", stdin);
    int n, m;
    long long s[1005][1005];
    scanf("%d%d", &n , &m);
    for(int i = 0; i <= n; i++) s[i][0] = 0;
    for(int j = 0 ; j <= m; j++) s[0][j] = 0;
    for(int i = 1 ; i <= n; i++){
        for(int j = 1 ; j <=  m ; j++){
            int a;
            scanf("%d", &a);
            s[i][j] =  s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a;
        
        }
    }

    int q;
    scanf("%d", &q);
    for (int k = 1 ; k <= q ; k++){
        int r1, c1, r2, c2 ;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        printf("%lld\n", s[r2][c2] - s[r2][c1-1] - s[r1-1][c2] + s[r1-1][c1-1]);

    }
    return 0;
}