#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;
struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    string name;
    vector<adjVertex> adj;
    int ID;
    vertex*parent;
    int dis;
    int distance;
    bool visited;
};

class Graph
{
    public:
        Graph();
        virtual ~Graph();
        void addEdge(string v1, string v2, int weight);
        void addVertex(string name);
	void shortestPath(string start,string end);
	void assignDistricts();
        void allOver();
    protected:
    private:
        vector<vertex> vertices;
        void BFTraversalLabel(string startingCity, int distID);
};

#endif // GRAPH_H
