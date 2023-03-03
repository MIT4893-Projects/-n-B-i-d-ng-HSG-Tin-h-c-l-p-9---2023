#include <bits/stdc++.h>
using namespace std;

struct Game {
    int startTime;
    int endTime;
};

int n;
const int MAX = 1e3 + 1;
Game listGame[MAX];
int L[MAX];

bool cmp(Game a, Game b)
{
    return a.startTime < b.startTime;
}

void init()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> listGame[i].startTime >> listGame[i].endTime;
    sort(listGame, listGame + n, cmp);
    fill(L, L+n, 1);
}

void solve()
{
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if (listGame[j].startTime >= listGame[i].endTime && L[j] <= L[i])
                L[j] = L[i] + 1;
    int maxVal = L[0];
    for (int i = 1; i < n; ++i)
        maxVal = max(maxVal, L[i]);
    cout << maxVal;
}

int main()
{
    freopen("LEHOI.INP", "r", stdin);
    freopen("LEHOI.OUT", "w", stdout);
    init();
    solve();
    return 0;
}
