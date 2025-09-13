// Program to demonstrate perfect hashing.
#include <iostream>
#include <vector>
using namespace std;

class PerfectHashing
{   // Hash table to store keys
    vector<int> table; // Initial value = -1 for empty slots

public:
    PerfectHashing(int size) : table(size, -1) {} // Constructor to initialize hash table
    int hash(int key) { return key % table.size(); } // Simple hash function
    void insert(int key) // Insert key into hash table
    {
        int index = hash(key);
        table[index] = key;
    }
    void display() // Display the hash table
    {
        for (int i = 0; i < table.size(); i++)
            cout << i << " -> " << table[i] << endl;
    }
};

int main()
{
    PerfectHashing ph(7);
    ph.insert(10);
    ph.insert(3);
    ph.insert(17);
    ph.display();
    return 0;
}