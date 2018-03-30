class Node:
    def __init__(self, val):
        self.val = val;
        self.left = None
        self.right = None


def minBST(arr):
    if len(arr) == 0:
        return
    elif len(arr) == 1:
        return Node(arr[0])
    else:
        mid = len(arr) / 2
        root = Node(arr[mid])
        root.left = minBST(arr[:mid])
        root.right = minBST(arr[mid + 1:])
        return root


def printLevelOrder(root):
    for level in range(1, height_tree(root) + 1):
        printGivenLevel(root, level)


def printGivenLevel(root, level):
    if root is None:
        return
    if level == 1:
        print(root.val)
    if level > 1:
        printGivenLevel(root.left, level - 1)
        printGivenLevel(root.right, level - 1)


def height_tree(root):
    if root == None:
        return 0
    else:
        return max(height_tree(root.left), height_tree(root.right)) + 1


l = [1, 2, 3, 5, 7, 9]
r = (minBST(l))
printLevelOrder(r)
