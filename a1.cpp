#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Define the Graph class to represent a graph structure
class Graph {
private:
    unordered_set<char> vertices; // Set to store vertices
    vector<pair<char, char>> edges; // Vector of pairs to store edges

public:
    // Constructor to initialize the graph with vertices and edges
    Graph(unordered_set<char> vertices, vector<pair<char, char>> edges) {
        this->vertices = vertices;
        this->edges = edges;
    }

    // Function to calculate the degree of each vertex in the graph
    unordered_map<char, int> calculate_degrees() {
        unordered_map<char, int> degrees;
        for (char vertex : vertices) {
            degrees[vertex] = 0;
        }
        for (auto edge : edges) {
            degrees[edge.first]++;
            degrees[edge.second]++;
        }
        return degrees;
    }

    // Function to remove a vertex and its incident edges from the graph
    void remove_vertex_and_incident_edges(char vertex) {
        vertices.erase(vertex);
        remove_incident_edges(vertex);
    }

    // Function to get the edges of the graph
    const vector<pair<char, char>>& get_edges() const {
        return edges;
    }

private:
    // Helper function to remove edges incident to a given vertex
    void remove_incident_edges(char vertex) {
        edges.erase(remove_if(edges.begin(), edges.end(), [vertex](const pair<char, char>& edge) {
            return edge.first == vertex || edge.second == vertex;
        }), edges.end());
    }
};

// Function to find the minimum vertex cover of a graph
unordered_set<char> minimum_vertex_cover(Graph &graph) {
    unordered_set<char> vertex_cover; // Initialize an empty set to store the minimum vertex cover
    // Iterate until all edges are covered
    while (!graph.get_edges().empty()) {
        
        auto degrees = graph.calculate_degrees(); // Calculate the degrees of vertices
        char min_degree_vertex = min_element(degrees.begin(), degrees.end(), [](pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        })->first; // Find the vertex with minimum degree

        cout << "Minimum Degree Vertex: " << min_degree_vertex << endl; // Print the minimum degree vertex

        vector<pair<char, int>> adjacent_degrees;
        // Find degrees of adjacent vertices to the minimum degree vertex
        for (auto edge : graph.get_edges()) {
            if (edge.first == min_degree_vertex) {
                adjacent_degrees.push_back({edge.second, degrees[edge.second]});
            } else if (edge.second == min_degree_vertex) {
                adjacent_degrees.push_back({edge.first, degrees[edge.first]});
            }
        }

        if (!adjacent_degrees.empty()) {
            // Select the adjacent vertex with maximum degree and add it to the cover
            auto max_degree_adjacent_vertex = max_element(adjacent_degrees.begin(), adjacent_degrees.end(), [](pair<char, int> a, pair<char, int> b) {
                return a.second < b.second;
            });
            
            cout << "Maximum Degree Adjacent Vertex: " << max_degree_adjacent_vertex->first << endl; // Print the maximum degree adjacent vertex
            
            vertex_cover.insert(max_degree_adjacent_vertex->first); // Add the vertex to the cover
            
            cout << "Vertex " << max_degree_adjacent_vertex->first << " added to cover" << endl; // Print the addition of vertex to cover
            
            graph.remove_vertex_and_incident_edges(max_degree_adjacent_vertex->first); // Remove the selected vertex and its incident edges
            
            cout << "Vertex " << max_degree_adjacent_vertex->first << " and its incident edges removed from the graph" << endl; // Print the removal of vertex and its edges
        } else {
            cout << "No adjacent vertices found for minimum degree vertex " << min_degree_vertex << endl; // Print if no adjacent vertices found
            
            // Always remove the minimum degree vertex if no adjacent vertices found
            graph.remove_vertex_and_incident_edges(min_degree_vertex); 
            cout << "Vertex " << min_degree_vertex << " and its incident edges removed from the graph" << endl; // Print the removal of vertex and its edges
        }
    }
    return vertex_cover;
}

int main() {
    // Define vertices and edges of the graph
    unordered_set<char> vertices1 = {'A', 'B', 'C', 'D', 'E'};
    vector<pair<char, char>> edges1 = {{'A', 'B'}, {'A', 'C'}, {'B', 'C'}, {'B', 'D'}, {'C', 'D'}, {'C', 'E'}};

    unordered_set<char> vertices2 = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<pair<char, char>> edges2 = {{'A', 'B'}, {'A', 'C'}, {'B', 'C'}, {'B', 'D'}, {'C', 'D'}, {'C', 'E'}, {'D', 'E'}, {'E', 'F'}};

    unordered_set<char> vertices3 = {'A', 'B', 'C', 'D', 'E'};
    vector<pair<char, char>> edges3 = {{'A', 'B'}, {'A', 'C'}, {'B', 'C'}, {'B', 'D'}, {'C', 'D'}, {'C', 'E'}, {'D', 'E'}};

    unordered_set<char> vertices4 = {'A', 'B', 'C', 'D', 'E', 'F'};
    vector<pair<char, char>> edges4 = {{'A', 'B'}, {'A', 'C'}, {'B', 'C'}, {'B', 'D'}, {'C', 'D'}, {'C', 'E'}, {'E', 'F'}, {'D', 'F'}};

    // Create graph objects
    Graph graph1(vertices1, edges1);
    Graph graph2(vertices2, edges2);
    Graph graph3(vertices3, edges3);
    Graph graph4(vertices4, edges4);

    // Find minimum vertex covers
    auto vertex_cover1 = minimum_vertex_cover(graph1);
    // Print minimum vertex covers
    cout << "Minimum Vertex Cover (Example 1): ";
    for (char vertex : vertex_cover1) {
        cout << vertex << " ";
    }
    cout << endl;
    cout << "=====" << endl;
    auto vertex_cover2 = minimum_vertex_cover(graph2);
    cout << "Minimum Vertex Cover (Example 2): ";
    for (char vertex : vertex_cover2) {
        cout << vertex << " ";
    }
    cout << endl;
    cout << "=====" << endl;

    auto vertex_cover3 = minimum_vertex_cover(graph3);
    cout << "Minimum Vertex Cover (Example 3): ";
    for (char vertex : vertex_cover3) {
        cout << vertex << " ";
    }
    cout << endl;
    cout << "=====" << endl;
    auto vertex_cover4 = minimum_vertex_cover(graph4);
    cout << "Minimum Vertex Cover (Example 4): ";
    for (char vertex : vertex_cover4) {
        cout << vertex << " ";
    }
    cout << endl;
    

    

    
    
}
