/** 680. Valid Palindrome II */
/** Given a string s, return true if the s can be palindrome after deleting at most one character from it.
 * 
 *  Example 1:
 *  Input: s = "aba"
 *  Output: true
 * 
 *  Example 2:
 *  Input: s = "abca"
 *  Output: true
 *  Explanation: You could delete the character 'c'.
 * 
 *  Example 3:
 *  Input: s = "abc"
 *  Output: false
 * 
 *  Constraints:
 *  1 <= s.length <= 10^5
 *  s consists of lowercase English letters. */

var isPalindrome = function(s) {
    var left = 0;
    var right = s.length-1;
    
    while (left <= right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    
    return true;
};

var validPalindrome = function(s) {
    var left = 0;
    var right = s.length-1;
    
    while (left <= right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else if (isPalindrome(s.substring(left, right))) {
            return true;
        } else if (isPalindrome(s.substring(left+1, right+1))) {
            return true;
        } else {
            return false;
        }
    }
    
    return true;
};

var s0 = "aba";
var ans0 = validPalindrome(s0);

var s1 = "abca";
var ans1 = validPalindrome(s1);

var s2 = "abc";
var ans2 = validPalindrome(s2);

console.log(ans0); // true
console.log(ans1); // true
console.log(ans2); // false

