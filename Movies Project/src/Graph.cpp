#include "Graph.h"
#include <queue>

Graph::Graph()
{
    //ctor
}

Graph::~Graph()
{
    //dtor
}
vertex* Graph:: findVertex(string n)
{
    vertex* x=NULL;
    for(int i=0;i<vertices.size();i++)
    {
        if(vertices[i].name==n)
        {
            x= &vertices[i];
            break;
        }
    }
    return x;
}
void Graph:: BFTraversalLabel(string startingCity, int distID)
{
    queue <vertex*> q;
    vertex* v =findVertex(startingCity);//the start aka Denver ..
    v->visited=true;
    v->distance =0;
    v->dis=distID;
    q.push(v);
    while(!q.empty ())
    {
        vertex* n=q.front();
        q.pop();
        for(int x=0;x<n->adj.size();x++)//cities adjacent to n
        {
            if(! n->adj[x].v ->visited)//v is the pointer in the adjacent list
            {
                n->adj[x].v->visited=true;
                n->adj[x].v->distance =n->distance+1;
                n->adj[x].v->parent=n;
                n->adj[x].v->dis=n->dis;
                q.push(n->adj[x].v);
            }
        }
    }
}
void Graph:: assignDistricts()
{
    int j=1;
    for(int i=0;i<vertices.size();i++)
    {
        if(vertices[i].dis==-1)
        {
            BFTraversalLabel(vertices[i].name,j);
            j+=1;
        }
    }

}
void Graph::addEdge(string v1, string v2, int weight)
{

    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == v1)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j].name == v2 && i != j)
                {
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                }
            }//2d for end
        }//end if
    }//1st for end
}
void Graph::addVertex(string n)
{
    bool found = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == n)
        {
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false)
    {
        vertex v;
        v.name = n;
        v.dis=-1;
        v.visited=false;
        v.parent=NULL;
        vertices.push_back(v);
    }
}
void Graph:: allOver()
{
    for(int i=0;i<vertices.size();i++)
    {
        vertices[i].visited=false;
        vertices[i].parent=NULL;

    }
}
void Graph::shortestPath(string start,string end)
{
    vertex *st=NULL;
    vertex *e=NULL;
    int INT_MAX=9999999999999999;
    for(int i=0;i<vertices.size();i++)
    {
        vertices[i].parent=NULL;
        vertices[i].visited=false;
        vertices[i].distance=INT_MAX;
        if(vertices[i].name==start)
        {
            st= &vertices[i];
        }
        if(vertices[i].name==end)
            e=&vertices[i];
    }
    if(st==NULL)
    {
        cout << " Your city doesn't exist" << endl;
    }
    ///////////////////
    else if( st->dis !=e->dis )
    {
        cout << "No safe path between cities" << endl;
    }
    //////////////////////
    else
    {

    st->visited=true;
    st->distance=0;
    vector<vertex*> solved;
    solved.push_back(st);
    vertex *parent=NULL;
     int dist=0;
    vector<vertex*>path;
     while (!e->visited)
    {

         vertex *solvedV=NULL;

          int minDistance = INT_MAX;
        for(int x = 0;x<solved.size();x++)
         {
            vertex *s = solved[x];
             for(int y = 0;y<s->adj.size();y++)
             {
                 if(s->adj[y].v->visited!=true)
                 {
                     dist = s->distance + s->adj[y].weight;

                     if(dist < minDistance)
                     {
                        solvedV = s->adj[y].v;
                        minDistance = dist;
                        parent = s;
                     }
                 }
            }

             }
              solvedV->distance = minDistance;
                solvedV->parent = parent;
                solvedV->visited = true;
                solved.push_back(solvedV);

     }
     path.push_back(e);
     cout<<e->distance;
      while(e->parent!=NULL)
      {
        path.push_back(e->parent);
        e=e->parent;
      }
       for(int xx=path.size()-1;xx>-1;xx--)
        {
              cout<<","<<path[xx]->name;
        }
        cout<<""<<endl;
    }
}
