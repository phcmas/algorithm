/** 1189. Maximum Number of Balloons */
/** Given a string text, you want to use the characters of text to 
 *  form as many instances of the word "balloon" as possible.
 *  You can use each character in text at most once. Return the maximum number of instances that can be formed.
 * 
 *  Example 1:
 *  Input: text = "nlaebolko"
 *  Output: 1
 * 
 *  Example 2:
 *  Input: text = "loonbalxballpoon"
 *  Output: 2
 * 
 *  Example 3:
 *  Input: text = "leetcode"
 *  Output: 0
 * 
 *  Constraints:
 *  1 <= text.length <= 10^4
 *  text consists of lower case English letters only. */

var checkBalloon = function(freq, count) {
    if (count < 7) return false;
    if (freq[1] < 1) return false;
    if (freq[0] < 1) return false;
    if (freq[11] < 2) return false;
    if (freq[14] < 2) return false;
    if (freq[13] < 1) return false;
    
    freq[1]--;
    freq[0]--;
    freq[11] -= 2;
    freq[14] -= 2;
    freq[13]--;
    
    return true;
};

var maxNumberOfBalloons = function(text) {
    var freq = new Array(26).fill(0);
    var count = 0;
    var answer = 0;
    
    for (var word of text) {
        if (word != 'b' && word != 'a' && word != 'l' && word != 'o' && word != 'n') continue;
        
        freq[word.charCodeAt(0)-97]++;
        count++;
        
        if (checkBalloon(freq, count)) {
            answer++;
            count -= 7;
        }
    }
    
    return answer;
};

var text0 = "nlaebolko";
var ans0 = maxNumberOfBalloons(text0);

var text1 = "loonbalxballpoon";
var ans1 = maxNumberOfBalloons(text1);

var text2 = "balllllllllllloooooooooon";
var ans2 = maxNumberOfBalloons(text2);

console.log(ans0); // 1
console.log(ans1); // 2
console.log(ans2); // 1

