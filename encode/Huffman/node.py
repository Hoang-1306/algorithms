class Node:
    def __init__(self, freq, symbol, left=None, right=None):

        self.freq = freq

        self.symbol = symbol

        self.left = left
  

        self.right = right
  

        self.huffman = ''

def print_node(node, val=''):

    new_val = val + str(node.huffman)
  

    if(node.left):
        print_node(node.left, new_val)
    if(node.right):
        print_node(node.right, new_val)
  
    if(not node.left and not node.right):
        print(f"{node.symbol} -> {new_val}")