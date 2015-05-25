// Nicolas Jones
// 861169228
// 5/24/15

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

vector<string> read_into_vector(string filename)
{
    vector<string> v(50000);
    ifstream fin;
    fin.open(filename.c_str());
    
    if(!fin.is_open()) // if file doesn't open
    {
        cout << "Error opening " << filename << endl;
        exit(0);
    }
    
    while(!fin.eof())
    {
        for (int i = 0; i < 50000; ++i)
        {
            fin >> v.at(i); // read words into vector
        }
    }
    
    fin.close();
    
    return v;
}

unordered_set<string> fill_hash(vector<string> words, int n)
{
    unordered_set<string> hash;
    
    for (int i = 0; i < n; ++i)
    {
        hash.insert(words.at(i));
    }
    
    return hash;
}

set<string> fill_sbt(vector<string> words, int n)
{
    set<string> sbt;
    
    for (int i = 0; i < n; ++i)
    {
        sbt.insert(words.at(i));
    }
    
    return sbt;
}

int main()
{
    vector<string> words;
    words = read_into_vector("words.txt");
    
    int n = 5000;
    
    unordered_set<string> hash; // hash table
    hash = fill_hash(words, n);
    
    set<string> sbt; // sbt = self-balancing tree
    sbt = fill_sbt(words, n);
    
    return 0;
}
