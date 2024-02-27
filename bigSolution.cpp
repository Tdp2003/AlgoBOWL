#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
#include <cmath>

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

void strongconnect(int v, int& index, map<int, vector<int> >& g, vector<vector<int> >& cycles, vector<int>& path, vector<bool>& visited, vector<int>& indices, vector<int>& lowlink, stack<int>& s){
    indices[v] = index;
    lowlink[v] = index;
    index++;
    s.push(v);
    visited[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        if(indices[g[v][i]] == -1){
            strongconnect(g[v][i], index, g, cycles, path, visited, indices, lowlink, s);
            lowlink[v] = min(lowlink[v], lowlink[g[v][i]]);
        }else if(visited[g[v][i]]){
            lowlink[v] = min(lowlink[v], indices[g[v][i]]);
        }
    }
    if(lowlink[v] == indices[v]){
        vector<int> cycle;
        while(true){
            int w = s.top();
            s.pop();
            visited[w] = false;
            cycle.push_back(w+1);
            if(w == v){
                break;
            }
        }
        cycles.push_back(cycle);
    }
}

void findCycles(map<int, vector<int> >& g, vector<vector<int> >& cycles, vector<int>& path, vector<bool>& visited, int gSize){
    int index = 0;
    stack<int> s;
    vector<int> indices(gSize, -1);
    vector<int> lowlink(gSize, -1);
    for(int v = 0; v < gSize; v++){
        if(indices[v] == -1){
            strongconnect(v, index, g, cycles, path, visited, indices, lowlink, s);
        }
    }
}

int main(int argc, char* argv[]){
    int gSize;
    map<int, vector<int> > g;
    buildGraph(g,gSize, argv[1]);
    vector< vector<int> > cycles;
    vector<bool> visited(gSize, false);
    vector<int> path;
    findCycles(g, cycles, path, visited, gSize);

    for(int i = 0; i < cycles.size(); i++){
        for(int j = 0; j < cycles[i].size(); j++){
            cout << cycles[i][j] << " ";
        }
        cout << endl;
    }
}