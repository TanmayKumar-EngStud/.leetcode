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
    // I will do this question later, this question is not that difficult, we just have to ignore the cases where the a[i] == '-'; that's it 👍
public:
    int div(int x){
        if(x%2 ==0 ){
            return x/2;
        }
        else{
            return (x+1)/2;
        }
    }
    string reverseOnlyLetters(string s) {
        char *a = new char[s.length()+1];// because char has a bad habbit to store '\0' in the end. 'O(1)'
        strcpy(a,s.c_str()); //created the string into character array. 'O(n)'
        int forward = 0;
        int backward = 0;
        for(int i = 0; i<div(s.length()); i++){
            if (a[s.length()-backward]!='-'){
                if(a[forward]!= '-'){
                    char temp = a[forward];
                    a[forward]= a[s.length()- backward];
                    a[s.length()- backward] = temp;
                    backward++;
                    forward++;
                }
                else{
                    forward++;
                }
            }
            else if (a[forward]!='-'){
                if(a[s.length() - backward]!= '-'){
                    char temp = a[forward];
                    a[forward]= a[s.length() - backward];
                    a[s.length() - backward] = temp;
                    backward++;
                    forward++;
                }
                else{
                    backward++;
                }
            }
        }
        for(int i = 0; i < s.length(); i++){
            cout<<a[i];
        }

        return s;
    }
};
// @lc code=end

