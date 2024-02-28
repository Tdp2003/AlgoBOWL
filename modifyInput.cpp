#include <fstream>
#include <map>

using namespace std;

void modifyInput(string input, string output){
    ofstream fout("modified.txt");
    ifstream iin(input);
    ifstream oin(output);

    int oSize;
    int iSize;

    iin >> iSize;
    oin >> oSize;

    map<int, bool> toDelete;
    int temp;
    for(int i = 0; i < oSize; i++){
        oin >> temp;
        toDelete[temp] = true;
    }
    fout << iSize;
    int numEdges;
    for(int i = 0; i < iSize; i++){
        if(toDelete[i+1]){
            fout << "0" << endl;
        }else{
            iin >> numEdges;
            for(int n = 0; n < numEdges; n++){
                iin >> temp;
                fout << temp << " ";
            }
            fout << endl;
        }
    }
}

int main(int argc, char* argv[]){
    modifyInput(argv[1], argv[2]);
}