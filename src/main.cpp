#include "input.h"
#include "solutions.h"

int main(){
    char fname[64];
    char fullpath[256];

    printHeader();
    cout<<"masukkan nama file input (dari folder test/input/): ";
    cin.getline(fname,64);

    // gabungin path otomatis ke test/input/
    strcpy(fullpath,"test/input/");
    strcat(fullpath,fname);

    Board papan = readInput(fullpath);
    cout<<"\npapan yang dibaca:\n";
    printBoard(papan);
    cout<<'\n';

    solve(papan);

    return 0;
}

