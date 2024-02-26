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
    uniform_int_distribution<> dist(10,20);
    if(curr != 5000){
        temp = curr + 2;
        edges[curr].insert(temp);
    }
    if(curr != 1){
        temp = curr;
        edges[curr].insert(temp);
    }
    int maxSize = dist(gen);
    total += maxSize;
    while(edges[curr].size() < maxSize){
        temp = distribution(gen);
        if(temp != curr + 1){
            edges[curr].insert(temp);
        }
    }
}

void toFile(map<int, set<int> >& edges){
    ofstream fout ("input2.txt");
    fout << 5000 << endl;
    for(int i = 0; i < 4999; i++){
        fout << edges[i].size();
        for(auto it = edges[i].begin(); it != edges[i].end(); ++it){
            fout << " " << *it;
        }
        fout << endl;
    }
    fout << edges[5000].size();
    for(auto it = edges[5000].begin(); it != edges[5000].end(); it++){
        fout << " " << *it;
    }
}

int main(){
    map<int, set<int> > edges;
    int size = 5000;
    int total = 2;
    edges[1].insert(5000);
    edges[5000].insert(1);
    for(int i = 1; i < 1001; i++){
        generateEdges(edges, i, 1000, 1, total);
    }
    for(int i = 1001; i < 2001; i++){
        generateEdges(edges, i, 2000, 1001, total);
    }
    for(int i = 2001; i < 3001; i++){
        generateEdges(edges, i, 3000, 2001, total);
    }
    for(int i = 3001; i < 4001; i++){
        generateEdges(edges, i, 4000, 3001, total);
    }
    for(int i = 4001; i < 5001; i++){
        generateEdges(edges, i, 5000, 4001, total);
    }

    toFile(edges);
    cout << total << endl;
    
    return 0;
}