#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int re=0;
        for(int j=0;j<s.size();j++){
            unordered_map<char,int> mapChar;
            int i=0;
            for(int k = j;k<s.size();k++){
                if(mapChar.find(s[k]) !=0) break;
                    mapChar[s[k]]++;
                    i++;
                }
                re = max(re,i);
        }
        return re;
    }
int lengthOfLongestSubstring1(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
