// Unordered set is based on hashing. 
// Set is self balancing tree (red black)
// Output would be in any order.

/*

insert(), erase(val), erase(it), find(), count() - O(1) on average
begin(), end(), cbegin(), cend(), size(), empty() - O(1)

*/

#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set < int > s;
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    for(int x : s)
        cout << x << " ";

    if(s.find(10) == s.end())
        cout << "\nNot Found";
    else
        cout << "\nFound " << *(s.find(10));

    if(s.count(15))
        cout << "\nFound";
    else
        cout << "\nNot Found";
    
    cout << endl;
    for(auto it = s.begin(); it != s.end(); it++)
        cout << (*it) << " ";
    cout << endl << s.size(); 

    s.erase(15);
    cout << endl << s.size();

    auto it = s.find(10);
    s.erase(it);
    cout << endl << s.size();

    s.clear();
    // s.erase(s.begin(), s.end());
    cout << endl << s.size();
    return 0;
}