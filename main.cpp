#include "MyHashTable.h"
#include <iostream>


void test(MyHashTable hashTable)
{
    // Test put and get
    hashTable.put("apple", 5);
    hashTable.put("banana", 8);
    hashTable.put("orange", 12);

    // Check if the values can be retrieved correctly
    std::cout << "Value for apple: " << hashTable.get("apple") << std::endl;     // Expected: 5
    std::cout << "Value for banana: " << hashTable.get("banana") << std::endl;   // Expected: 8
    std::cout << "Value for orange: " << hashTable.get("orange") << std::endl;   // Expected: 12

    // Check for a key that doesn't exist
    std::cout << "Value for grape: " << hashTable.get("grape") << std::endl;      // Expected: -1

    // Test rehashing
    for (int i = 0; i < 20; ++i) {
        hashTable.put("key" + std::to_string(i), i * 2);
    }

    // Check if all values can be retrieved correctly after rehashing
    for (int i = 0; i < 20; ++i) {
        std::cout << "Value for key" << i << ": " << hashTable.get("key" + std::to_string(i)) << std::endl;
        // Expected: 0, 2, 4, ..., 38
    }

    // Test isEmpty
    std::cout << "Is hashTable empty? " << (hashTable.isEmpty() ? "Yes" : "No") << std::endl;  // Expected: No
}

int main() {
    // Create an instance of MyHashTable
    MyHashTable hashTable;
/*
    // Insert a large number of key-value pairs to trigger collisions
    for (int i = 0; i < 1000; ++i) {
        hashTable.put("key" + std::to_string(i), i * 2);
    }

    // Check if all values can be retrieved correctly after inserting a large number of elements
    for (int i = 0; i < 1000; ++i) {
        std::cout << "Value for key: " << i << ": " << hashTable.get("key" + std::to_string(i)) << std::endl;
        // Expected: 0, 2, 4, ..., 1998
    }
*/
    test(hashTable);
    return 0;

}
