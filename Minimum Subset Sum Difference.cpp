#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define fast                    \
    cin.sync_with_stdio(false); \
    cin.tie(NULL);              \
    cout.tie(NULL);

bool dp[1001][10001];
int MinSubseSumDiff(int n, int arr[], int sum)
{
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    //Find the minimum diff for valid sum
    int diff = sum;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[n][i] == 1)
            diff = min(diff, sum - 2 * i);
    }
    return diff;
}

signed main()
{
    fast;
    int n = 4;
    int arr[4] = {19, 6, 11, 5};
    int sum = accumulate(arr, arr + n, 0);
    //memonization
    memset(dp, 0, sizeof(dp));

    cout << MinSubseSumDiff(n, arr, sum);

    return 0;
}
