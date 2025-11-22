class Solution:
    # in this solution we are keeping the right most idx of each character in the string.
    # and then while iterarting inside the loop we are checking if the last char of the res
    # is bigger than the cur character and it's occurence in the string is there which 
    # can be easily checked by comparing the current idx with the idx in the lookup map we have created
    # and if that;s the case we will simply pop the element from the result.
    # and in the end we will push the cur char into the result.
    def removeDuplicateLetters(self, s: str) -> str:
        rindex = {c: i for i, c in enumerate(s)}
        result = []
        for i, c in enumerate(s):
            if c not in result:
                while result and c < result[-1] and i < rindex[result[-1]]:
                    result.pop()
                result.append(c)
        return ''.join(result)