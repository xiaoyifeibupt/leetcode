/**
*A message containing letters from A-Z is being encoded to numbers using the following mapping:

  'A' -> 1
  'B' -> 2
  ...
  'Z' -> 26
*Given an encoded message containing digits, determine the total number of ways to decode it.

*For example,
*Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

*The number of ways decoding "12" is 2.
*/

class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0)
            return 0;
        if(s.length() == 1)
            return s[0] != '0'?1:0;
        if(s.length() == 2)
            return (s[0] != '0' && s[1] != '0'? 1 : 0) + 
            ((s[0] != '0' && (char2int(s[0]) * 10 + char2int(s[1])) <= 26) ? 1 : 0);
        int* dp = new int[s.length()];  
        dp[0] = s[0] != '0' ? 1 : 0;  
        dp[1] = (s[0] != '0' && s[1] != '0'? 1 : 0) + 
            ((s[0] != '0' && (char2int(s[0]) * 10 + char2int(s[1])) <= 26) ? 1 : 0);
        for(int i = 2; i < s.length(); ++i) {
            dp[i] = 0;  
            if(s[i] != '0'){  
                dp[i] += dp[i-1];  
            }  
              
            if(s[i-1] != '0' && (char2int(s[i-1]) * 10 + char2int(s[i])) <= 26){  
                dp[i] += dp[i-2];  
            }
        }
    return dp[s.length() - 1];
    }
    int char2int(char c){  
        return c - '0';  
    }
};
