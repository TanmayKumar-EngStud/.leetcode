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
    string reverseWords(string s) {
        //first we need to change the String into char Array.
        // Sample :-
        // string temp = "cat";
        // char * tab2 = new char [temp.length()+1];
        // strcpy (tab2, temp.c_str());
        vector<int> spaceIndex = {-1};
        char * c = new char[s.length()+1];
        strcpy(c, s.c_str());
        for(int i=0; i<s.length(); i++){
            if(c[i] == ' '){
                spaceIndex.push_back(i); // store all the locations of blank spaces.
            }
        }
        spaceIndex.push_back(s.length());
        int i=0;
        for(int x= spaceIndex[i]; i<spaceIndex.size(); x=spaceIndex[++i]){
            //now we have to do mirroring of all the
            // words that are lying in between spaceIndex[i]<-> spaceIndex[++i];
            if(i != spaceIndex.size()-1){// this condition is needed to prevent it from unnecessary heap-overflow.
                // index will range from [(x+1), (spaceIndex[i+1]-1)] !note that here don't do i++ or ++i inside the spaceIndexing. otherwise the value of i will also change.
                int j = 0;
                for (char alpha = c[x+1]; j < spaceIndex[i+1]; alpha= c[(x+1)+(++j)]){
                    cout<<alpha;
                }
                cout<<endl;
            }
        }
        return s;
    }
};
// @lc code=end

