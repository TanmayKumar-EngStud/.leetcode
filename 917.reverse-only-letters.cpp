/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 *
 * https://leetcode.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (60.74%)
 * Likes:    1327
 * Dislikes: 49
 * Total Accepted:    125K
 * Total Submissions: 205.8K
 * Testcase Example:  '"ab-cd"'
 *
 * Given a string s, reverse the string according to the following rules:
 * 
 * 
 * All the characters that are not English letters remain in the same
 * position.
 * All the English letters (lowercase or uppercase) should be reversed.
 * 
 * 
 * Return s after reversing it.
 * 
 * 
 * Example 1:
 * Input: s = "ab-cd"
 * Output: "dc-ba"
 * Example 2:
 * Input: s = "a-bC-dEf-ghIj"
 * Output: "j-Ih-gfE-dCba"
 * Example 3:
 * Input: s = "Test1ng-Leet=code-Q!"
 * Output: "Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s consists of characters with ASCII values in the range [33, 122].
 * s does not contain '\"' or '\\'.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        // s[s.length()-1-backward]>='a'&&s[s.length()-1-backward]<='z' || s[s.length()-1-backward]>= 'A' && s[s.length()-1-backward]<= 'Z'
        int forward = 0;
        int backward = 0;
        if(s.length()==1){
            return s;
        }
        while(forward <= s.length()-1-backward){
            if(((s[forward]>='a'&&s[forward]<='z') || (s[forward]>= 'A' && s[forward]<= 'Z'))&&((s[s.length()-1-backward]>='a'&&s[s.length()-1-backward]<='z') || (s[s.length()-1-backward]>= 'A' && s[s.length()-1-backward]<= 'Z'))){
                char temp = s[forward];
                s[forward] = s[s.length()-1-backward];
                s[s.length()-1-backward] = temp;
                forward++;
                backward++;
            }
            else{
                if(!((s[forward]>='a'&&s[forward]<='z') || (s[forward]>= 'A' && s[forward]<= 'Z'))){
                    ++forward;
                }
                if(!((s[s.length()-1-backward]>='a'&&s[s.length()-1-backward]<='z' )|| (s[s.length()-1-backward]>= 'A' && s[s.length()-1-backward]<= 'Z'))){
                    ++backward;
                }
            }
        }
        return s;
    }
};
// @lc code=end

