#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <random>

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
            g[temp].push_back(i);
        }
    }
}

int main(int argc, char* argv[]){
    ifstream fin(argv[1]);
    ofstream fout("output.txt");
    int gSize;
    fin >> gSize;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(1, gSize);
    set<int> solution;
    fout << (int)(.75*gSize) << endl;
    int temp;
    for(int i = 0; i < .75*gSize; i++){
        temp = distribution(gen);
        if(solution.find(temp) == solution.end()){
            i--;
        }
        solution.insert(temp);
    }

    for(auto it = solution.begin(); it != solution.end(); ++it){
        fout << *it << " ";
    }

}