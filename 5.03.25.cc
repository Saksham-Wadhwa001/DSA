//Count Total Number of Colored Cells
//LC POTD

#include <string>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        return (long long)n * n + (long long)(n - 1) * (n - 1);
    }
};

//TC-O(n);
//SC-O(n);
