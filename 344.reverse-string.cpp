/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (73.34%)
 * Likes:    3741
 * Dislikes: 879
 * Total Accepted:    1.4M
 * Total Submissions: 1.9M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters s.
 * 
 * You must do this by modifying the input array in-place with O(1) extra
 * memory.
 * 
 * 
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s[i] is a printable ascii character.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int div(int i){
        if(i%2==0){
            return i/2;
        }
        else{
            return (i+1)/2;
        }
    }
    void reverseString(vector<char>& s) {
        // there will be two cases.
        // len := odd; div(len) = (len+1)/2
        // len := even; div(len) = (len)/2
        int len = s.size();
        for (int i= 0; i<div(len); i++){
            char temp = s[i];
            s[i] = s[(len-1)-i]; // [last index - the first index]
            s[(len -1)-i]= temp;
        }
        // Space complexity = O(1)
        // Time complexity = O(n)
    }
};
// @lc code=end

