/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (77.08%)
 * Likes:    2308
 * Dislikes: 145
 * Total Accepted:    373.5K
 * Total Submissions: 484.6K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * Given a string s, reverse the order of characters in each word within a
 * sentence while still preserving whitespace and initial word order.
 *
 *
 * Example 1:
 * Input: s = "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * Example 2:
 * Input: s = "God Ding"
 * Output: "doG gniD"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * s contains printable ASCII characters.
 * s does not contain any leading or trailing spaces.
 * There is at least one word in s.
 * All the words in s are separated by a single space.
 *
 *
 */

// @lc code=start
class Solution {
public:
    int div(int x){
        if(x%2==0){
            return x/2;
        }
        else{
            return (x+1)/2;
        }
    }
    string reverseWords(string s) {
        vector<int> spaceIndex = {-1};
        char * c = new char[s.length()+1];
        strcpy(c, s.c_str());
        for(int i=0; i<s.length(); i++){
            if(c[i] == ' '){
                spaceIndex.push_back(i); // store all the locations of blank spaces.
            }
        }
        spaceIndex.push_back(s.length());
        
        for(int i =0; i< spaceIndex.size()-1; i++){
            // it will tell the particular location of all the spaces.
            // for every element in between the spaces.
            // i.e from c[spaceIndex[i]+1] till c[spaceIndex[i+1] -1]]
            // here the total number of elements in that particular word will be 
            // spaceIndex[i+1]-1 - (spaceIndex[i]+1)+1;
            // therefore the total number of elements will be spaceIndex[i+1] - (spaceIndex[i]+1)
            // so we need to take the div of,
            // := div(spaceIndex[i+1]-spaceIndex[i]-1);
            // we have to do mirroring of those elements that are going to lie in this range.
            
            for(int j = 0; j <div(spaceIndex[i+1]-spaceIndex[i]-1); j++){
                // here the value of j is the indexing range of the particular element
                // creating a temp character holder.
                char temp = c[spaceIndex[i]+1+j];
                c[spaceIndex[i]+1+j] = c[(spaceIndex[i+1]-1)-j]; 
                //here spaceIndex[i+1]-1 represent the last element of that element.
                 c[(spaceIndex[i+1]-1)-j] = temp;
            }
        }
        string ans="";
        for(int g=0; g<s.length(); g++){
            ans+=c[g];
        }
        return ans;
        // Time complexity = O(n**2)
        // Space Complexity = O(n)
    }
};
// @lc code=end

