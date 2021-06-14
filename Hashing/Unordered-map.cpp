// Used to store key, value pair.
// Map is based on red black tree. Unordered map is based on hashing
// Map stores keys in ordered form. Unordered map stores randomly
// Output will be in any order
// begin(), end(), size(), empty() - O(1) in worst case
// count(), find(), erase(key), insert(), [], at - O(1) on average

#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map <string, int> m;
    m["abc"] = 10; // error when single quotes are used
    m["def"] = 30;
    m.insert({"xyz", 15});
    for(auto x : m) 
        cout << x.first << " " << x.second << endl;

    if(m.find("def") != m.end())
        cout << "\nFound\n";
    else
        cout << "\nNot Found\n";
    for(auto it = m.begin(); it != m.end(); it++)
        cout << (it -> first) << " " << (it -> second) << endl;

    if(m.count("def") > 0) // return type is size_t not boolean
        cout << "\nFound\n"; 
    else
        cout << "\nNot Found\n";

    cout << m.size() << endl;
    m.erase("def");
    m.erase(m.begin());
    // m.erase(m.begin(), m.end());
    cout << m.size() << endl;
    return 0;
}