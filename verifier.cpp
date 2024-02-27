#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

vector<int> buildGraph(string input, string output, map<int, vector<int> >& g, int& gSize){
    ifstream oin(output);
    ifstream iin(input);
    int outputSize = 0;
    int inputSize = 0;
    iin >> inputSize;
    gSize = inputSize;
    oin >> outputSize;
    vector<int> edited(inputSize, 0);
    int currNode = 0;
    int numEdges = 0;
    int temp = 0;
    for(int i = 0; i < inputSize; i++){
        iin >> numEdges;
        for(int j = 0; j < numEdges; j++){
            iin >> temp;
            g[temp-1].push_back(i+1);
        }
    }
    for(int o = 0; o < outputSize; o++){
        oin >> currNode;
        edited[currNode-1] = 2;
    }
    return edited;
}

void printGraph(map<int, vector<int> >& g){
    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < g[i].size(); j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}

bool dfs(map<int, vector<int> >& g, vector<int>& visited, int start){
    stack<int> s;
    vector<int>* trace = new vector<int>(visited.size(), 0);
    int temp;
    s.push(start);
    trace->at(start-1) = 1;
    while(!s.empty()){
        temp = s.top();
        s.pop();
        visited[temp-1] = 1;
        for(int i = 0; i < g[temp-1].size(); i++){
            if(g[temp-1][i] == start){
                return true;
            }else if(trace->at(g[temp-1][i]-1) == 0 && visited[g[temp-1][i]-1] != 2){
                trace->at(g[temp-1][i]-1) = 1;
                s.push(g[temp-1][i]);
            }
        }
    }
    return false;
}


int main(int argc, char* argv[]){
    map<int, vector<int> >g;
    int gSize;
    vector<int> visited = buildGraph(argv[1], argv[2], g, gSize);
    //printGraph(g);
    for(int i = 0; i < gSize; i++){
        if(visited[i] == 0){
            if(dfs(g, visited, i+1)){
                cout << "invalid solution" << endl;
                return 0;
            }
        }
    }
    cout << "valid solution" << endl;
    return 0;
}