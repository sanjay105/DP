#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}
void LCS(string a, string b, int x, int y, int *m0, int *m1)
{
    if (a[x - 1] == b[y - 1])
    {
        m1[y] = m0[y - 1] + 1;
    }
    else
    {
        m1[y] = max(m0[y], m1[y - 1]);
    }
}

int longestCommonSubsequence(string text1, string text2)
{
    int l1 = text1.length(), l2 = text2.length();
    int *m1, *m0;
    m0 = (int *)calloc(sizeof(int), l2 + 1);
    m1 = (int *)calloc(sizeof(int), l2 + 1);
    for (int i = 1; i < l1 + 1; i++)
    {
        for (int j = 1; j < l2 + 1; j++)
        {
            LCS(text1, text2, i, j, m0, m1);
        }
        for (int k = 0; k < l2 + 1; k++)
        {
            m0[k] = m1[k];
        }
    }
    return m1[l2];
    //cout<<backtrack(text1,text2,m,l1,l2);
}
int main()
{
    string s1 = "abbsddsghfgbvsdn";
    string s2 = "afkjknfdbretvjm";
    cout << longestCommonSubsequence(s1, s2);
}