import networkx as nx
import sys
class AllNodes:
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

    def make_output_file(self):
        
        with open(self.output_file, 'w') as file:
            file.write(f"{len(self.graph)}\n")
            for node in self.graph:
                file.write(f"{node} ")

if __name__ == "__main__":

    input = sys.argv[1]
    output = sys.argv[2]

    A = AllNodes(input, output)

    A.make_output_file()
    