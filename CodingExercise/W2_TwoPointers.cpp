/*
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

Dữ liệu
Dòng 1: ghi n và M (1 <= n, M <= 1000000)
Dòng 2: ghi a1, a2, ..., an
Kết quả
Ghi ra giá trị Q
Ví dụ
Dữ liệu
5 6
5 2 1 4 3
Kết quả
2
*/

#include<stdio.h>
#include<algorithm>
using namespace std;
int main (){
    int n, M;
    int a[1000005];
    int res = 0;
    freopen("input.inp", "r", stdin);
    scanf("%d%d", &n, &M);
    for(int i = 1 ; i <= n ; i++) scanf("%d", &a[i]);
    
    sort(a+1, a+n+1);
   
    int i = 1, j = n ;
    while(i < j){
        if (a[i] + a[j] == M){
            res = res + 1;
            i = i+1;
            j = j -1;
        }
        else if (a[i] + a[j] < M) i = i + 1;
            else j = j -1;
    }
    printf("%d", res);
    return 0;
}