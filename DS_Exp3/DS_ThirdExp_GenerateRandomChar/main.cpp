#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/**C5 LVV*/

int main()
{
    srand(time(0));
    ofstream outfile("text.txt",ios::out);
    for(int i=0;i<4096;i++) //4096: 文本长度
    {
        char c=(rand()%('l'-'a'+1))+'a';  //a/l: 生成范围
        outfile<<c;
    }
    return 0;
}
