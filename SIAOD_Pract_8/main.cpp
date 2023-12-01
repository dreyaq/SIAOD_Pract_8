#include <iostream>
#include <string>
using namespace std;
string compressRLE(const string& input) {
    string compressed;
    int count = 1;

    for (int i = 0; i < input.length(); ++i) {
        if (i + 1 < input.length() && input[i] == input[i + 1]) {
            count++;
        }
        else {
            compressed += to_string(count) + input[i];
            count = 1;
        }
    }

    return compressed;
}

int main() {
    // Пример с длинными сериями
    string text1 = "AAAABBBCCDAA";
    string compressed1 = compressRLE(text1);
    double compressionRatio1 = static_cast<double>(text1.length()) / compressed1.length();

    cout << "Original Text 1: " << text1 << endl;
    cout << "Compressed Text 1: " << compressed1 << endl;
    cout << "Compression Ratio 1: " << compressionRatio1 << endl;

    // Пример с неповторяющимися символами и разделением
    string text2 = "ABCDEFABCDE";
    string compressed2 = compressRLE(text2);
    double compressionRatio2 = static_cast<double>(text2.length()) / compressed2.length();

    cout << "Original Text 2: " << text2 << endl;
    cout << "Compressed Text 2: " << compressed2 << endl;
    cout << "Compression Ratio 2 (without splitting): " << compressionRatio2 << endl;

    // Применение алгоритма разделения
    string groupedCompressed2;
    int groupSize = 3;

    for (int i = 0; i < text2.length(); i += groupSize) {
        string group = text2.substr(i, groupSize);
        groupedCompressed2 += compressRLE(group);
    }

    double groupedCompressionRatio2 = static_cast<double>(text2.length()) / groupedCompressed2.length();

    cout << "Compressed Text 2 (with splitting): " << groupedCompressed2 << endl;
    cout << "Compression Ratio 2 (with splitting): " << groupedCompressionRatio2 << endl;

    return 0;
}
