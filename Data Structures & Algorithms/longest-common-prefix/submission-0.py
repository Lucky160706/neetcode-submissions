class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ""
        min_length = 201
        for str in strs:
            if len(str) < min_length:
                min_length = len(str)
        next = True
        
        if min_length == 0:
            return ""
        
        for i in range(min_length):
            for j in range(len(strs) - 1):
                if strs[j][i] != strs[j + 1][i]:
                    next = False
                    break
                elif strs[j][0] != strs[j + 1][0]:
                    return ""
            if next:
                prefix += strs[0][i]
            next = True
        return prefix 
