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
        # Tarjan's algorithm to find SCCs
        sccs = list(nx.strongly_connected_components(self.graph))
        for scc in sccs:
            if len(scc) > 1:  # If the SCC represents a cycle (more than one node)
                node_to_remove = min(scc)  # Example strategy: remove the node with the smallest value
                self.graph.remove_node(node_to_remove)
                removed_nodes.append(node_to_remove)
        return removed_nodes

    def generate_solution(self):
        removed_nodes = self.remove_cycles()
        while removed_nodes:  # Repeat the process until no more cycles (SCCs with more than one node) are found
            more_nodes = self.remove_cycles()
            removed_nodes.extend(more_nodes)
            if not more_nodes:  # No more nodes were removed in the last iteration
                break
        return removed_nodes

if __name__ == "__main__":
    file_path = "./inputs/input_group797.txt"  # Update this path
    processor = DigraphProcessor(file_path)
    removed_nodes = processor.generate_solution()
    with open("output.txt", "w") as f:
        print(len(removed_nodes), file=f)
        print(*removed_nodes, file=f)