#include <iostream>
#include <vector>
using namespace std;

// Class implementing Hash Table using Quadratic Probing for collision resolution
class QuadraticProbing
{
    // Vector to store keys; initialized with -1 to represent empty slots
    vector<int> table;

public:
    // Constructor: initialize the hash table with specified size and set all slots to -1
    QuadraticProbing(int size) : table(size, -1) {}

    // Hash function: simple modulo operation to get initial index
    int hash(int key)
    {
        return key % table.size();
    }

    // Insert function: insert key using quadratic probing to resolve collisions
    void insert(int key)
    {
        int index = hash(key);  // Calculate initial index
        int i = 0;              // Probe counter

        // Loop until an empty slot is found
        // Use quadratic probing formula: (index + i^2) % table size
        while (table[(index + i * i) % table.size()] != -1)
            i++;

        // Place the key in the found slot
        table[(index + i * i) % table.size()] = key;
    }

    // Display function: output the hash table contents
    void display()
    {
        for (int i = 0; i < table.size(); i++)
            cout << i << " -> " << table[i] << endl;
    }
};

int main()
{
    // Create a hash table of size 7
    QuadraticProbing qp(7);

    // Insert sample keys into the table
    qp.insert(10);
    qp.insert(3);
    qp.insert(17);

    // Display the current state of the hash table
    qp.display();

    return 0;
}