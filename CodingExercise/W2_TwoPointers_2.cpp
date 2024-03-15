/*
Given a sequence of positive integers a = a1, a2, . . ., an. A subsequence of a is defined to be a sequence of consecutive elements ai, ai+1, . . ., aj (1 <= i <= j <= n). The weight of a subsequence is the sum of its elements. Given a positive integer Q. A subsequence is said to be feasible if the weight is less than or equal to Q.
Find a feasible subsequence such that the number of elements of that subsequence is maximal.

Input
Line 1: contains two positive integers n and Q (1 <= n <= 106, 1 <= Q <= 100000)
Line 2: contains a1, a2, . . ., an (1 <= ai <= 10000).

Output
Write the number of elements of the subsequence found, or write -1 if no such subsequence exists.

Example
Input
6 20
2 2 5 6 5 7 

Output
5
*/

#include<stdio.h>
#include<algorithm>
using namespace std;
int main () {
    freopen("input.inp", "r", stdin);
    int n , Q;
    int a[1000005];
    scanf("%d%d", &n , &Q);
    for(int i = 1; i<= n ; i++){
        scanf("%d", &a[i]);
    }
    int res = 0, S = 0;
    int L = 1 ;
    for(int R = 1 ; R <n ; R++){
        S = S + a[R];
        while (S > Q) {
            S = S - a[L];
            L = L +1;
        }
        res = max(res, R - L + 1);
    }
    printf("%d" , res != 0 ? res : -1 );
    return 0;
}
