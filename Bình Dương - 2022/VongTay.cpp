#include <iostream>
#include <vector>
using namespace std;

int n;
int res = 1;
vector<short int> arr;

short int getVal(int idx)
{
    try
    {
        return arr[idx];
    }
    catch(exception) {}
    return -1;
}

int main()
{
    freopen("vongtay.inp", "r", stdin);
    freopen("vongtay.out", "w", stdout);


    cin >> n;
    arr = vector<short int>(n, 0);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    for (int start = 0; start < n; ++start)
    {
        for (int stop = start + 1; stop < n; ++stop)
        {
            int subLength = stop - start;
            bool isRepeating = true;
            for (int idx = 0; idx < subLength; ++idx)
            {
                if (getVal(start + idx) != getVal(stop + idx))
                {
                    isRepeating = false;
                    break;
                }
            }
            if (isRepeating)
                res = max(subLength, res);
        }
    }

    cout << res;

    return 0;
}
