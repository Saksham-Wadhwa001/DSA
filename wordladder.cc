//https://leetcode.com/problems/word-ladder/
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()); 
        queue<pair<string, int>> q; // Store {word, steps}
        q.push({beginWord, 1});

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord) return steps; 

            for (int i = 0; i < word.length(); i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c; // Change one letter at a time
                    if (dict.find(word) != dict.end()) { 
                        q.push({word, steps + 1});
                        dict.erase(word); 
                    }
                }
                word[i] = original; 
            }
        }
        return 0; // No change found
    }
};

//TC=O(26*n*l)=O(n*l)
//SC=O(n)
