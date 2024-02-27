#include <iostream>
#include <fstream>
#include <map>
#include <vector>

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

void findCycles(map<int, vector<int> >& g, vector<vector<int> >& cycles, vector<int>& path, vector<bool>& visited, int curr){
    visited.at(curr) = true;
    path.push_back(curr);

    for(int i = 0 ; i < g[curr].size(); i++){
    
    }

    path.pop_back();
    visited.at(curr) = false;
}

int main(int argc, char* argv[]){
    int gSize;
    map<int, vector<int> > g;
    buildGraph(g,gSize, argv[1]);
    vector< vector<int> > cycles;
    vector<bool> visited(gSize, false);
    vector<int> path;
    for(int i = 0; i < gSize; i++){
        if(!visited.at(i)){
            findCycles(g, cycles, path, visited, i);
        }
    }

    for(int i = 0; i < cycles.size(); i++){
        for(int j = 0; j < cycles[i].size(); j++){
            cout << cycles[i][j];
        }
        cout << endl;
    }
    
}