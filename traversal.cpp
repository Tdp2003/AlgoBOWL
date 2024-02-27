#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <set>

using namespace std;

void buildGraph(map<int, vector<int> >& g, int& gSize, string file){
    ifstream fin(file);
    int numEdges = 0;
    int temp = 0;
    fin >> gSize;
    for(int i = 0; i < gSize; i++){
        fin >> numEdges;
        for(int j = 0; j < numEdges; j++){
            fin >> temp;
            g[i].push_back(temp);
        }
    }
}

void printGraph(map<int, vector<int> >& g){
    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < g[i].size(); j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(map<int, vector<int> >& g, set<int>& solution, vector<int>& visited, int gSize, int start){
    stack<int> s;
    int temp;
    s.push(start);
    //int additions = 0;
    while(!s.empty()){
        temp = s.top();
        s.pop();
        visited[temp-1] = 1;
        for(int i = 0; i < g[temp-1].size(); i++){
            if(visited[g[temp-1][i]-1] == 1){
                solution.insert(g[temp-1][i]);
                //additions++;
            }else{
                s.push(g[temp-1][i]);
            }
        }
    }
    //return additions;
}

void createOutput(set<int>& solution){
    ofstream fout ("testOutput.txt");
    fout << solution.size() << endl;
    for(auto it = solution.begin(); it != solution.end(); it++){
        fout << *it << " ";
    }
}

int main(int argc, char* argv[]){
    int gSize;
    map<int, vector<int> > g;
    buildGraph(g,gSize, argv[1]);
    set<int> solution;
    vector<int> visited(gSize, 0);
    for(int i = 0; i < gSize; i++){
        if(visited[i] == 0){
            dfs(g, solution, visited, gSize,i);
        }
    }
    createOutput(solution);
    cout << solution.size() << endl;
}