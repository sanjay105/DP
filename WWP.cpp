/*
Word Wrap Problem | DP-19
Given a sequence of words, and a limit on the number of characters that can be put in one line (line width). 
Put line breaks in the given sequence such that the lines are printed neatly. 
*/
#include <bits/stdc++.h>
using namespace std;
int printsol(int *p, int n)
{
    int k;
    if (p[n] == 1)
    {
        k = 1;
    }
    else
    {
        k = printsol(p, p[n] - 1) + 1;
    }
    cout << "Line number " << k << ": From word no. " << p[n] << " to " << n << endl;
    return k;
}
void WWP(int *a, int n, int M)
{
    int **extras, **lc;
    extras = (int **)malloc(sizeof(int *) * (n + 1));
    lc = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; i++)
    {
        extras[i] = (int *)calloc(sizeof(int), (n + 1));
        lc[i] = (int *)calloc(sizeof(int), (n + 1));
        if (i != 0)
        {
            extras[i][i] = M - a[i - 1];
            for (int j = i + 1; j <= n; j++)
            {
                extras[i][j] = extras[i][j - 1] - a[j - 1] - 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (extras[i][j] < 0)
            {
                lc[i][j] = INT_MAX;
            }
            else if (j == n)
            {
                lc[i][j] = 0;
            }
            else
            {
                lc[i][j] = extras[i][j] * extras[i][j];
            }
        }
    }
    int *c = (int *)calloc(sizeof(int), n + 1);
    int *p = (int *)calloc(sizeof(int), n + 1);
    c[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        c[j] = INT_MAX;
        for (int i = 1; i <= j; i++)
        {
            if (c[i - 1] != INT_MAX && lc[i][j] != INT_MAX && (c[i - 1] + lc[i][j] < c[j]))
            {
                c[j] = lc[i][j] + c[i - 1];
                p[j] = i;
            }
        }
    }
    printsol(p, n);
}
int main()
{
    int n, *a, M;
    cin >> n;
    a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> M;
    WWP(a, n, M);
    return 0;
}