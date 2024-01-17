#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string,int> m;

    // INSERTION

    pair<string,int> p = make_pair("Okay",2);
    m.insert(p);

    pair<string,int> p1("Hmm",3);
    m.insert(p1);

    m["aacha"] = 9;

    m.insert(make_pair("ohh",8)); 
    m["aacha"] = 0;// updates the value

    // Search
    cout << m["Okay"] << endl;
    cout << m["Hmm"] << endl;
    cout << m["aacha"] << endl;
    cout << m["ohh"] << endl;

    // cout << m.at("unknown") << endl; 
    // will give error as no such key exists -> 'std::out_of_range'

    cout << m["unknown"] << endl; //creates <"unknown",0>
    cout << m.at("unknown") << endl << endl; 
    
    cout << "Size: " << m.size() << endl;

    cout << "Is Okay Present?: " << m.count("Okay") << endl; // Case Sensitive

    // Traversing the map
    cout << "Map key-pair values: " << endl;
    for(auto i:m)
    {
        cout << i.first << " -> " << i.second << endl;
    }
    cout << endl;

    // Using iterator

    m.erase("unknown");
    cout << "New Size: " << m.size() << endl;
}