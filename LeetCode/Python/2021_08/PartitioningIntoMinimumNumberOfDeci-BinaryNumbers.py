'''
1689. Partitioning Into Minimum Number Of Deci-Binary Numbers 
A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

Example 1:
Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32

Example 2:
Input: n = "82734"
Output: 8

Example 3:
Input: n = "27346209830709182346"
Output: 9
 
Constraints:
1 <= n.length <= 10^5
n consists of only digits.
n does not contain any leading zeros and represents a positive integer. '''

# minPartitions는 내가 처음 고안한 풀이.. 통과는 했으나 너무 느리다. minPartitions2는 Solution을 보고 참고한 풀이

class Solution:
    def minPartitions(self, n: str) -> int:
        answer = 0
        str = n

        while (int(str) > 0):
            str_list = []
            for i in range(len(str)):
                if str[i] > '0':
                    str_list.append(chr(ord(str[i])-1))
        
            str = ''.join(str_list)
            answer += 1

        return answer
    
    def minPartitions2(self, n: str) -> int:
        answer = 0

        for char in n:
            answer = max(ord(char)-ord('0'), answer)
        
        return answer


test0 = Solution()
test1 = Solution()
test2 = Solution()

print(test0.minPartitions("32")) # 3
print(test1.minPartitions("82734")) # 8
print(test2.minPartitions("27346209830709182346")) # 9



