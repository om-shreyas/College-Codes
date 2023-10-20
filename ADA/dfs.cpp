#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
int inf = INT_MAX;
using namespace std;
int ** Graph(int nodes){
    int** Graph = new int*[nodes];
    for(int i = 0;i<nodes;i++){
        Graph[i] = new int[nodes];
        for(int j = 0;j<nodes;j++){
            if(i==j){
                Graph[i][j]=inf;
            }
            else{
                Graph[i][j]= inf;
            }
        }
    }
    return(Graph);
}
int ** create_graph(int ** Graph,int nodes){
    int bi_directional;
    cout<<"Is the Graph Bi-Directional(0: No 1:yes): ";
    cin>>bi_directional;

    while(true){
        int i,j;
        cout<<"Enter starting Edge (enter -1 to exit): ";
        cin>>i;
        if(i==-1){
            break;
        }
        cout<<"Enter ending Edge: ";
        cin>>j;
        int w;
        cout<<"Ender path weight: ";
        cin>>w;

        Graph[i-1][j-1] = w;
        if(bi_directional==1){
            Graph[j-1][i-1] = w;
        }
    }
    return Graph;
}
int node_in(vector<int> v,int j){
    for(auto i = v.begin();i<v.end();i++){
        if(j==*i){
            return(1);
        }
    }
    return(0);
}
int main()
{
    int nodes;
    cout<<"Enter the total number of nodes: ";
    cin>>nodes;
    int ** graph = Graph(nodes);
    graph = create_graph(graph,nodes);

    int min = INT_MAX;
    vector<int> visited_nodes;

    vector<int> queue;
    queue.push_back(0);
    visited_nodes.push_back(0);
    int answer = INT_MAX;

   while (!queue.empty())
    {
        int i = queue[queue.size()-1];
        queue.pop_back();

        for (int j = 0; j < nodes; j++)
        {
            if(graph[i][j] != inf && node_in(visited_nodes,j)==0)
            {
                cout<<i<<"-"<<graph[i][j]<<"-"<<j<<endl;
                queue.push_back(j);
                visited_nodes.push_back(j);
            }
        }
    }
}