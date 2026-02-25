#include <bits/stdc++.h>

using namespace std;
#define fi for (int i = 0; i < n; i++)
#define f1 for (int i = 1; i < n; i++)
#define fj for (int j = 0; j < m; j++)
#define s(x) sort(x.begin(), x.end());
#define ll long long
int n, m;
char ar[105][105];
bool vis[105][105];

pair<int, int> parent[105][105]; 

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || ar[i][j] == '#' || vis[i][j])
        return false;
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    parent[si][sj] = {-1, -1};

    int targetI = -1, targetJ = -1;
    bool found = false;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        
        if (ar[curr.first][curr.second] == 'D') {
            found = true;
            targetI = curr.first;
            targetJ = curr.second;
            break; 
        }

        for (int i = 0; i < 4; i++) {
            int ci = curr.first + d[i].first;
            int cj = curr.second + d[i].second;

            if (valid(ci, cj)) {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {curr.first, curr.second}; 
            }
        }
    }

    
    if (found) {
        pair<int, int> curr = parent[targetI][targetJ];
        while (curr.first != -1 && ar[curr.first][curr.second] != 'R') {
            ar[curr.first][curr.second] = 'X';
            curr = parent[curr.first][curr.second];
        }
    }
}
int main()

{

    cin >> n >> m;
    int si, sj;
    fi
    {
        fj
        {
            cin >> ar[i][j];

            if (ar[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    bfs(si, sj);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ar[i][j];
        }
        cout << endl;
    }

    return 0;
}