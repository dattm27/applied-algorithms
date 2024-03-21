/*
Given a material having the shape rectangle with height H and width W. We need to cut this material into n smaller rectangle submaterials of size (h1,w1), (h2, w2), ..., (hn, wn). Write a program to check if we can perform this cut.
Input
Line 1: contains two positive integers H, W (1 <= H, W <= 10)
Line 2: contains a positive integer n (1 <= n <= 10)
Line i+2 (i= 1,...,n): contains two positive integer hi and wi (1 <= hi, wi <= 10)
Output
Write 1 if we can perform the cut and write 0, otherwise.
Example
Input
7 5
4
1 5
6 2
2 2
4 3
Output
1
*/

#include<stdio.h>
#include<algorithm>
using namespace std;
int H, W;
int n ;
int h[11], w[11];
bool mark[11][11];
int x[11], y[11],o[11];
int solution =0;
void doMark ( int vo ,int vx, int vy, int k , bool mark_value){
    int wk = w[k], hk = h[k];
    if (vo)  {
        wk = h[k];
        hk = w[k];
    }
    for (int i = vx ; i<= vx + wk-1 ;i++ ){
        for(int j = vy ; j <= vy + hk-1; j++) 
            mark[i][j] = mark_value;
    }
}
bool check (int vo, int vx, int vy, int k){
    int wk = w[k], hk=h[k];
    if (vo==1) {
        wk=h[k];
        hk=w[k];
    }
    if (vx + wk  >  W) return false;
    if (vy + hk  > H) return false;
    for(int i = vx ; i <= vx + wk -1 ; i++){
        for (int j = vy; j <= vy + hk -1; j++){
            if(mark[i][j]) return false;
        }
    }
    return true;
}
void Try (int k){

    for(int vo = 0; vo <= 1 ;  vo++){
        int wk = w[k], hk =  h[k];
        if (vo == 1) {
            wk=h[k];
            hk = w[k];
        }
        for (int vx = 0 ; vx <= W - wk; vx++){
            for (int vy = 0 ;vy <= H- hk; vy++ ){
                if (check(vo,vx,vy,k)){
                    x[k] = vx;
                    y[k] = vy;
                    o[k] = vo;
                    doMark(o[k], x[k], y[k], k, true); // do mark
                    if (k == n) {
                        solution = 1;
                    
                        return;
                    }
                    else Try(k+1);
                    doMark(o[k], x[k], y[k], k ,false); //undo mark
                }
            }
        }
    }
}
int main () {
    freopen("input.inp", "r", stdin);
    scanf("%d%d%d", &H, &W, &n);

    for(int i = 1; i<=n ; i++){
        scanf("%d%d", &h[i], &w[i] );
    }
    Try(1);
    printf("%d", solution);
    return 0;
}