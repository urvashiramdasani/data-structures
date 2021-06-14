/* 
1. Hashing takes O(1) time to search, insert and delete elements. Mainly used to implement dictionaries (key, value) pairs and sets.
    It is not useful in 1. Finding closest value 2. sorted data 3. prefix searching
    In first two cases above, we use AVL tree or red black tree. In prefic searching, we use Trie data structure. 
2. Most used data structure in Computer Science.
3. Applications - dictionaries, database indexing (b or b+ trees), cryptography, caches, symbol tables in compilers, routers.
4. Direct address tables do not handle large values, floating point numbers and strings.
 
5. Concept of Hashing - Take a key from the universe of keys, apply the hash function and store them in hash table.
6. Hash function should always map a large key to small key. It should generate values from 0 to m - 1. It should be fast, O(1) for integers
and O(len) for strings. It should uniformly distribute large keys into table slots.
7. If we want to insert n keys in hash table, its size should be proportional to n.
8. For integers, we use modulo hash function (mod m). The value of m should be prime number close to the size to hash table. 
m should be a prime not close to power of 2 and 10. 
9. For strings, we use weighted sum of ascii values and then mod m.
10. Universal Hashing - we take a random hash function from the universal set of hash functions. Inordered set in CPP and Hash set in
Java.

11. Birthday Paradox - If there are 23 people in a room, there is 50% chance that 2 people have same birthday. If number of people is 70,
then the chances increase to 99.99%.
12. Collisions are bound to happen. Perfect Hashing has no collisions (if data is known in advance).
13. Methods of collision handling - Chaining and Open Addressing.

14. Chaining - we maintain an array of linked lists.
    Performance - Let m = number of slots in the hash table, n = number of keys to be inserted. Load factor alpha = n / m.
    Expected chain length = alpha (Assuming keys are uniformly distributed). Expected time to search = O(1 + alpha) (1 for hash
    function computation).
    Expected time to insert/delete = O(1 + alpha)

    Data structure used - 
    1. linked list - search, insert, delete - O(l) not cache friendly
    2. dynamic sized array (vector) - search, insert, delete - O(l) cache friendly
    3. self balancing tree (AVL, red black) - search, insert, delete - O(log(l)) not cache friendly
*/

// Implementation of Chaining

#include <iostream>
#include <list>

using namespace std;

struct MyHash {
    int BUCKET;
    list < int > * table;

    MyHash(int b) {
        BUCKET = b;
        table = new list < int >[b];
    }

    void insert(int key) {
        int i = key % BUCKET;
        table[i].push_back(key);
        cout << key << " inserted at " << i << endl;
    }

    void remove(int key) {
        int i = key % BUCKET;
        table[i].remove(key);
        cout << key << " removed\n";
    }

    bool search(int key) {
        int i = key % BUCKET;
        for(auto x : table[i]) {
            if(x == key) return true;
        }
        return false;
    }
};

int main() {
    struct MyHash m = {7};
    m.insert(70);
    m.insert(71);
    m.insert(56);
    m.insert(9);
    m.remove(56);
    cout << m.search(9);
    return 0;
}