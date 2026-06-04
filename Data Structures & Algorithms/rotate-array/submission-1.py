class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k = k % n  # Xử lý trường hợp k lớn hơn độ dài mảng
        
        nums.reverse() # Lật toàn bộ mảng (hàm này có tác dụng in-place)
        
        # Cắt mảng, lật ngược, và gán ĐÈ trực tiếp lên mảng gốc
        nums[0: k] = reversed(nums[0: k])
        nums[k: n] = reversed(nums[k: n])

        
        