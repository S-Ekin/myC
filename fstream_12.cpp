#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <direct.h>
#include "stdlib.h"

using namespace std;

void readTxt(string file)
{
    cout << file.data() << endl; 
    ifstream infile; 
    infile.open(file);   //将文件流对象与文件连接起来 
    if(!infile){
        cerr << "打开错误" << endl;
        return;
    }   //若失败,则输出错误消息,并终止程序运行 
    string s;
    while(infile >> s)
    {
        cout<<s;
    }
        cout<<s<<endl;
    
    infile.close();             //关闭文件输入流 
}
int main (int argc, char **argv){	
    cout << argv[0] << endl;
    SetConsoleOutputCP(65001);
    char * buffer;
    buffer = getcwd(NULL, 0);
    cout << buffer << endl;
    cout << _pgmptr << endl;
    readTxt("E:\\c++\\myC\\ts.txt");
	return 0;
}