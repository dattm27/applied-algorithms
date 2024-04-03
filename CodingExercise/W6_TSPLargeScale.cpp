#include<algorithm>
#include<stdio.h>
using namespace std;
#define MAX_N 10005
int n;
int c[MAX_N][MAX_N];
int min_cost = 1e9;
/*
Trả về 0 nếu không tìm được đường đim ngược lại trả về tổng độ dài 
start: đỉnh xuất phát
path: thứ tự các đỉnh đã đi qua
np: độ dài đường đi tìm được
*/
int tim_duong(int a[][MAX_N], int n, int start, int path[], int &np ){
    np = 0 ; 
    int visited[MAX_N];
    int cur = start; 
    int next; // xem di duoc nua khong
    int cost = 0;
    path[np++] = start;
    for(int i =0  ; i< n ; i++) visited[i] = 0;
    visited[start] = 1;
    do {
        // Kiểm tra nếu chi phí hiện tại lớn hơn min_cost thì kết thúc
        if (cost >= min_cost) return 0;
        // tim dinh dau tie co the di duoc tu dinh cur
        int i =  0;
        while (i < n && (a[cur][i] == 0|| visited[i] ==1 ))i++;
        //xet ket qua 
        if (i >= n) next = -1;
        else {
            next = i ;
            //tim dinh co the di duoc co kc nho nhat
            for (; i<n ; i++){
                if (visited[i] ==0 && a[cur][i] < a[cur][next]) next = i;
            }
            //di toi next;
            path[np++] = next;
            visited[next] =1;
            cost += a[cur][next];
            cur = next;
        }

    }while (next != -1) ;// cho toi khi het duong di
    if (np < 0)  return 0;
    else {
        if (a[cur][start] !=0) //co duong tu dinh hien tai -> start
        {
            cost += a[cur][start];
            return cost;
        }
        else return 0;
    }

}
int main () {
    freopen("input.inp", "r", stdin);
    scanf("%d", &n);
    for(int i = 0 ; i< n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d", &c[i][j]);
        }
    }
    int np ; // do dai duong di
    int path[MAX_N]; // thu tu cac dinh di qua
    int res_path[MAX_N];
  //  int cost = tim_duong(c,n, 0, path, np);
    for(int i = 0 ; i< n; i++) {
        int cost = tim_duong(c,n, i, path, np);
        if (cost) {
            min_cost = cost;
            for(int i = 0 ; i< n ; i++) res_path[i] = path[i];
        }
    }
    printf("%d\n",n);
  
    for (int i = 0 ; i< n ; i++) printf("%d ", res_path[i]+1);
    
    return 0;
}