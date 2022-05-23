#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

bool output_cmp(std::ostream& _out, std::istream& _in1, std::istream& _in2) {
    if (_in1.eof() || _in1.fail() || _in2.eof() || _in2.fail())
        return false;

    bool ok = true;
    unsigned int row = 1;
    std::string a, b;
    do {
        std::getline(_in1, a);
        std::getline(_in2, b);
        if (a != b) {
            _out << "line: " << row << std::endl;
            _out << a << std::endl;
            _out << b << std::endl << std::endl;
            ok = false;
            break;
        }
        ++row;
    } while (!_in1.eof() || !_in2.eof());
    return ok;
}

int main(void) {
    //для примера сравнение двух строк
    char s1[] = "APL\nALGOL\nC/C++\nPASCAM";
    char s2[] = "APL\nALGOL\nC/C++\nHACTOR";
    std::istringstream sp1(s1), sp2(s2);
    if (output_cmp(std::cout, sp1, sp2))
        std::cout << "Yes cmp." << std::endl;

    //сравнение файлов
    std::ifstream fp1("file1.txt");
    std::ifstream fp2("file2.txt");
    if (output_cmp(std::cout, fp1, fp2))
        std::cout << "Yes cmp." << std::endl;
    fp1.close();
    fp2.close();
    std::cin.get();
    return 0;
}