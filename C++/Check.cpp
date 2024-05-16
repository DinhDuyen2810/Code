#include <iostream>
#include <string>

int main() {
    std::string str = "3.14";
    double number = std::stod(str);
    
    std::cout << "Chuoi: " << str << std::endl;
    std::cout << "So thuc: " << number << std::endl;

    return 0;
}