#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class HashTable {
    private:
        static const int m = 10;
        list<pair<int, string>> table[m];
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void hashInsertion(int key, string value);
        void removeItem(int key);
        string searchItem(int key);
        void printTable();
};

bool HashTable::isEmpty() const {
    int sum{};
    for (int i{}; i<m; i++) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}

int HashTable::hashFunction(int key) {
    return key%m;
}

void HashTable::hashInsertion(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExist = false;
    for (;bItr!=end(cell);bItr++) {
        if (bItr->first == key) {
            keyExist = true;
            bItr->second = value;
            cout << "value for " << key << " was swapped for " << value << "\n";
            break;
        }
    }

    if (!keyExist) {
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (;bItr!=end(cell);bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "removed key " << key << "\n";
            break;
        }
    }

    if (!keyExists) {
        cout << "item not found" << "\n";
    }

    return;
}

string HashTable::searchItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (;bItr!=end(cell);bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            return bItr->second;
        }
    }

    if (!keyExists) {
        cout << "item not found" << "\n";
    }

    return NULL;
}

void HashTable::printTable() {
    for (int i; i<m; i++) {
        if (table[i].size() == 0) {
            continue;
        }

        auto bItr = table[i].begin();
        for (; bItr!=table[i].end(); bItr++) {
            cout << "(" << bItr->first << "," << bItr->second << ") ";
        }
    }
    cout << "\n";
    return;
}

int main() {
    HashTable HT;

    if (HT.isEmpty()) {
        cout << "Hash Table is Empty" << "\n";
    }

    HT.hashInsertion(804, "Bruno");
    HT.hashInsertion(752, "Igor");
    HT.hashInsertion(813, "Lena");
    HT.hashInsertion(106, "Adrian");
    HT.hashInsertion(924, "Michal");
    HT.hashInsertion(522, "Stasiu");
    HT.hashInsertion(792, "Kuba");
    HT.hashInsertion(106, "Natalia");

    HT.printTable();
    
    HT.removeItem(924);
    HT.removeItem(792);

    HT.printTable();

    int key = 106;

    cout << "Found " << HT.searchItem(key) << " with key " << key << "\n";

    if (HT.isEmpty()) {
        cout << "Hash Table is empty" << "\n";
    } else {
        cout << "Hash Table is not empty" << "\n";
    }

    return 0;
}