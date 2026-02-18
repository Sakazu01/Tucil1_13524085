#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include "input.h"

void tampilHasil(Board board, int perm[]);
void simpanSolusi(Board board, int perm[], double waktu, long long kasus);
bool nextPerm(int arr[], int n);
int cekValid(Board &board, int perm[]);
void solve(Board board);

#endif
