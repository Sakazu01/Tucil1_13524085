#include "input.h"

Board readInput(char fname[]){
    Board b;
    b.N=0; b.numRegions=0;

    ifstream fin(fname);
    if(!fin.is_open()){ cout<<"gabisa buka file\n"; exit(1); }

    char lines[MAX_N][MAX_N+2];
    int nl=0;
    char buf[256];
    while(fin.getline(buf,256)){
        int len=strlen(buf);
        while(len>0&&(buf[len-1]=='\r'||buf[len-1]=='\n'||buf[len-1]==' ')) len--;
        buf[len]='\0';
        if(len>0){
            for(int i=0;i<len;i++) lines[nl][i]=buf[i];
            lines[nl][len]='\0';
            nl++;
        }
    }
    fin.close();

    if(nl==0){ cout<<"file kosong\n"; exit(1); }
    b.N=nl;

    for(int i=0;i<b.N;i++){
        int len=strlen(lines[i]);
        if(len!=b.N){ cout<<"ukuran baris salah\n"; exit(1); }
        for(int j=0;j<b.N;j++){
            b.grid[i][j]=lines[i][j];
            int ada=0;
            for(int k=0;k<b.numRegions;k++) if(b.regions[k]==lines[i][j]){ ada=1; break; }
            if(!ada) b.regions[b.numRegions++]=lines[i][j];
        }
    }

    if(b.numRegions!=b.N){ cout<<"jumlah tidak cocok dengan ukuran papan\n"; exit(1); }
    return b;
}

void printBoard(Board b){
    for(int i=0;i<b.N;i++){
        for(int j=0;j<b.N;j++) cout<<b.grid[i][j];
        cout<<'\n';
    }
}

void clearScreen(){ system("cls"); }

void printHeader(){
    cout<<"==============================\n";
    cout<<"   QUEENS PUZZLE SOLVER\n";
    cout<<"==============================\n\n";
}

void fillRegionCoords(Board &b){
    for(int i=0;i<b.numRegions;i++) b.regionCounts[i]=0;
    for(int i=0;i<b.N;i++){
        for(int j=0;j<b.N;j++){
            char c=b.grid[i][j];
            int idx=-1;
            for(int k=0;k<b.numRegions;k++) if(b.regions[k]==c){ idx=k; break; }
            if(idx!=-1){
                int cnt=b.regionCounts[idx];
                b.regionCoords[idx][cnt][0]=i;
                b.regionCoords[idx][cnt][1]=j;
                b.regionCounts[idx]++;
            }
        }
    }
}
