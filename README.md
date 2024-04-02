The Maximum Adjacent Minimum Degree Algorithm (MAMA) is a heuristic algorithm used to find a near-optimal solution for the Minimum Vertex Cover problem in graph theory.
In this algorithm, vertices are selected based on their degrees and the degrees of their adjacent vertices. \

Specifically, the algorithm prioritizes vertices with the minimum degree among their neighbours, aiming to cover as many edges in the graph as possible while minimizing 
the number of selected vertices. MAMA iteratively selects vertices and removes them along with their incident edges until all edges in the graph are covered. 
Despite its simplicity, MAMA often yields satisfactory results and is widely used in practice due to its efficiency and ease of implementation.
