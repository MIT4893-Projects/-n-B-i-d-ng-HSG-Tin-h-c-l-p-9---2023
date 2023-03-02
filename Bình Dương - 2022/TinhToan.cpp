#include <bits/stdc++.h>
using namespace std;

struct Position
{
    int val;
    int idx;
};

vector<Position> pos;
vector<Position> nev;
int n;

void init()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        Position positionI;
        positionI.idx = i;
        cin >> positionI.val;
        if (positionI.val > 0)
            pos.push_back(positionI);
        else
            nev.push_back(positionI);
    }
}

void solve()
{
    int i = 0; // moving point in Positive Array
    int j = 0; // moving point in Negative Array

    int currentMoney = 0;
    int step = 0;
    int prevIdx = 0;
    while (i < pos.size() && j < nev.size())
    {
        step = step + abs(pos[i].idx - prevIdx);
        prevIdx = pos[i].idx;
        currentMoney += pos[i].val;
        ++i;

        while (currentMoney + nev[j].val >= 0 && j < nev.size()) {
            step = step + abs(nev[j].idx - prevIdx);
            prevIdx = nev[j].idx;
            currentMoney += nev[j].val;
            ++j;
        }
    }
    step = step + abs(n - prevIdx);
    cout << step;
}

int main()
{
    freopen("TINHTOAN.INP", "r", stdin);
    freopen("TINHTOAN.OUT", "w", stdout);
    init();
    solve();
    return 0;
}
