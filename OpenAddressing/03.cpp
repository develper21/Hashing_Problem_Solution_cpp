#include <iostream>
#include <vector>
using namespace std;

// Class implementing Hash Table using Linear Probing for collision resolution
class LinearProbing
{
    // Vector to store keys; initialized with -1 indicating empty slots
    vector<int> table;

public:
    // Constructor: initialize the hash table with given size and set all entries to -1
    LinearProbing(int size) : table(size, -1) {}

    // Hash function: simple modulo operation to compute initial index
    int hash(int key)
    {
        return key % table.size();
    }

    // Insert function: insert key into the hash table using linear probing
    void insert(int key)
    {
        // Compute initial index using hash function
        int index = hash(key);

        // If the slot is already occupied, move linearly to next slot
        while (table[index] != -1)
            index = (index + 1) % table.size();

        // Place the key in the first available empty slot
        table[index] = key;
    }

    // Display function: show the contents of the hash table
    void display()
    {
        for (int i = 0; i < table.size(); i++)
            cout << i << " -> " << table[i] << endl;
    }
};

int main()
{
    // Create a hash table of size 7
    LinearProbing lp(7);

    // Insert sample keys into the table
    lp.insert(10);
    lp.insert(3);
    lp.insert(17);

    // Display the current state of the hash table
    lp.display();

    return 0;
}