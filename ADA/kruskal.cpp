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

    vector <int> w;
    vector <int> start;
    vector <int> end;

    for(int i =0;i<nodes;i++){
        for(int j =0;j<nodes;j++){
            if(graph[i][j]!=inf && graph[i][j]!=0){
                w.push_back(graph[
                    i][j]);
                start.push_back(i);
                end.push_back(j);
            }
        }
    }

    for(int i=0;i<w.size();i++){
        for(int j=0;j<w.size()-i-1;j++){
            if(w[j]>w[j+1]){
                int temp = w[j];
                w[j] = w[j+1];
                w[j+1] = temp;

                temp = end[j];
                end[j] = end[j+1];
                end[j+1] = temp;

                temp = start[j];
                start[j] = start[j+1];
                start[j+1] = temp;
            }
        }
    }

    vector<int> nodes_covered;
    nodes_covered.push_back(0);
    for(int i = 0;i<w.size();i++){
        if(node_in(nodes_covered,end[i])==0){
            nodes_covered.push_back(end[i]);
            cout<<start[i]<<"--"<<w[i]<<"-->"<<end[i]<<endl;
        }
    }
    return 0;
}