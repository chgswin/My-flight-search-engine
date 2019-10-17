# My flight search engine
**1. Motivation**
The project aims to create a flight search engine app based on graph theory algorithms.

**2. Mathematical problem**
The flight map is represented by a large graph, where each node is an airport and each flight is a edge connecting two nodes (connecting flights between two airports). 

The nature of the problem implies that:
1. Not every pair of airports are connected directly to each other.
2. There may be many flights connecting two airports.

**3. Implementation **

The optimization problem is to find the shortest path connecting two airports together. There are several graph algorithms to find such path, namely, Dijkstra, Bellman-Ford, A*, etc.

With this particular problem, K-shortest Dijkstra algorithm is used to find as many results as possible.

The program supports two optimization criteria:
1. Cost efficient (the cheapest flights).
2. Time efficient (the shortest flights).
