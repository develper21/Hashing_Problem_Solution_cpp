#include <iostream>
#include <vector>
using namespace std;

// Class implementing Hash Table using Double Hashing for collision resolution
class DoubleHashing
{
    // Vector to store keys; initialized with -1 to represent empty slots
    vector<int> table;

public:
    // Constructor: initialize the hash table with specified size and fill all slots with -1
    DoubleHashing(int size) : table(size, -1) {}

    // First hash function: simple modulo operation to compute initial index
    int hash1(int key)
    {
        return key % table.size();
    }

    // Second hash function: used for probing step size in case of collision
    int hash2(int key)
    {
        return 7 - (key % 7);  // Common technique to avoid clustering
    }

    // Insert function: insert key using double hashing to resolve collisions
    void insert(int key)
    {
        int index = hash1(key);  // Initial index
        int i = 0;               // Probe counter

        // Loop until an empty slot is found
        // Probing formula: (hash1(key) + i * hash2(key)) % table size
        while (table[(index + i * hash2(key)) % table.size()] != -1)
            i++;

        // Place the key in the found empty slot
        table[(index + i * hash2(key)) % table.size()] = key;
    }

    // Display function: show the current state of the hash table
    void display()
    {
        for (int i = 0; i < table.size(); i++)
            cout << i << " -> " << table[i] << endl;
    }
};

int main()
{
    // Create a hash table of size 7
    DoubleHashing dh(7);

    // Insert sample keys into the table
    dh.insert(10);
    dh.insert(3);
    dh.insert(17);

    // Display the final state of the hash table
    dh.display();

    return 0;
}