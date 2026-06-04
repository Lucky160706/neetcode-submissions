# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = [] # (1) Tạo ra DUY NHẤT một mảng res

        def inorder(node): # (2) Hàm phụ bắt đầu ở đây
            if not node:
                return
            inorder(node.left)
            res.append(node.val) # (3) Gọi res từ bên ngoài vào
            inorder(node.right)

        inorder(root)
        return res

