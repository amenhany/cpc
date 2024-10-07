#include <iostream>
#include <map>


//map of dictionary, input each word from the description until a period is input
//find each word in the map and add its value to a sum which is output after each description
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int dictionaryLength, descriptionNumber;
    std::cin >> dictionaryLength >> descriptionNumber;

    std::map<std::string, int> dictionary;
    for (int i = 0; i < dictionaryLength; i++) {
        std::string word;
        int dollars;
        std::cin >> word >> dollars;
        dictionary.insert({word, dollars});
    }

    for (int i = 0; i < descriptionNumber; i++) {
        std::string word;
        int sum = 0;
        while (word != ".") {
            if (dictionary.find(word) != dictionary.end())
                sum += dictionary[word];
            std::cin >> word;
        }
        std::cout << sum << '\n';
    }
}