#include "Words.h"

void Words() {
    const char* filename = "input.txt";
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return;
    }

    char word[256]; // Предполагаем, что слово не будет длиннее 255 символов
    while (file >> word) {
        size_t length = strlen(word);

        // Удаляем пунктуацию в конце слова, если она есть
        while (length > 0 && ispunct(word[length - 1])) {
            word[length - 1] = '\0';
            length--;
        }

        // Если слово не пустое, проверяем, начинается и заканчивается ли оно на гласные
        if (length > 0 && isVowel(word[0]) && isVowel(word[length - 1])) {
            std::cout << word << std::endl;
        }
    }
    std::cout << "\n\n";
    file.close();
}