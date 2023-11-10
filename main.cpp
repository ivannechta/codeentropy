#include <cstdlib>
#include <iostream>
#include <string.h>
#include "DBCommands.h"
#include "NdimArray.h"

using namespace std;
#define FILENAME "/home/user/Temp/Entropy2/a.txt"
int main()
{ DataBase *DB=new DataBase();

DB->Load(FILENAME);
DB->vivod(DB->Root);

 NdimArray *A=new NdimArray(10,2);
 DB->ReadChains(A,FILENAME);

 for (int i=0;i<10;i++){
    for (int j=0;j<10;j++){
            cout<<A->get(i*10+j)<<" ";
    }
    cout<<"\n";
 }

delete DB;


cout<<A->CalcEntropy();




system("PAUSE");

    return EXIT_SUCCESS;
}
