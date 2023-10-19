#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
void print_mat( vector<vector <int>> mat){
    for(int i = 0;i<mat.size();i++){
        for(int j = 0;j<mat[0].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void print_mat_char( vector<vector <char>> mat){
    for(int i = 0;i<mat.size();i++){
        for(int j = 0;j<mat[0].size();j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void print_lcs(string s,vector<vector <char>> dir,int i, int j){
    if(i==0||j==0){
        return;
    }
    if(dir[i][j]=='D'){
        print_lcs(s,dir,i-1,j-1);
        cout<<s[i-1];
    }
    else if(dir[i][j]=='U'){
        print_lcs(s,dir,i-1,j);
    }
    else{
        print_lcs(s,dir,i,j-1);
    }
}
int main(){
    string s1; 
    cout<<"Enter String 1: ";
    getline(cin,s1);
    string s2;
    cout<<"Enter String 2: ";
    getline(cin,s2);

    vector<vector <int>> mat;
    vector<vector <char>> dir;
    for(int i =0;i<=s1.size();i++){
        vector<int> temp;
        vector<char> temp2;
        for(int j = 0;j<=s2.size();j++){
            temp.push_back(0);
            temp2.push_back('N');
        }
        mat.push_back(temp);
        dir.push_back(temp2);
    }
    
    for(int i = 0;i<=s1.size();i++){
        for(int j = 0;j<=s2.size();j++){
            if(i==0 or j==0){
                continue;
            }
            else if(s1[i-1] == s2[j-1]){
                mat[i][j] = mat[i-1][j-1] +1;
                dir[i][j] = 'D';
            }
            else{
                if(mat[i][j-1]>mat[i-1][j]){
                    mat[i][j] = mat[i][j-1];
                    dir[i][j] = 'L';
                }
                else{
                    mat[i][j] = mat[i-1][j];
                    dir[i][j] = 'U';
                }
            }
        }
    }
    
    print_lcs(s1,dir,mat.size()-1,mat[0].size()-1);
}