/** 1122. Relative Sort Array */
/** Given two arrays arr1 and arr2, the elements of arr2 are distinct, 
 *  and all elements in arr2 are also in arr1.
 *  Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.
 *  Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.
 * 
 *  Example 1:
 *  Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 *  Output: [2,2,2,1,4,3,3,9,6,7,19]
 * 
 *  Constraints:
 *  1 <= arr1.length, arr2.length <= 1000
 *  0 <= arr1[i], arr2[i] <= 1000
 *  All the elements of arr2 are distinct.
 *  Each arr2[i] is in arr1. */

 var relativeSortArray = function(arr1, arr2) {
    let appeared = new Set();
    let newArr1 = [];
    let newArr2 = [];
    
    for (let i = 0; i < arr2.length; ++i) {
        for (let j = 0; j < arr1.length; ++j) {
            if (arr1[j] == arr2[i]) {
                appeared.add(arr1[j]);
                newArr1.push(arr1[j]);
            }
        }
    }
    
    for (let i = 0; i < arr1.length; ++i) {
        if (!appeared.has(arr1[i])) newArr2.push(arr1[i]);
    }
    
    newArr2.sort((a,b) => a-b);
    for (let i = 0; i < newArr2.length; ++i) {
        newArr1.push(newArr2[i]);
    }
    
    return newArr1;
};

var arr1 = [2,3,1,3,2,4,6,7,9,2,19];
var arr2 = [2,1,4,3,9,6];
var ans0 = relativeSortArray(arr1, arr2);

for (num in ans0) {
    console.log(num);
}