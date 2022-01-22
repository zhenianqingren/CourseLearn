#include <iostream>
#include <fstream>

//------
class LinkScreen
{
public:
    LinkScreen *prev;
    LinkScreen *next; //right
    // LinkScreen l;wrong
};
//

int main()
{
    LinkScreen l;
    l.prev = nullptr;
    l.next = nullptr;

    std::ofstream output("D:\\C.txt");
    std::ifstream input("D:\\C.txt");

    output << "abcdefg\n";
    output << "hijklmn\n";

    output.flush();

    char c;
    while (input.get(c))
        std::cout << c;

    input.close();
    output.close();
    getchar();
    return 0;
}