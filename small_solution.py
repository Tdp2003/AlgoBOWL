import networkx as nx
#import matplotlib.pyplot as plt

class DigraphProcessor:

    def __init__(self, file):
        self.input_file = file
        self.graph = nx.DiGraph()
        self.num_classes=0
        self.initialize_graph()

    def initialize_graph(self):
        with open(self.input_file) as file:

            line = file.readline()
            self.num_classes = int(line)
            
            for i in range(1, self.num_classes+1):
                print(f"creating Graph node {i}")
                self.graph.add_node(i)
                line = file.readline()
                edges = [int(num) for num in line.split()]

                for source in edges[1:]:
                    print(f"    creating edge ({source}, {i})")                
                    self.graph.add_edge(source, i)
    
    def generate_removable_nodes(self, cycles):
        node_occurences = [0]*self.num_classes
        for cycle in cycles:
            for node in cycle:
                print(f"increment occurences {node}")
                node_occurences[node-1] +=1
        
        solution_set =[]
        max_occurences = max(node_occurences)
        for i in range(1, len(node_occurences)+1):
            if(node_occurences[i-1] == max_occurences):
                print(f"        Added {i} to solution set")
                solution_set.append(i)
        return solution_set
    
    def generate_solution_optimal_case(self):
        print("Begin Solution Generation")
        solution_set = []
        cycles = list(nx.simple_cycles(self.graph))
        while len(cycles) > 0:
            
            removable_nodes = self.generate_removable_nodes(cycles)  
            print(f"    Removable Nodes Generated: {removable_nodes}")
            if len(removable_nodes) > 0:
                self.graph.remove_node(removable_nodes[0])
                solution_set.append(removable_nodes[0])

            cycles = list(nx.simple_cycles(self.graph))
        return solution_set
    
    
if __name__ == "__main__":

    file_path = "./inputs/input_group725.txt"
    processor = DigraphProcessor(file_path)
    print(f"SOLUTION: {processor.generate_solution_optimal_case()}")




