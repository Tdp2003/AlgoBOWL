import networkx as nx

class DigraphProcessor:
    def __init__(self, file):
        self.input_file = file
        self.graph = nx.DiGraph()
        self.load_graph()

    def load_graph(self):
        with open(self.input_file, 'r') as f:
            self.num_classes = int(f.readline().strip())
            for i in range(1, self.num_classes + 1):
                edges = list(map(int, f.readline().split()))
                for source in edges[1:]:
                    self.graph.add_edge(source, i)

    def remove_cycles(self):
        removed_nodes = []
        sccs = list(nx.strongly_connected_components(self.graph))
        for scc in sccs:
            if len(scc) > 1:  # If the SCC represents a cycle (more than one node)
                # Choose the node with the lowest degree (in-degree + out-degree) to remove
                node_to_remove = max(scc, key=lambda node: self.graph.in_degree(node) + self.graph.out_degree(node))
                self.graph.remove_node(node_to_remove)
                removed_nodes.append(node_to_remove)
        return removed_nodes

    def generate_solution(self):
        removed_nodes = self.remove_cycles()
        while removed_nodes:  # Repeat the process until no more cycles
            more_nodes = self.remove_cycles()
            removed_nodes.extend(more_nodes)
            if not more_nodes: #no mroe removed here
                break
        return removed_nodes

if __name__ == "__main__":
    #Inputs that we already have optimized output for before using newSol: 729, 742, 746, 754, 765, 774, 778, 780, 781, 784, 790, 791, 797
    file_path = "./inputs/input_group796.txt"# Update this path as needed
    processor = DigraphProcessor(file_path)
    removed_nodes = processor.generate_solution()
    with open("output.txt", "w") as f:
        print(len(removed_nodes), file=f)
        print(*removed_nodes, file=f)