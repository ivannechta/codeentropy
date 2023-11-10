#include <cstdlib>
#include <iostream>
#include <string.h>
#include "DBCommands.h"
#include "NdimArray.h"


#define FILENAME "e:\\temp\\Entropy2\\commands_from_exe.txt"

using namespace std;
int main()
{
    DataBase *DB;
    for (int i=1;i<=12;i++){
        DB=new DataBase();
        DB->ReadChains(i, (char *)FILENAME);
        printf("Memory=%d, %.3f\n",i,DB->CalcEntropy());
        delete DB;
    }


    return EXIT_SUCCESS;
}
