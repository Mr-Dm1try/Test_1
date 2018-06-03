#pragma once
#include "stdafx.h"

using namespace std;

int Random(int min, int max);
void FillVec(vector<int> &someVec, int size);
void FillMap(map<int, int> &someMap, int size);
int DelFromVec(vector<int> &someVec);
int DelFromMap(map<int, int> &someMap);
void Synch(vector<int> &someVec, map<int, int> &someMap);