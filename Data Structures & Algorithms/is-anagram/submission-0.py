class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hashmap1 = {}
        hashmap2 = {}

        for letter in s:
            if letter not in hashmap1:
                hashmap1[letter] = 0
            hashmap1[letter] += 1
        
        for letter in t:
            if letter not in hashmap2:
                hashmap2[letter] = 0
            hashmap2[letter] += 1
        
        return hashmap1 == hashmap2