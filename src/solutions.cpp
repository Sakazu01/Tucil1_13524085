#include "solutions.h"

void tampilHasil(Board board, int perm[]){
    for(int i=0;i<board.N;i++){
        for(int j=0;j<board.N;j++){
            if(j==perm[i]) cout<<'#';
            else cout<<board.grid[i][j];
        }
        cout<<'\n';
    }
}

void simpanSolusi(Board board, int perm[], double waktu, long long iter){
    char fname[64];
    char fullpath[256];
    cout<<"nama file output (akan disimpan di test/output/, tanpa .txt): ";
    cin.getline(fname,64);
    // gabungin path otomatis ke test/output/ dan tambahin .txt
    strcpy(fullpath,"test/output/");
    strcat(fullpath,fname);
    strcat(fullpath,".txt");
    ofstream fout(fullpath);
    if(!fout.is_open()){ cout<<"gagal buka file\n"; return; }
    for(int i=0;i<board.N;i++){
        for(int j=0;j<board.N;j++){
            if(j==perm[i]) fout<<'#';
            else fout<<board.grid[i][j];
        }
        fout<<'\n';
    }
    fout<<'\n';
    fout<<"Waktu pencarian: "<<waktu<<" ms\n";
    fout<<"Banyak kasus yang ditinjau: "<<iter<<" kasus\n";
    fout.close();
    cout<<"tersimpan di "<<fname<<'\n';
}

bool nextPerm(int a[], int n){
    int i=n-2;
    while(i>=0 && a[i]>=a[i+1]) i--;
    if(i<0) return false;
    int j=n-1;
    while(a[j]<=a[i]) j--;
    int t=a[i]; a[i]=a[j]; a[j]=t;
    int l=i+1,r=n-1;
    while(l<r){ t=a[l];a[l]=a[r];a[r]=t; l++;r--; }
    return true;
}

int cekValid(Board &board, int perm[]){
    int n=board.N;
    // cek baris berurutan ga boleh bersebelahan/diagonal langsung
    for(int i=0;i<n-1;i++){
        int d=perm[i]-perm[i+1];
        if(d<0) d=-d;
        if(d<=1) return 0;
    }
    // cek tiap queen beda region
    char used[MAX_N]; int cnt=0;
    for(int i=0;i<n;i++){
        char c=board.grid[i][perm[i]];
        for(int k=0;k<cnt;k++) if(used[k]==c) return 0;
        used[cnt++]=c;
    }
    return 1;
}

void solve(Board board){
    int n=board.N;
    int perm[MAX_N];
    for(int i=0;i<n;i++) perm[i]=i;

    long long total=1;
    for(int i=1;i<=n;i++) total*=i;

    cout<<"nyari solusi...\n";
    cout<<"total permutasi: "<<total<<"\n\n";

    long long iter=0;
    int sol[MAX_N], found=0;
    clock_t t0=clock();

    do{
        iter++;
        if(iter%20==0){
            clearScreen();
            printHeader();
            cout<<"percobaan ke "<<iter<<" dari "<<total<<"\n\n";
            tampilHasil(board,perm);
            cout<<'\n';
        }
        if(cekValid(board,perm)){
            found=1;
            for(int i=0;i<n;i++) sol[i]=perm[i];
            break;
        }
    }while(nextPerm(perm,n));

    clock_t t1=clock();
    double waktu=(double)(t1-t0)/CLOCKS_PER_SEC*1000;

    clearScreen();
    printHeader();

    if(found){
        cout<<"solusi ketemu!\n\n";
        tampilHasil(board,sol);
    } else {
        cout<<"ga ada solusi\n";
    }

    cout<<"\nWaktu pencarian: "<<waktu<<" ms\n";
    cout<<"Banyak kasus yang ditinjau: "<<iter<<" kasus\n";

    if(found){
        cout<<"\nmau simpan? (y/n): ";
        char jwb[4]; cin.getline(jwb,4);
        if(jwb[0]=='y'||jwb[0]=='Y') simpanSolusi(board,sol,waktu,iter);
    }
}
