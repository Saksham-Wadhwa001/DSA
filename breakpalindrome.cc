//https://leetcode.com/problems/break-a-palindrome/
#include<iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

class Solution {
    public:
        string breakPalindrome(string palindrome) {
            int n = palindrome.size();
            if (n == 1) return "";  
            
            for (int i = 0; i < n / 2; i++) {
                if (palindrome[i] != 'a') {
                    palindrome[i] = 'a';
                    return palindrome;  
                }
            }
        
            palindrome[n - 1] = 'b';
            return palindrome;
        }
    };
//Approach- As we have to return answer in lexicographically smallest then we have to change the first character which is non 'a' to 'a' 
//and we have to find that char in first half of the string as in the second half we can have a case in which the resultant string will still be
// a palindrome like in aba;

//TC = O(n)
//SC = O(1)
