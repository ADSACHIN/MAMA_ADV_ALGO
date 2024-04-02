class Graph:
    def __init__(self, vertices, edges):
       
        self.vertices = set(vertices)  # Store vertices as a set
        self.edges = edges  # Store edges as a list of tuples

    def calculate_degrees(self):
       
        degrees = {vertex: 0 for vertex in self.vertices}  # Initialize degrees dictionary
        # Count the degree of each vertex by iterating through edges
        for edge in self.edges:
            degrees[edge[0]] += 1
            degrees[edge[1]] += 1
        return degrees

    def remove_vertex_and_incident_edges(self, vertex):
        
        self.vertices.remove(vertex)  # Remove the vertex from the set of vertices
        # Remove edges incident to the vertex from the list of edges
        self.edges = [edge for edge in self.edges if vertex not in edge]

def minimum_vertex_cover(graph):
    
    vertex_cover = set()  # Initialize an empty set to store the minimum vertex cover
    # Iterate until all edges are covered
    while graph.edges:
        degrees = graph.calculate_degrees()  # Calculate the degrees of vertices
        min_degree_vertex = min(degrees, key=degrees.get)  # Find the vertex with minimum degree
        
        print("Minimum Degree Vertex:", min_degree_vertex)  # Print the minimum degree vertex
        
        adjacent_degrees = []
        # Find degrees of adjacent vertices to the minimum degree vertex
        for edge in graph.edges:
            if min_degree_vertex in edge:
                adjacent_vertex = edge[1] if edge[0] == min_degree_vertex else edge[0]
                adjacent_degrees.append((adjacent_vertex, degrees[adjacent_vertex]))

        if adjacent_degrees:
            # Select the adjacent vertex with maximum degree and add it to the cover
            max_degree_adjacent_vertex = max(adjacent_degrees, key=lambda x: x[1])
            
            print("Maximum Degree Adjacent Vertex:", max_degree_adjacent_vertex[0])  # Print the maximum degree adjacent vertex
            
            vertex_cover.add(max_degree_adjacent_vertex[0])  # Add the vertex to the cover
            
            print("Vertex", max_degree_adjacent_vertex[0], "added to cover")  # Print the addition of vertex to cover
            
            graph.remove_vertex_and_incident_edges(max_degree_adjacent_vertex[0])  # Remove the selected vertex and its incident edges
            
            print("Vertex", max_degree_adjacent_vertex[0], "and its incident edges removed from the graph")  # Print the removal of vertex and its edges
        else:
            print("No adjacent vertices found for minimum degree vertex", min_degree_vertex)  # Print if no adjacent vertices found
            
            graph.remove_vertex_and_incident_edges(min_degree_vertex)  # Remove the minimum degree vertex and its edges
            
            print("Vertex", min_degree_vertex, "and its incident edges removed from the graph")  # Print the removal of vertex and its edges
    return vertex_cover

# Define vertices and edges of the graph
vertices1 = {'A', 'B', 'C', 'D', 'E'}
edges1 = [('A', 'B'), ('A', 'C'), ('B', 'C'), ('B', 'D'), ('C', 'D'), ('C', 'E')]

vertices2 = {'A', 'B', 'C', 'D', 'E', 'F'}
edges2 = [('A', 'B'), ('A', 'C'), ('B', 'C'), ('B', 'D'), ('C', 'D'), ('C', 'E'), ('D', 'E'), ('E', 'F')]

vertices3 = {'A', 'B', 'C', 'D', 'E'}
edges3 = {('A', 'B'), ('A', 'C'), ('B', 'C'), ('B', 'D'), ('C', 'D'), ('C', 'E'), ('D', 'E')}

vertices4 = {'A', 'B', 'C', 'D', 'E', 'F'}
edges4 = {('A', 'B'), ('A', 'C'), ('B', 'C'), ('B', 'D'), ('C', 'D'), ('C', 'E'), ('E', 'F'), ('D', 'F')}

# Create graph objects
graph1 = Graph(vertices1, edges1)
graph2 = Graph(vertices2, edges2)
graph3 = Graph(vertices3, edges3)
graph4 = Graph(vertices4, edges4)

# Find minimum vertex covers
vertex_cover1 = minimum_vertex_cover(graph1)
vertex_cover2 = minimum_vertex_cover(graph2)
vertex_cover3 = minimum_vertex_cover(graph3)
print("=====")
vertex_cover4 = minimum_vertex_cover(graph4)

# Print minimum vertex covers
print("Minimum Vertex Cover (Example 1):", vertex_cover1)
print("Minimum Vertex Cover (Example 2):", vertex_cover2)
print("Minimum Vertex Cover (Example 3):", vertex_cover3)

print("Minimum Vertex Cover (Example 4):", vertex_cover4)
