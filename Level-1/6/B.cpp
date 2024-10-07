#include <iostream>
#include <map>
#include <string>


std::string validateName(std::string name, std::map<std::string, int> &database) {
    if (database.find(name) == database.end()) {
        database.insert({ name, 0 });
        return "OK\n";
    }
    else {
        database[name]++;
        return name + std::to_string(database[name]) + '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n;
    std::cin >> n;
    
    std::map<std::string, int> database;
    while (n--) {
        std::string name;
        std::cin >> name;

        std::cout << validateName(name, database);
    }
}
