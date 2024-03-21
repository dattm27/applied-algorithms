#include<stdio.h>
#include<algorithm>
using namespace std;
int n, K;
int c[30][30]; //distance to move from point i to j
bool visited[30];
int load = 0; // number of passengers on bus
int x[30] ;// solution
int f =0 ; //độ dài lộ trình bộ phận 
int cmin = 1e9;
int res=  1e9;

bool check(int v){
    if (visited[v]) return false;
    if (v > n) {
        if (visited[v-n]== false) return false;
    }
    else {
        if ((load + 1) > K) return false;
    }
    return true;
}

void updateBest(){
    if(f + c[x[2*n]][0] < res) res = f + c[x[2*n]][0];

}
void Try (int k){
    for(int v = 1 ; v <= 2*n; v++){
        if (check(v)){
            x[k] = v;
            f = f + c[x[k-1]][x[k]]; //update current solution distance 
            visited[v] = true;
            if (v <= n) load += 1;
            else load -= 1;
            if (k == 2*n) updateBest();
            else {
                //nhanh can
                if(f + cmin*(2*n+1-k) < res){
                    Try(k+1);
                }
            }
            if( v<= n) load -= 1 ;
            else load+= 1;
            f = f - c[x[k-1]][x[k]];
            visited[v] = false;
        }
    }
}
int main () {
    freopen("input.inp", "r", stdin);


    scanf("%d%d", &n, &K);
    for(int i = 0 ; i< 2*n + 1; i++ ){
        for(int j = 0 ; j< 2*n +1 ; j++){
            scanf("%d", &c[i][j]);
            if (c[i][j] != 0) cmin = min(cmin, c[i][j]);
        }
    }
    
    Try(1);

    printf("%d", res);
    return 0 ;

}