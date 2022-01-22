#include <iostream>
#include <fstream>
using namespace std;

//ifstream ->read
//ofstream ->write
//fstream ->read and write

int main()
{

    // void open(const char *filename, ios::openmode mode);

    // ios::app	׷��ģʽ������д�붼׷�ӵ��ļ�ĩβ��
    // ios::ate	�ļ��򿪺�λ���ļ�ĩβ��
    // ios::in	���ļ����ڶ�ȡ��
    // ios::out	���ļ�����д�롣
    // ios::trunc ������ļ��Ѿ����ڣ������ݽ��ڴ��ļ�֮ǰ���ضϣ������ļ�������Ϊ 0

    char data[100];

    // ��дģʽ���ļ�
    ofstream outfile;
    outfile.open("D:\\afile.dat");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // ���ļ�д���û����������
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // �ٴ����ļ�д���û����������
    outfile << data << endl;

    // �رմ򿪵��ļ�
    outfile.close();

    // �Զ�ģʽ���ļ�
    ifstream infile;
    infile.open("D:\\afile.dat");

    cout << "Reading from the file" << endl;
    infile >> data;

    // ����Ļ��д������
    cout << data << endl;

    // �ٴδ��ļ���ȡ���ݣ�����ʾ��
    infile >> data;
    cout << data << endl;

    // �رմ򿪵��ļ�
    infile.close();


// ��λ�� fileObject �ĵ� n ���ֽڣ������� ios::beg��
// fileObject.seekg( n );
 
// ���ļ��Ķ�ָ��� fileObject ��ǰλ������� n ���ֽ�
// fileObject.seekg( n, ios::cur );
 
// ���ļ��Ķ�ָ��� fileObject ĩβ������ n ���ֽ�
// fileObject.seekg( n, ios::end );
 
// ��λ�� fileObject ��ĩβ
// fileObject.seekg( 0, ios::end );


    getchar();
    return 0;
}