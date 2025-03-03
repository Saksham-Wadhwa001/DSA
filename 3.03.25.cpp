// LC POTD Partition Array According to the given Pivot
#include <bits/stdc++.h>
using namespace std;

vector<int> pivotArray(vector<int> &v, int pivot)
{
    vector<int> ans;

    for (int num : v)
    {
        if (num < pivot)
            ans.push_back(num);
    }

    for (int num : v)
    {
        if (num == pivot)
            ans.push_back(num);
    }

    for (int num : v)
    {
        if (num > pivot)
            ans.push_back(num);
    }

    return ans;
}

//TC= O(n)
//SC= O(n)
