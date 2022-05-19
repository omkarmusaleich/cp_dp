#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
vector<vector<int>> v(N, vector<int>(32, 0));

void pre()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (i & (1 << j))
            {
                v[i][j] = (v[i - 1][j] + 1);
            }
            else
            {
                v[i][j] = v[i - 1][j];
            }
        }
    }
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    pre();
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        if (n == 1)
        {
            cout << x << endl;
        }
        else if (n == 2)
        {
            cout << 0 << " " << x << endl;
        }
        else
        {

            int y = 0;
            for (int i = 0; i < 32; i++)
            {
                if (v[n - 3][i] & 1)
                {
                    y = (y | (1 << i));
                }
            }
            //cout<<y<<endl;
            if (y != x)
            {

                int ans = 0;
                int n1, n2;
                n1 = (1 << 18);
                n2 = (1 << 18);
                for (int i = 0; i < 17; i++)
                {
                    if ((x & (1 << i)) != (y & (1 << i)))
                    {
                        n2 = (n2 | (1 << i));
                    }
                }
                cout << n1 << " " << n2 << " ";
                for (int i = 0; i <= (n - 3); i++)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
            else
            {
                int y1 = 0;
                for (int i = 0; i < 32; i++)
                {
                    if (v[n - 2][i] & 1)
                    {
                        y1 = (y1 | (1 << i));
                    }
                }
                int N1 = (1 << 18);
                int N2 = (1 << 18);

                for (int i = 0; i < 17; i++)
                {
                    if ((x & (1 << i)) != (y1 & (1 << i)))
                    {
                        N2 = (N2 | (1 << i));
                    }
                }
                cout << N1 << " " << N2 << " ";
                for (int i = 1; i <= (n - 2); i++)
                {
                    cout << i << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
