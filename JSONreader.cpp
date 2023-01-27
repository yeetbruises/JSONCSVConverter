#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

vector <string> exports (void);


int main() {
    vector<string> fisnal = exports();
    unordered_map <string, int> theMap; 
    unordered_map <string, int>::iterator it;

    for (int i = 0; i < fisnal.size(); i++) {
        if (theMap.find(fisnal[i]) == theMap.end()) { // if key non existant
            theMap.insert(pair<string, int> (fisnal[i], 1)); // insert
        } else {
            theMap[fisnal[i]]++;
        }
    }

    ofstream myfile;
    myfile.open ("final.csv");
    for (auto const &pair: theMap) {
        myfile << pair.first << "," << pair.second << "\n";
    }

    return 0;
}

vector <string> exports() {
    string line;
    ifstream myfile;
    vector<string> final;
    myfile.open("final.txt");
    int index = 0;

    while(myfile>>line) {
        if (line.compare("\"name\":") == 0){
            myfile>>line;
            final.push_back(line);
            final[index].erase(remove( final[index].begin(), final[index].end(), '\"' ),final[index].end());
            final[index].erase(remove( final[index].begin(), final[index].end(), ',' ),final[index].end());
            final[index].erase(remove( final[index].begin(), final[index].end(), '.' ),final[index].end());
            final[index].erase(remove( final[index].begin(), final[index].end(), ':' ),final[index].end());
            //cout << final[index] << endl;
            index++;
        }
    }

    return final;
}