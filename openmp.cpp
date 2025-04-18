#include <bits/stdc++.h>
#include <omp.h>
#define fore(i, l, r) for (int i = l; i < r; i++)
using namespace std;


void solve() {
    int n, m, num_cnt;
    ifstream fin("data.txt");
    fin >> n >> m >> num_cnt;
    vector<vector<double>> vec(n + 1, vector<double>(m + 1));
    int u, v;
    double w;
    fore(i, 0, num_cnt) {
        fin >> u >> v >> w;
        vec[u][v] = w;
    }
    auto start = chrono::high_resolution_clock::now();
    vector<int> x(n, 1), y(n, 0);

    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < n; ++i) {
        double local_y = 0;
        for (int j = 0; j < m; ++j) {
            y[i] += vec[i][j] * x[j];
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
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}