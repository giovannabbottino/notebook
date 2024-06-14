
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.childrenleft = None
        self.childrenright = None

    def add(self, new_value):
        if compare_lexicographical(new_value, self.value) < 0:
            if self.childrenleft is None:
                self.childrenleft = TreeNode(new_value)
            else:
                self.childrenleft.add(new_value)
        else:
            if self.childrenright is None:
                self.childrenright = TreeNode(new_value)
            else:
                self.childrenright.add(new_value)

    def print_tree(self):
        if self.childrenleft:
            self.childrenleft.print_tree()
        print(self.value)
        if self.childrenright:
            self.childrenright.print_tree()


x = input()
lexicographical_order = {c: index for index, c in enumerate(x)}

def compare_lexicographical(str1, str2):
    len1, len2 = len(str1), len(str2)
    for i in range(min(len1, len2)):
        if str1[i] != str2[i]:
            return lexicographical_order[str1[i]] - lexicographical_order[str2[i]]
    return len1 - len2

n = int(input())

strn = input()
tree = TreeNode(strn)
for i in range(1, n):
    strn = input()
    tree.add(strn)

tree.print_tree()
