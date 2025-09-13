#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Class implementing Hash Table using Separate Chaining
class SeparateChaining
{
    // Vector of lists to store chains of elements in each bucket
    vector<list<int>> table;

public:
    // Constructor: initialize the hash table with a fixed number of buckets (size)
    SeparateChaining(int size) : table(size) {}

    // Hash function: simple modulo-based hashing
    int hash(int key) 
    {
        return key % table.size();
    }

    // Insert function: insert key into appropriate chain
    void insert(int key) 
    {
        // Compute hash index and insert key at the end of the chain (list)
        table[hash(key)].push_back(key);
    }

    // Display function: show the contents of the hash table
    void display()
    {
        // Iterate through each bucket in the table
        for (int i = 0; i < table.size(); i++)
        {
            cout << i << ": ";
            // Iterate through the chain (list) at this bucket
            for (int k : table[i])
                cout << k << " -> ";
            cout << "NULL\n";  // End of chain representation
        }
    }
};

int main()
{
    // Create a hash table with 7 buckets
    SeparateChaining sc(7);

    // Insert some sample keys into the table
    sc.insert(10);
    sc.insert(3);
    sc.insert(17);

    // Display the current state of the hash table
    sc.display();

    return 0;
}