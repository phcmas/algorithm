/** 1736. Latest Time by Replacing Hidden Digits */
/** You are given a string time in the form of hh:mm, where some of the digits 
 *  in the string are hidden (represented by ?).
 * 
 *  The valid times are those inclusively between 00:00 and 23:59.
 *  Return the latest valid time you can get from time by replacing the hidden digits.
 * 
 *  Example 1:
 *  Input: time = "2?:?0"
 *  Output: "23:50"
 *  Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
 * 
 *  Example 2:
 *  Input: time = "0?:3?"
 *  Output: "09:39"
 * 
 *  Example 3:
 *  Input: time = "1?:22"
 *  Output: "19:22"
 * 
 *  Constraints:
 *  time is in the format hh:mm.
 *  It is guaranteed that you can produce a valid time from the given string. */

var maximumTime = function(time) {
    var hourAndMinute = time.split(":");
    var hour = hourAndMinute[0];
    var minute = hourAndMinute[1];
    var newHour = "";
    var newMinute = "";

    if (hour.charAt(0) == '?') {
        if (hour.charAt(1) == '?' || hour.charAt(1) < '4') {
            newHour += '2';
        } else {
            newHour += '1';
        }
    } else {
        newHour += hour.charAt(0);
    }

    if (hour.charAt(1) == '?') {
        if (newHour.charAt(0) == '2') {
            newHour += '3';
        } else {
            newHour += '9';
        }
    } else {
        newHour += hour.charAt(1);
    }

    if (minute.charAt(0) == '?') {
        newMinute += '5';
    } else {
        newMinute += minute.charAt(0);
    }

    if (minute.charAt(1) == '?') {
        newMinute += '9';
    } else {
        newMinute += minute.charAt(1);
    }

    return newHour + ":" + newMinute;
};

var time0 = "2?:?0";
var time1 = "0?:3?";
var time2 = "1?:22";
var time3 = "?4:03";

var ans0 = maximumTime(time0);
var ans1 = maximumTime(time1);
var ans2 = maximumTime(time2);
var ans3 = maximumTime(time3);

console.log(ans0);
console.log(ans1);
console.log(ans2);
console.log(ans3);

