#include <fstream>
#include <map>
#include <random>
#include <set>
#include <iostream>

using namespace std;

void generateEdges(map<int, set<int> >& edges, int curr, int max, int min, int& total){
    random_device rd;
    mt19937 gen(rd());
    int temp;
    uniform_int_distribution<> distribution(min, max);
    if(curr != 4999){
        edges[curr].insert(curr+1);
        total++;
    }
    if(curr != 0){
        edges[curr].insert(curr - 1);
        total++;
    }
    while(edges[curr].size() < 21){
            edges[curr].insert(distribution(gen));
    }
}

void toFile(map<int, set<int> >& edges){
    ofstream fout ("input2.txt");
    fout << 5000 << endl;
    for(int i = 0; i < 4999; i++){
        fout << edges[i].size();
        for(auto it = edges[i].begin(); it != edges[i].end(); ++it){
            
        }
    }
}

int main(){
    map<int, set<int> > edges;
    int size = 5000;
    int total = 2;
    edges[0].insert(4999);
    edges[4999].insert(0);
    for(int i = 0; i < 1000; i++){
        generateEdges(edges, i, 999, 0, total);
    }
    for(int i = 1000; i < 2000; i++){
        generateEdges(edges, i, 1999, 1000, total);
    }
    for(int i = 2000; i < 3000; i++){
        generateEdges(edges, i, 2999, 2000, total);
    }
    for(int i = 3000; i < 4000; i++){
        generateEdges(edges, i, 3999, 3000, total);
    }
    for(int i = 4000; i < 5000; i++){
        generateEdges(edges, i, 4999, 4000, total);
    }

    toFile(edges);
    
    return 0;
}