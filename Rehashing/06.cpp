#include <iostream>
#include <vector>
using namespace std;

// Class implementing Hash Table with Rehashing mechanism when load factor exceeds threshold
class Rehashing
{
    vector<int> table;  // Vector to store keys; -1 indicates empty slots
    int count;          // Keeps track of number of inserted elements

public:
    // Constructor: initializes the table with given size and count as 0
    Rehashing(int size) : table(size, -1), count(0) {}

    // Simple hash function using modulo operation
    int hash(int key)
    {
        return key % table.size();
    }

    // Insert function: inserts key and triggers rehash if load factor exceeds 0.5
    void insert(int key)
    {
        // Rehash when the table is more than half full
        if (count >= table.size() / 2)
            rehash();

        int index = hash(key);

        // Linear probing in case of collision
        while (table[index] != -1)
            index = (index + 1) % table.size();

        // Insert the key into the empty slot
        table[index] = key;
        count++;
    }

    // Rehash function: doubles the table size and reinserts existing elements
    void rehash()
    {
        vector<int> oldTable = table;             // Backup old table
        table = vector<int>(table.size() * 2, -1);  // Double the size, initialize with -1
        count = 0;

        // Reinsert all non-empty elements from old table into new table
        for (int k : oldTable)
            if (k != -1)
                insert(k);
    }

    // Display function: shows the current state of the hash table
    void display()
    {
        for (int i = 0; i < table.size(); i++)
            cout << i << " -> " << table[i] << endl;
    }
};

int main()
{
    // Create a hash table with initial size 3
    Rehashing rh(3);

    // Insert keys into the table
    rh.insert(10);
    rh.insert(3);
    rh.insert(17);
    rh.insert(24);  // This insert triggers rehash due to load factor > 0.5

    // Display the final state of the hash table after rehashing
    rh.display();

    return 0;
}