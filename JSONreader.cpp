#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

/*
This code reads strings from a file named "final.txt", processes them by removing certain characters, 
and then counts the frequency of each processed string. The frequency information is stored in an 
unordered_map, and the final key-value pairs are written to a file named "final.csv".
*/

// Declaration of the exports function
vector <string> exports (void);


int main() {
    // Call the exports function to get a vector of strings
    vector<string> strings_to_be_mapped = exports();

    // Create an unordered_map to store the frequency of each string
    unordered_map <string, int> map_of_string_frequency; 
    unordered_map <string, int>::iterator iterator;

    // Loop through the vector of strings and update the frequency in the map
    for (int i = 0; i < strings_to_be_mapped.size(); i++) {
        if (map_of_string_frequency.find(strings_to_be_mapped[i]) == map_of_string_frequency.end()) { // Check if the key is not present
            map_of_string_frequency.insert(pair<string, int> (strings_to_be_mapped[i], 1)); // Insert the key with frequency 1
        } else {
            map_of_string_frequency[strings_to_be_mapped[i]]++; // Increment the frequency for existing keys
        }
    }

    // Open a file named "final.csv" for writing
    ofstream myfile;
    myfile.open ("final.csv");

    // Loop through the map and write key-value pairs to the file
    for (auto const &pair: map_of_string_frequency) {
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

    // Read lines from the file and process them
    while(myfile>>line) {
        // Check if the line contains the specified pattern
        if (line.compare("\"name\":") == 0){
            myfile>>line;
            final.push_back(line);

            // Remove unwanted characters from the string
            final[index].erase(remove( final[index].begin(), final[index].end(), '\"' ),final[index].end());
            final[index].erase(remove( final[index].begin(), final[index].end(), ',' ),final[index].end());
            final[index].erase(remove( final[index].begin(), final[index].end(), '.' ),final[index].end());
            final[index].erase(remove( final[index].begin(), final[index].end(), ':' ),final[index].end());
            
            // Increment index for the next element
            index++;
        }
    }

    // Return the vector of processed strings
    return final;
}
