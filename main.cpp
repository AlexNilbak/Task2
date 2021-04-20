#include "Fabric.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

class Fabric;
class FabricHori;
class FabricVert;

int main() {
    try {
        AutoTest();

        ifstream input("data.txt");
        if (!input.is_open()) {
            cout << "Cannot open the file" << endl;
            return 1;
        }
        string sf;
        string st;
        int m;
        double d;
        int n = 0;
        while (!input.eof()){
            getline(input,sf);
            n++;
        }
        input.seekg(0, ios_base::beg);
        
        vector <Vector*> arr(n);
        map<string, Fabric*> factory;
        factory["Hori"] = new FabricHori;
        factory["Vert"] = new FabricVert;
        for (auto i = arr.begin(); i !=arr.end(); ++i) {
            input >> st;
            *i = create(st, factory);
            input >> sf;
            (*i)->SetFileName(st);
            input >> m;
            (*i)->Setn(m);
            for (int j = 0; j < m; ++j) {
                input >> d;
                (*(*i))[j] = d;
            }
        }
        for (auto i = arr.begin(); i != arr.end(); ++i) {
            (*i)->output((*i)->GetFileName());
        }
        input.close();
        for (auto i = arr.begin(); i != arr.end(); ++i) {
            delete (*i);
        }
        return 0;
    }
    catch (int err) { 
        printf("error=%d\n", err); 
    }
}
