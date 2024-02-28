import networkx as nx
import sys

class Verifier:
    def __init__(self, in_file, out_file):
        self.input_file = in_file
        self.output_file = out_file
        self.graph = nx.DiGraph()
        self.num_classes=0
        self.initialize_graph()

    def initialize_graph(self):
        with open(self.input_file) as file:

            line = file.readline()
            self.num_classes = int(line)
            
            for i in range(1, self.num_classes+1):
                self.graph.add_node(i)
                line = file.readline()
                edges = [int(num) for num in line.split()]

                for source in edges[1:]:
                    self.graph.add_edge(source, i)
    
    def procerss_output_file(self):
        with open(self.output_file) as file:
            
    
            num_nodes_to_remove = int(file.readline())

            nodes_to_remove = file.readline().split()
            nodes_to_remove = [int(value) for value in nodes_to_remove]

            for node in nodes_to_remove:
                self.graph.remove_node(node)
    
    def verify(self):
        cycles = list(nx.simple_cycles(self.graph))

        if(len(cycles)==0):
            return True
        else:
            return False

if __name__ == "__main__":

    input = sys.argv[1]
    output = sys.argv[2]

    V = Verifier(input, output)

    V.initialize_graph()
    V.procerss_output_file()

    if V.verify():
        print("OUTPUT IS CORRECT")
    else:
        print("OUTPUT FILE IS INCORRECT")
