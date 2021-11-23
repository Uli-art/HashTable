// HashTable.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>


class HashTable{
private:
    int TableSize;
    std::vector<std::vector<std::pair<std::string, int> > > Values;

    int HashKeys(std::string key) {
        int HashKey = 0;

        for (int i = 0; i < key.size(); i++) 
            HashKey = (HashKey + key[i] - 'a' + 1) % TableSize;
        return HashKey;
    }
public:
    HashTable(int TableSize) {
        this->TableSize = TableSize;
        Values.resize(TableSize);
    }

    void add(std::string key, int value) {
        int HashKey = HashKeys(key);

        for (int i = 0; i < Values[HashKey].size(); i++) {
            if (Values[HashKey][i].first == key) 
                Values[HashKey][i].second = value;
        }
        Values[HashKey].push_back( make_pair(key, value));
    }

    int GetValue(std::string key) {
        int HashKey = HashKeys(key);

        for (int i = 0; i < Values[HashKey].size(); i++) {
            if (Values[HashKey][i].first == key)
                return Values[HashKey][i].second;
        }
        return -1;
    }
};
   
int main()
{
    HashTable table(100);

    table.add("key", 57);
    std::cout << table.GetValue("key") << std::endl;


    table.add("key", 37);
    std::cout << table.GetValue("key") << std::endl;

    std::cout << table.GetValue("ndndffn") << std::endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
