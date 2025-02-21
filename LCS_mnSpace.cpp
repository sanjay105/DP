#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}
string backtrack(string a, string b, int **m, int l1, int l2)
{
    stack<int> s;
    int y = l2;
    string res = "";
    for (int i = l1; i > 0; i--)
    {
        if (m[i][y] == m[i - 1][y - 1] + 1)
        {
            y--;
            s.push(i - 1);
        }
    }
    while (!s.empty())
    {
        res += a[s.top()];
        s.pop();
    }
    return res;
}
string longestCommonSubsequence_mn(string s1, string s2)
{
    int l1 = s1.length(), l2 = s2.length();
    int **m = (int **)malloc(sizeof(int *) * (l1 + 1));
    for (int j = 0; j < l1 + 1; j++)
    {
        m[j] = (int *)malloc(sizeof(int) * (l2 + 1));
        m[0][j] = m[j][0] = 0;
    }
    for (int i = 1; i < l1 + 1; i++)
    {
        for (int j = 1; j < l2 + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                m[i][j] = m[i - 1][j - 1] + 1;
            }
            else
            {
                m[i][j] = max(m[i - 1][j], m[i][j - 1]);
            }
        }
    }
    cout << m[l1][l2] << endl;
    return backtrack(s1, s2, m, l1, l2);
}
int main()
{
    string s1 = "abbsddsghfgbvsdn";
    string s2 = "afkjknfdbretvjm";
    cout << longestCommonSubsequence_mn(s1, s2);
}