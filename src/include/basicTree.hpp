#ifndef BASICTREE_H 
#define BASICTREE_H

#include "record.hpp"

#include <queue>

// struct Record{
// 	int key;
// 	int value;
// };

struct TreeBin{
	Record reg;
	TreeBin *esq, *dir;
};

TreeBin* CreateTreeBin();
bool TVazia(TreeBin **t);
void insertTree(TreeBin **t, Record r);
void pesquisaBin(TreeBin **t, TreeBin **aux, Record r);
int isInTree(TreeBin *t, Record r);

void removeTree(TreeBin **t, Record r);
void antecessor(TreeBin **t, TreeBin *aux);

void treeSizeBin(TreeBin *t, int *cont);
// void central(TreeBin *t);
// void posordem(TreeBin *t);
void widthPath(TreeBin *t);

#endif