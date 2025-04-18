#include <bits/stdc++.h>
#include <omp.h>
#define fore(i, l, r) for (int i = l; i < r; i++)
using namespace std;


void solve() {
    int n, m, num_cnt;
    ifstream fin("data.txt");
    fin >> n >> m >> num_cnt;
    vector<vector<int>> vec(n + 1, vector<int>(m + 1));
    int u, v;
    fore(i, 0, num_cnt) {
        fin >> u >> v;
        vec[u][v] = rand() % 100;
    }
    auto start = chrono::high_resolution_clock::now();
    vector<int> x(n, 1), y(n, 0);

    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < n; i++) {
        int local_y = 0;
        for (int j = 0; j < m; ++j) {
            local_y += vec[i][j] * x[j];
        }
        y[i] = local_y;
    }

    ofstream fout("std.txt");
    for(int c : y) fout << c << ' ';

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "time : " << duration.count() << " ms" << endl;
}
    
int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
