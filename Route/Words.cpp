#include "Words.h"

void Words() {
    const char* filename = "input.txt";
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "�� ������� ������� ���� " << filename << std::endl;
        return;
    }

    char word[256]; // ������������, ��� ����� �� ����� ������� 255 ��������
    while (file >> word) {
        size_t length = strlen(word);

        // ������� ���������� � ����� �����, ���� ��� ����
        while (length > 0 && ispunct(word[length - 1])) {
            word[length - 1] = '\0';
            length--;
        }

        // ���� ����� �� ������, ���������, ���������� � ������������� �� ��� �� �������
        if (length > 0 && isVowel(word[0]) && isVowel(word[length - 1])) {
            std::cout << word << std::endl;
        }
    }
    std::cout << "\n\n";
    file.close();
}