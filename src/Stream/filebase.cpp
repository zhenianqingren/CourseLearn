#include <iostream>
#include <fstream>
using namespace std;

//ifstream ->read
//ofstream ->write
//fstream ->read and write

int main()
{

    // void open(const char *filename, ios::openmode mode);

    // ios::app	追加模式。所有写入都追加到文件末尾。
    // ios::ate	文件打开后定位到文件末尾。
    // ios::in	打开文件用于读取。
    // ios::out	打开文件用于写入。
    // ios::trunc 如果该文件已经存在，其内容将在打开文件之前被截断，即把文件长度设为 0

    char data[100];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("D:\\afile.dat");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // 向文件写入用户输入的数据
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // 再次向文件写入用户输入的数据
    outfile << data << endl;

    // 关闭打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream infile;
    infile.open("D:\\afile.dat");

    cout << "Reading from the file" << endl;
    infile >> data;

    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;

    // 关闭打开的文件
    infile.close();


// 定位到 fileObject 的第 n 个字节（假设是 ios::beg）
// fileObject.seekg( n );
 
// 把文件的读指针从 fileObject 当前位置向后移 n 个字节
// fileObject.seekg( n, ios::cur );
 
// 把文件的读指针从 fileObject 末尾往回移 n 个字节
// fileObject.seekg( n, ios::end );
 
// 定位到 fileObject 的末尾
// fileObject.seekg( 0, ios::end );


    getchar();
    return 0;
}