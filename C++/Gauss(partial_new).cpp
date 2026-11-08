#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

enum SolutionType
{
    UNIQUE,
    INFINITE,
    NONE
};

struct GaussJordan
{
    vector<vector<double>> a; // augmented matrix: n x (m+1)
    int n, m;                 // n equations, m variables

    GaussJordan(int rows, int cols)
    {
        n = rows;
        m = cols;
        a.assign(n, vector<double>(m + 1));
    }

    void setRow(int i, const vector<double> &row)
    {
        a[i] = row;
    }

    SolutionType solve(vector<double> &ans)
    {
        vector<int> where(m, -1);
        for (int col = 0, row = 0; col < m && row < n; ++col)
        {
            int sel = row;
            for (int i = row; i < n; ++i)
                if (fabs(a[i][col]) > fabs(a[sel][col]))
                    sel = i;

            if (fabs(a[sel][col]) < EPS)
                continue;

            swap(a[sel], a[row]);
            where[col] = row;

            double inv = a[row][col];
            for (int j = col; j <= m; ++j)
                a[row][j] /= inv;

            for (int i = 0; i < n; ++i)
            {
                if (i != row && fabs(a[i][col]) > EPS)
                {
                    double factor = a[i][col];
                    for (int j = col; j <= m; ++j)
                        a[i][j] -= factor * a[row][j];
                }
            }
            ++row;
        }

        ans.assign(m, 0);
        for (int i = 0; i < m; ++i)
            if (where[i] != -1)
                ans[i] = a[where[i]][m];

        for (int i = 0; i < n; ++i)
        {
            double sum = 0;
            for (int j = 0; j < m; ++j)
                sum += ans[j] * a[i][j];
            if (fabs(sum - a[i][m]) > EPS)
                return NONE;
        }

        for (int i = 0; i < m; ++i)
            if (where[i] == -1)
                return INFINITE;

        return UNIQUE;
    }

    void debugPrint()
    {
        cout << "Augmented Matrix:\n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= m; ++j)
                cout << fixed << setprecision(4) << a[i][j] << ' ';
            cout << '\n';
        }
    }
};

int main()
{
    int n = 3, m = 3;
    GaussJordan gj(n, m);

    // Example system:
    // 2x +  y - z =  8
    //-3x -  y + 2z = -11
    //-2x +  y + 2z = -3

    gj.setRow(0, {3, 0, 1, 6});
    gj.setRow(1, {0, 2, 2, 10});
    gj.setRow(2, {1, 3, 1, 10});

    vector<double> ans;
    SolutionType res = gj.solve(ans);

    if (res == NONE)
        cout << "No solution\n";
    else if (res == INFINITE)
        cout << "Infinite solutions\n";
    else
    {
        cout << "Unique solution:\n";
        for (double x : ans)
            cout << fixed << setprecision(6) << x << ' ';
        cout << '\n';
    }

    return 0;
}
