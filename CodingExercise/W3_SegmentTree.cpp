/*
Given a sequence of positive integers a1, a2, . . ., an. Perform a sequence of actions of following types:
update  i  v : assign ai= v
get-max  i  j : return the maximum value of the subsequence ai, ai+1, . . ., aj

Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
Line 3: contains a positive integer m (1 <= m <= 100000) which is the number of actions
Line i + 3 (i = 1, 2, . . ., m): contains an action described above
Output
Write in each line the result of the corresponding action of type get-max
Example
Input
10
1 10 9 7 1 4 2 4 8 10 
5
get-max 5 8
get-max 5 9
get-max 3 8
update 9 20
get-max 4 10

Ouput
4
8
9
20
*/
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n, m;
int a[100005];

struct SegmentTree{
    int id;
    int L, R; 
    int maxVal[900020]; 

    int getMaxFromNode(int id , int L, int R , int i  , int j ){
        //return the max value of ai,... ạ from the node (id, L, R)
        if(i > R || j < L) return -1e9; // [l,R] and [i,j] are disjoint --> not found
        if(i <= L and j >= R)
            return maxVal[id]; // max value is stored in the node (id, L, R);
        int mid = (L+R)/2;
        int LC = 2*id; 
        int  RC = 2*id + 1 ; // left-child and right-child
        int maxLeft = getMaxFromNode(LC, L, mid , i , j);
        int maxRight = getMaxFromNode(RC, mid + 1, R, i, j);
        return (max(maxLeft, maxRight));
    }
    int getMax(int i, int j){
        return getMaxFromNode(1,1,n,i,j);
    }   
    void updateFromNode(int id , int L, int R, int index, int value){
        //propagate from the node (id, L, R) by the update a[index] = value
        if (L > R) return;
        if (index < L || index > R) return; // node (id, L , R ) does not manage a[index]
        if (L == R) {
            maxVal[id] = value ; 
            return;

        }
        int LC = 2*id, RC = 2*id + 1; // left-child and right child;
        int mid = (L+R)/2;
        updateFromNode(LC, L, mid, index, value);
        updateFromNode(RC, mid+1, R, index, value);
        maxVal[id] = max(maxVal[LC], maxVal[RC]);
    }
    void update(int i, int v){
        updateFromNode(1,1,n, i, v);// start the propagation from the root node
    }
} ST;


int main () {
    freopen("input.inp", "r", stdin);
    scanf("%d", &n);
    for(int i = 1 ; i<= n ; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 1; i <= n ; i++){
        ST.update(i, a[i]);
    }

    scanf("%d", &m);
    for(int k = 1 ; k <= m ; k++){
        char cmd[8];
        scanf("%s", cmd);
        if(strcmp(cmd, "get-max")==0){
            int i, j;
            scanf("%d%d", &i, &j);
            printf("%d\n", ST.getMax(i,j));
        }
        else{
            int i, v;
            scanf("%d%d", &i, &v);
            ST.update(i,v);
        }
    }


    return 0;
}