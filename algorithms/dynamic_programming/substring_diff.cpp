#include<bits/stdc++.h>
#define VVI vector<vector<int>>
#define TU tuple<int, int, int>
using namespace std;

int solve(string &P, string &Q, int S) {
    int LL = P.size(), max_L = -1;
    map<TU, int> mem;
        
    for(int l=1; l<=LL; l++) {
        for (int i=0; i<=(LL-l); i++) {
            for (int j=0; j<=(LL-l); j++) {
                int x = P[i+l-1] == Q[j+l-1] ? 0 : 1;
                TU t(i, j, l), tm(i, j, l-1);
                mem[t] = x + (mem.find(tm) == mem.end() ? 0 : mem[tm]);
                // cout << i << "," << j << "," << l << " " << mem[t] << endl;
                if (mem[t] <= S)
                    max_L = l > max_L ? l : max_L;
            }
        }
    }
    return max_L;
}

int solve_d(VVI &mat, int S) {
    int max_L = -1, len = mat.size();
    for (int i=1; i<len; i++)
        for (int j=1; j<len; j++)
                mat[i][j] += mat[i-1][j-1];
/**        
    for (int i=0; i<len; i++) {
        for (int j=0; j<len; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
**/            
    for (int i=1; i<len; i++)
        for (int j=1; j<len; j++)         
            if (i == 1 || j == 1) {
                // cout << i << "," << j << " - ";
                int si = i-1, sj = j-1, ti = i, tj = j, tk = 1;
                while (ti < len && tj < len) {
                    while (si < ti && sj < tj && mat[ti][tj] - mat[si][sj] > S) {
                        si += 1;
                        sj += 1;
                        tk -= 1;
                    }
                    // cout << tk << " ";
                    assert(mat[ti][tj] - mat[si][sj] <= S);
                    max_L = tk > max_L ? tk : max_L;        
                    
                    tk += 1;
                    ti += 1;
                    tj += 1;
                }
                // cout << endl;
            }
    return max_L;
} 

int main() {
    int nc;
    cin >> nc;
    while (nc--) {
        string P, Q; int S;
        cin >> S >> P >> Q;
        
        int len = P.size();
        VVI diff(1+len);
        for (int i=0; i<=len; i++)
            for (int j=0; j<=len; j++)
                diff[i].push_back((P[i-1] == Q[j-1] || i==0 || j == 0) ? 0 : 1);
                
        cout << solve_d(diff, S) << endl;
    }
    return 0;
}