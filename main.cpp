#include <cstdlib>
#include <iostream>
#include <string.h>
#include "DBCommands.h"
#include "NdimArray.h"

using namespace std;
#define FILENAME "/home/user/Temp/Entropy2/a.txt"
int main()
{
    DataBase *DB=new DataBase();

    DB->ReadChains(2, FILENAME);

    cout<<DB->CalcEntropy();

    delete DB;



    system("PAUSE");

    return EXIT_SUCCESS;
}
