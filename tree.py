
class Node:
    def __init__(self,val):
        self.left = None
        self.right = None
        self.val = val

def inOrderPrint(root):
    if(root.left):
        inOrderPrint(root.left)
    print root.val
    if(root.right):
        inOrderPrint(root.right)

def preOrderPrint(root):
    print root.val
    if(root.left):
        preOrderPrint(root.left)
    if(root.right):
        preOrderPrint(root.right)

def postOrderPrint(root):
    if(root.left):
        postOrderPrint(root.left)
    if(root.right):
        postOrderPrint(root.right)
    print root.val

#main

#
#       1
#   2       3
#4      5
#
#

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

#inOrderPrint(root)

#preOrderPrint(root)

postOrderPrint(root)
