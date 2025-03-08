//LC POTD

#include <bits/stdc++.h>
using namespace std;

int minimumRecolors(string s, int k)
{
    int i = 0, j = 0, n = s.length(), couount = 0, mini = n + 1;
    while (j < n)
    {
        if (s[j] == 'W')
        {
            count++;
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            mini = min(mini, count);
            if (s[i] == 'W')
            {
                count--;
            }
            i++;
            j++;
        }
    }
    return mini;
}

//Approach-> using sliding window
//TC=O(n)
//SC=O(1)
