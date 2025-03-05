#include <string>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(10, 0);
        array<int, 26> freq = {}; 

        for (char c : s) {
            freq[c - 'a']++;
        }

        count[0] = freq['z' - 'a'];  // "zero"
        count[2] = freq['w' - 'a'];  // "two"
        count[4] = freq['u' - 'a'];  // "four"
        count[6] = freq['x' - 'a'];  // "six"
        count[8] = freq['g' - 'a'];  // "eight"

        count[1] = freq['o' - 'a'] - count[0] - count[2] - count[4];  // "one"
        count[3] = freq['h' - 'a'] - count[8];  // "three"
        count[5] = freq['f' - 'a'] - count[4];  // "five"
        count[7] = freq['v' - 'a'] - count[5];  // "seven"
        count[9] = (freq['n' - 'a'] - count[1] - count[7]) / 2;  // "nine"

        string ans;
        for (int i = 0; i < 10; i++) {
            ans.append(count[i], '0' + i);
        }

        return ans;
    }
};
