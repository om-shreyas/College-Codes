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
    int nodes = 3;
    int ** graph = Graph(nodes);
    graph = create_graph(graph,nodes);

    int ** result_graph = Graph(nodes);


    for(int j =0;j<nodes;j++){
        int min_weight =-1;
        int min_parent = -1;
        for(int i =0;i<nodes;i++){
            if(graph[i][j]!=0 && graph[i][j]!=inf){
                if(min_weight>graph[i][j] || min_weight==-1){
                    min_weight=graph[i][j];
                    min_parent = i;    
                }
            }
        }
        result_graph[min_parent][j] = min_weight;
    }

    

    return 0;
}