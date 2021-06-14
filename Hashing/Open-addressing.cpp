// Open addressing - number of slots in hash table >= number of keys to be inserted. Cache friendly
// Methods of open addressing - 1. Linear probing 2. Quadratic probing 3. Double hashing
// Linear probing - linearly search for the next empty slot when there is a collision. If we map to last slot and it is occupied, then we
// search in circular manner.
// Search: We compute hash function. We go to the index and compare. If we find we return true. Else we linearly search. Stop when we get
// an empty slot, when we return to the same index or when we find the key.
// Problem with simply making slot empty when we delete: search stops even if the element is present and returns false. 
// Solution: Mark the slot 'deleted' and not empty
// Problem with linear probing - clustering - makes every operation costly

/*
h(key) = key % m, linear probing - hash(key, i) = (h(key) + i) % m     ---->>> primary clusters
quadratic probing - hash(key, i) = (h(key) + i ^ 2) % m     --->> clustering still exists (secondary clusters), it might not find an 
                                                                    empty slot even if it is still there. If alpha < 0.5 and m is prime,
                                                                    empty slot is guaranteed.
double hashing - hash(key, i) = (h1(key) + i * h2(key)) % m --> h2 should never be 0.
Here, if m is relatively prime to h2, then it always finds a free slot. No clustering, distributes key more uniformly than linear 
and quadratic

Performance analysis of search - Assumption - every probe sequence looks at a random location. (1 - alpha) slots of the table are empty
Expected number of probes required = 1 / (1 - alpha)
*/

// Implementation of double hashing
#include <iostream>

using namespace std;

struct MyHash {
    int *arr, cap, size;

    MyHash(int c) {
        cap = c;
        size = 0;
        arr = new int[cap];
        for(int i = 0; i < cap; i++) arr[i] = -1;
    }

    int hash(int key) {
        return key % cap;
    }

    bool search(int key) {
        int h = hash(key);
        int i = h;
        while(arr[i] != -1) {
            if(arr[i] == key) return true;
            i = (i + 1) % cap;
            if(i == h) return false;
        }
        return false;
    }

    bool insert(int key) {
        if(size == cap) return false;
        int i = hash(key);
        while(arr[i] != -1 && arr[i] != -2 && arr[i] != key) i = (i + 1) % cap;
        if(arr[i] == key) return false;
        else {
            arr[i] = key;
            size++;
            return true;
        }
    }

    bool erase(int key) {
        int h = hash(key);
        int i = h;
        while(arr[i] != -1) {
            if(arr[i] == key) {
                arr[i] = -2;
                return true;
            }
            i = (i + 1) %cap;
            if(i == h)
                return false;
        }
        return false;
    }
};

int main() {
    struct MyHash m = {7};
    cout << m.insert(70);
    cout << m.insert(71);
    cout << m.insert(56);
    cout << m.insert(9);
    cout << m.erase(56);
    cout << m.search(9);
    return 0;
}

/*

Chaining - 
1. Hash table never fills   2. Less sensitive to hash functions   3. Poor cache performance   4. Extra space for links

Open addressing -
1. Table may become full and ranging becomes mandatory   2. Extra care required for clustering   3. Cache friendly   
4. Extra space may be required to perform same performance as chaining

*/