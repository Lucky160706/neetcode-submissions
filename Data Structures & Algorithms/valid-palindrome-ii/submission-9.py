class Solution:
    def validPalindrome(self, s: str) -> bool:
        arr = list(s)
        l, r = 0, len(s) - 1
        count = 1
        arr1, arr2 = [], []
        while l <= r:
            if arr[l] != arr[r]:
                arr1 = arr.copy()
                arr1.pop(l)
                arr2 = arr.copy()
                arr2.pop(r)
                break
            else:
                l += 1
                r -= 1
        if l >= r:
            return True

        l1, r1 = 0, len(arr1) - 1
        l2, r2 = 0, len(arr2) - 1

        is_arr1_valid = True
        is_arr2_valid = True

        print(arr1, "\n")
        print(arr2)

        while l1 <= r1:
            if arr1[l1] != arr1[r1]:
                is_arr1_valid = False
                break
            l1 += 1
            r1 -= 1

        while l2 <= r2:
            if arr2[l2] != arr2[r2]:
                is_arr2_valid = False
                break
            l2 += 1
            r2 -= 1

        return is_arr1_valid or is_arr2_valid