#include <iostream>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

class HashTable {
    private:
        static const int m = 30;
        vector<pair<int, string>> table[m];
    public:
        void initHashTable();
        bool isEmpty() const;
        int hashFunction(int key, int i);
        void hashInsertion(int key, string value);
        void removeItem(int key);
        string searchItem(int key);
        void printTable();
};

void HashTable::initHashTable() {
    pair<int, string> nullPair(0, "NULL");

    for (int i=0; i<m; i++) {
        table->push_back(nullPair);
    }

    for (int i=0; i<table->size(); i++) {
        auto pair = table->at(i);
    }
}

bool HashTable::isEmpty() const {
    int sum{};
    for (int i=0; i<m; i++) {
        auto pair = table->at(i);
        sum += pair.first;
    }
    if (sum == 0) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key, int i) {
    return ((key%m) + i*(29-(key%29)))%m;
}

void HashTable::hashInsertion(int key, string value) {
    for (int i=0; i<m; i++) {
        int hashValue = hashFunction(key, i);
        auto& pair = table->at(hashValue);
        if (pair.first == key) {
            pair.second = value;
            break;
        }
        if (pair.first == 0 || pair.first == -1) {
            pair.first = key;
            pair.second = value;
            break;
        }
    }

    return;
}

void HashTable::removeItem(int key) {
    for (int i=0; i<m; i++) {
        int hashValue = hashFunction(key, i);
        auto& pair = table->at(hashValue);
        if (pair.first == key) {
            pair.first = -1;
            pair.second = "deleted";
            break;
        }
        if (pair.first == 0) {
            cout << "key does not exist" << "\n";
            break;
        }
    }

    return;
}

string HashTable::searchItem(int key) {
    for (int i=0; i<m; i++) {
        int hashValue = hashFunction(key, i);
        auto& pair = table->at(hashValue);
        if (pair.first == key) {
            return pair.second;
        }
        if (pair.first == 0) {
            cout << "key does not exist" << "\n";
            break;
        }
    }

    return NULL;
}

void HashTable::printTable() {
    for (int i=0; i<m; i++) {
        auto& pair = table->at(i);
        cout << "[" << i << "](" << pair.first << ", " << pair.second << ") ";
    }

    cout << "\n";

    return;
}

int main() {
    HashTable HT;

    HT.initHashTable();

    if (HT.isEmpty()) {
        cout << "Hash Table is Empty" << "\n";
    }

    HT.hashInsertion(804, "Bruno");
    HT.hashInsertion(752, "Igor");
    HT.hashInsertion(813, "Lena");
    HT.hashInsertion(834, "Adrian");
    HT.hashInsertion(924, "Michal");
    HT.hashInsertion(812, "Stasiu");
    HT.hashInsertion(782, "Kuba");
    HT.hashInsertion(106, "Natalia");

    HT.printTable();
    
    HT.removeItem(924);
    HT.removeItem(106);

    HT.printTable();

    int key = 834;

    cout << "Found " << HT.searchItem(key) << " with key " << key << "\n";

    if (HT.isEmpty()) {
        cout << "Hash Table is empty" << "\n";
    } else {
        cout << "Hash Table is not empty" << "\n";
    }

    return 0;
}