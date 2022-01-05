from node import *
from huffman import *

if __name__ == "__main__":
    # ky tu cho cay huffman
    chars = ['h', 'o', 'a', 'n', 'g']
    
    # xac xuat cua ky tu
    freq = [40, 30, 10, 5 , 15]
    
    nodes = []

    nodes = main(nodes, chars, freq)
    print_node(nodes[0])