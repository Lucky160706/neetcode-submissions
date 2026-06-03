class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        open_bracket = ['(', '{', '[']
        close_bracket = [')', '}', ']']
        for char in s:
            if char in open_bracket:
                stack.append(char)
            elif char in close_bracket:
                # print(close_bracket.index(char))
                if stack and stack[-1] == open_bracket[close_bracket.index(char)]:
                    stack.pop()
                else:
                    return False
        return True if not stack else False