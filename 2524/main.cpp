#include<cstdio>

using namespace std;

int stu[50000 + 10];

void init_set(int n) {
    for(int i = 1; i <= n; i++) {
        stu[i] = i;
    }
}

int find(int x) {
    return stu[x] == x ? x : stu[x] = find(stu[x]);
}

void union_set(int x, int y) {
    int root1 = find(x);
    int root2 = find(y);

    if(root1 != root2) {
        stu[root1] = root2;
    }
}

int main() {
    int n,m;
    int count = 0;
    while(scanf("%d%d", &n, &m) != EOF) {
        
        if(n == 0 && m == 0) break; 

        init_set(n);

        int r1,r2;
        while(m--) {
            scanf("%d%d", &r1, &r2);
            union_set(r1, r2);
        }
        
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(stu[i] == i) ++ans;
        }

        printf("Case %d: %d\n", ++count, ans);
    }
    return 0;
}