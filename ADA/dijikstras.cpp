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
                Graph[i][j]=0;
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

        Graph[i][j] = w;
        if(bi_directional==1){
            Graph[j][i] = w;
        }
    }
    return Graph;
}
void print_graph(int ** graph,int nodes){
    cout <<" \t";
    for(int i =0;i<nodes;i++){
        cout<<i<<"\t";
    }
    cout<<endl;
    for(int i =0;i<nodes;i++){
        cout<<i<<"\t";
        for(int j=0;j<nodes;j++){
            if(graph[i][j]==inf){
                cout<<"inf"<<"\t";
            }
            else{
                cout<<graph[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
}
int node_in(vector<int> v,int j){
    for(auto i = v.begin();i<v.end();i++){
        if(j==*i){
            return(1);
        }
    }
    return(0);
}
int main(){
    int nodes;
    cout<<"Enter the total number of nodes: ";
    cin>>nodes;
    int ** graph = Graph(nodes);
    graph = create_graph(graph,nodes);

    vector<int> nodes_covered;

    int start;
    cout<<"Enter Start Node: ";
    cin>>start;
    nodes_covered.push_back(start);
    int path_weight = 0;
    while(nodes_covered.size()<nodes){
        int min_weight = -1;
        int min_end_node = -1;
        int min_start_node = -1;
        auto i = nodes_covered.end()-1;
        for(int j = 0;j<nodes;j++){
            if(node_in(nodes_covered,j)==0){
                if(min_weight==-1 || min_weight>graph[*i][j]){
                    min_weight = graph[*i][j];
                    min_end_node = j;
                    min_start_node = *i;
                }
            }
        }
        cout<<min_start_node<<"--"<<min_weight<<"-->"<<min_end_node<<endl;
        nodes_covered.push_back(min_end_node);
        path_weight +=min_weight;

    }
    cout<<"The path weight: "<<path_weight<<endl;
    return 0;
}