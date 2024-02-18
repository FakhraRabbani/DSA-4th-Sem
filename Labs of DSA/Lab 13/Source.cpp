#include "iostream"
#include "string"

using namespace std;

class HashTable
{
private:
    string* table;
    int size;
    int curSize;
public:
    HashTable(int size) : size(size), curSize(0)
    {
        table = new std::string[size];
        for (int i = 0; i < size; ++i) {
            table[i] = "EMPTY";
        }
    }

    ~HashTable()
    {
        delete[] table;
    }

    bool isEmpty()
    {
        return curSize == 0;
    }

    bool isFull()
    {
        return curSize == size;
    }

    double loadFactor()
    {
        return static_cast<double>(curSize) / size;
    }

    bool insert(const string& name)
    {
        int index = value(name) % size;
        int originalIndex = index;

        while (table[index] != "EMPTY")
        {
            index = (index + 1) % size;

            // If we have checked all indices and haven't found an empty slot, return false
            if (index == originalIndex)
            {
                return false;
            }
        }

        table[index] = name;
        curSize++;
        return true;
    }

    bool search(const string& name)
    {
        int index = value(name) % size;
        int originalIndex = index;

        while (table[index] != "EMPTY" && table[index] != name)
        {
            index = (index + 1) % size;

            // If we have checked all indices and haven't found the name, return false
            if (index == originalIndex)
            {
                return false;
            }
        }

        return table[index] == name;
    }

    bool remove(const std::string& name)
    {
        int index = value(name) % size;
        int originalIndex = index;

        while (table[index] != "EMPTY" && table[index] != name)
        {
            index = (index + 1) % size;

            // If we have checked all indices and haven't found the name, return false
            if (index == originalIndex)
            {
                return false;
            }
        }

        if (table[index] == name)
        {
            table[index] = "EMPTY";
            curSize--;
            return true;
        }

        return false;
    }

    void display()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << "Index " << i << ": " << (table[i] == "EMPTY" ? "EMPTY" : table[i]) << endl;
        }
    }

    int value(const string& name)
    {
        int temp = 0;
        for (int i = 0; i < name.length(); i++)
        {
            temp = temp + name[i];
        }
        return temp;
    }
};


void menu()
{
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;

    HashTable hashTable(size);

    while (true)
    {
        cout << "\n1. Insert a name\n"
            "2. Search for a name\n"
            "3. Remove a name\n"
            "4. Display the table\n"
            "5. Display the load factor of the table\n"
            "6. Exit\n"
            "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name;
            cout << "Enter a name to insert: ";
            cin >> name;

            if (hashTable.insert(name))
            {
                cout << "Name inserted successfully!\n";
            }
            else
            {
                cout << "Table is full. Name insertion failed.\n";
            }
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter a name to search: ";
            cin >> name;

            if (hashTable.search(name))
            {
                cout << "Name found in the table.\n";
            }
            else
            {
                cout << "Name not found in the table.\n";
            }
            break;
        }
        case 3:
        {
            string name;
            cout << "Enter a name to remove: ";
            cin >> name;

            if (hashTable.remove(name))
            {
                cout << "Name removed successfully!\n";
            }
            else
            {
                cout << "Name not found in the table. Removal failed.\n";
            }
            break;
        }
        case 4:
            cout << "Displaying the table:\n";
            hashTable.display();
            break;
        case 5:
            cout << "Load factor of the table: " << hashTable.loadFactor() << endl;
            break;
        case 6:
            cout << "Exiting...\n";
            return;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}


int main()
{
    menu();
    return 0;
}