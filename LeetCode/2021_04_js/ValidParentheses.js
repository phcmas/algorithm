/** 20. Valid Parentheses */
/** Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *  An input string is valid if:
 *  Open brackets must be closed by the same type of brackets.
 *  Open brackets must be closed in the correct order.
 * 
 *  Example 1:
 *  Input: s = "()"
 *  Output: true
 * 
 *  Example 2:
 *  Input: s = "()[]{}"
 *  Output: true
 * 
 *  Example 3:
 *  Input: s = "(]"
 *  Output: false
 * 
 *  Example 4:
 *  Input: s = "([)]"
 *  Output: false
 * 
 *  Example 5:
 *  Input: s = "{[]}"
 *  Output: true
 * 
 *  Constraints:
 *  1 <= s.length <= 10^4
 *  s consists of parentheses only '()[]{}'. */

var isValid = function(s) {
    let stack = [];
    let pair = {
        '(' : ')',
        '[' : ']',
        '{' : '}'
    };

    for (let c of s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else {
            let top = stack.pop();
            if (pair[top] != c) return false;
        }
    }

    return stack.length == 0;
};

var ans0 = isValid("()");
var ans1 = isValid("()[]{}");
var ans2 = isValid("(]");
var ans3 = isValid("([)]");
var ans4 = isValid("{[]}");
var ans5 = isValid("]");

console.log(ans0); // true
console.log(ans1); // true
console.log(ans2); // false
console.log(ans3); // false
console.log(ans4); // true
console.log(ans5); // false

