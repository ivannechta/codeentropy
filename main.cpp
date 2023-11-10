#include <cstdlib>
#include <iostream>
#include <string.h>
#include "DBCommands.h"
#include "NdimArray.h"

using namespace std;

int main()
{ DataBase *DB=new DataBase() ;

DB->addCommand("c");
DB->addCommand("a");
DB->addCommand("a");
DB->addCommand("e");
DB->addCommand("e");
DB->addCommand("b");

DB->makeHash();
DB->vivod(DB->Root);

cout << DB->findCMD("e");
delete DB;

 NdimArray *A=new NdimArray(3,1);

    A->add(0);
    A->add(0);
    A->add(1);
    A->add(2);

    cout<<A->CalcEntropy();


system("PAUSE");

    return EXIT_SUCCESS;
}
