/*
Description
A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi packages from a central depot 0 to clients 1,2,…,n. Each client i requests d[i] packages. The distance from location i to location j is c[i,j], 0≤i,j≤n. A delivery solution is a set of routes: each truck is associated with a route, starting from depot, visiting some clients and returning to the depot for deliverying requested pepsi packages such that:
Each client is visited exactly by one route
Total number of packages requested by clients of each truck cannot exceed its capacity
Goal
Find a solution having minimal total travel distance
Note that: 
There might be the case that a truck does not visit any client (empty route)
The orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.
Input
Line 1: n,K,Q (2≤n≤12,1≤K≤5,1≤Q≤50)
Line 2: d[1],...,d[n](1≤d[i]≤10)
Line i+3 (i=0,…,n): the i
th
 row of the distance matrix c (1≤c[i,j]≤30)
Output
Minimal total travel distance
Example
Input
4 2 15
7 7 11 2
0 12 12 11 14
14 0 11 14 14
14 10 0 11 12
10 14 12 0 13
10 13 14 11 0

Output
70
*/
#include<stdio.h>
#include<algorithm>
using namespace std;
int c[30][30]; // khoang cachdi chuyen tu diem i den j
int Q; // TAI TRONG cua moi xe
int d[15]; // luong hang yeu cau o moi diem
int K; // so luong xe
int y[30];// diem giao dau tien cua xe thu k y[k+1] > y[k];
int x[30]; //diem tiep theo cua diem i tren lo trinh
bool visited[15]; // danh dau diem thu i da duoc den them 
int load[10]; //tai trong cua moi xe
int n ; // so luong client
int segments = 0 ;
int nbR;
int f=0, res = 1e9;
int cmin = 1e9;

void updateBest (int s ) {
 
    if (f + c[s][0] < res) res = f + c[s][0];
}
bool checkX(int v,int  k){
    if (v > 0 and visited[v]) return false;
    if ((load[k]  + d[v]) > Q) return false;
    return true;
}
//thử xem xe k đi tới điểm tiếp nào
void TRY_X(int s, int k){

    if (s ==0) { //xe k không dùng
        if (k <K) TRY_X(y[k+1],k+1);
        return;
    }
    for (int v = 0 ; v <= n ; v ++){
        if (checkX(v,k)){
            x[s]= v;
            visited[v] = true;
            f = f+ c[s][v];
            load[k] = load[k] + d[v];
            segments = segments +1;
            
            if (v > 0) {
                if (f + (n +nbR-segments)*cmin < res) TRY_X(v,k);
            }
            //từ s về 0
            else {
                if (k==K){
                    if (segments == n + nbR) updateBest (v);
                }
                else {
                    if (f + (n+nbR -segments)*cmin < res) TRY_X(y[k+1], k+1);
                }
            }

            
            visited[v] =false;
            f = f - c[s][v];
            load[k] = load[k]-d[v];
            segments = segments -1;
        }
    }
}
bool checkY(int v , int k) {
    if(v==0) return true;
    if (load[k] + d[v] > Q) return false;
    if(visited[v]) return false;
    return true;
}
//thu gia tri cho y[k] là điểm đầu tiên của xe thứ k
void TRY_Y(int k){
    
    int s = 0;
    if (y[k-1] > 0) s = y[k-1] + 1;
    for (int v = s ; v <= n ; v++){
        if (checkY(v, k)){
            y[k] = v; 
            if (v > 0) segments = segments + 1;
            visited[v] = true;
            f = f + c[0][v];
            load[k] = load[k] + d[v];
            if (k < K) TRY_Y(k+1);
            else {
                nbR = segments ; 
                TRY_X(y[1],1);

            }
            //recover
            load[k] = load[k] - d[v]    ;
            visited[v] = false;
            f = f - c[0][v];
            if (v > 0) segments = segments -1;
        }
    }
}
int main () {
    
    freopen("input.inp", "r", stdin);
  

    scanf("%d%d%d", &n, &K, &Q);
    //nhap luong hang moi diem
    for(int i = 1 ; i<= n ; i++ ) scanf("%d", &d[i]); 
    
    for(int i =0 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++) {
            scanf("%d", &c[i][j]);
            if (i!= j) cmin = min(cmin, c[i][j]);
        }
    }
    
    y[0] =0;
    for (int v = 1 ; v <= n ; v++) visited[v] = false;
    TRY_Y(1);
    printf("%d", res);
    return 0;

}


