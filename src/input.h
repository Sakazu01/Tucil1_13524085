#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_N 26

// struct buat nyimpen data papan
struct Board{
    int N;
    char grid[MAX_N][MAX_N];
    char regions[MAX_N];       // list region unik
    int numRegions;
    int regionCounts[MAX_N];               // jumlah kotak per region
    int regionCoords[MAX_N][MAX_N][2];     // koordinat tiap region [regionIdx][kotakKe][0=baris/1=kolom]
};

Board readInput(char filename[]);
void fillRegionCoords(Board &board);
void printBoard(Board board);
void clearScreen();
void printHeader();

#endif
