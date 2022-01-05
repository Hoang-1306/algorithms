from node import *
def main(nodes, chars, freq):
    for x in range(len(chars)):
        nodes.append(Node(freq[x], chars[x]))
    
    while len(nodes) > 1:

        nodes = sorted(nodes, key=lambda x: x.freq)
    

        left = nodes[0]
        right = nodes[1]
    

        left.huffman = 0
        right.huffman = 1

        new_node = Node(left.freq + right.freq, left.symbol + right.symbol, left, right)
        nodes.remove(left)
        nodes.remove(right)
        nodes.append(new_node)
    return nodes