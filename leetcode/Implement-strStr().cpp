/*
*Implement strStr().

*Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (haystack.empty()) return needle.empty() ? 0 : -1;
        if (needle.empty()) return 0;
        int i = 0, j = 0;
        while(i < haystack.length()) {
            if(haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                i = i - j + 1;
                j = 0;
            }
            
            if(j == needle.length())
                return i - j;
        }
        return -1;
    }
};