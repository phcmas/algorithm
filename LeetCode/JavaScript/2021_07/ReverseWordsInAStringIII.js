/** 557. Reverse Words in a String III */
/** Given a string s, reverse the order of characters in each word within a 
 *  sentence while still preserving whitespace and initial word order.
 * 
 *  Example 1:
 *  Input: s = "Let's take LeetCode contest"
 *  Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 *  Example 2:
 *  Input: s = "God Ding"
 *  Output: "doG gniD"
 * 
 *  Constraints:
 *  1 <= s.length <= 5 * 10^4
 *  s contains printable ASCII characters.
 *  s does not contain any leading or trailing spaces.
 *  There is at least one word in s.
 *  All the words in s are separated by a single space. */

var reverseWords = function(s) {
    var words = s.split(" ");
    var answer = "";
    
    for (let i = 0; i < words.length; ++i) {
        for (let j = words[i].length-1; j >= 0; --j) {
            answer += words[i][j];
        }
        
        if (i < words.length-1) answer += " ";
    }
    
    return answer;
};

var reverseWords2 = function(s) {
    var words = s.split(" ");
    var answer = "";

    for (let i = 0; i < words.length; ++i) {
        answer += words[i].split("").reverse().join("") + " ";
    }

    return answer.substr(0, answer.length-1);
};

var s0 = "Let's take LeetCode contest";
var s1 = "God Ding";

var ans0 = reverseWords2(s0);
var ans1 = reverseWords2(s1);

console.log(ans0); 
console.log(ans1); 
