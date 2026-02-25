#include <bits/stdc++.h>

using namespace std;
#define fi for (int i = 0; i < n; i++)
#define f1 for (int i = 1; i < n; i++)
#define fj for (int j = 0; j < m; j++)
#define s(x) sort(x.begin(), x.end());
#define ll long long
int n, m;
char ar[10005][10005];
bool vis[10005][10005];
int cnt = 0;
int ma = INT_MAX;
bool found = false;
vector<pair<int, int>> d = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && ar[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}

int main()

{

    cin >> n >> m;
    fi
            fj
                cin >>
        ar[i][j];
    memset(vis, false, sizeof(vis));
    fi
        fj if (!vis[i][j] && ar[i][j] == '.')
    {
        cnt = 0;
        found = true;
        dfs(i, j);
        if (cnt < ma)
            ma = cnt;
    }
    
    if (!found)
        cout << "-1" << endl;
    else
        cout << ma << endl;




    return 0;
}