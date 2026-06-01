class Solution:
    def isPalindrome(self, s: str) -> bool:
        arr = []
        for char in s:
            if 'A' <= char <= 'Z' or 'a' <= char <= 'z' or '0' <= char <= '9':
                arr.append(char.lower())
        l, r = 0, len(arr) - 1
        while l <= r:
            if arr[l] != arr[r]:
                return False
            l += 1
            r -= 1
        return True
        
        