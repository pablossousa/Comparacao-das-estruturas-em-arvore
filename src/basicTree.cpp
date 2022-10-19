#include "include/basicTree.hpp"

TreeBin *CreateTreeBin() {
    return NULL;
}

bool TVazia(TreeBin **t) {
    return *t == NULL;
}

void insertTree(TreeBin **t, Record r) {

    if (TVazia(t)) {
        *t = (TreeBin *)malloc(sizeof(TreeBin));
        (*t)->esq = NULL;
        (*t)->dir = NULL;
        (*t)->reg = r;
    } else {

        if (r.key < (*t)->reg.key) {
            insertTree(&(*t)->esq, r);
        }

        if (r.key > (*t)->reg.key) {
            insertTree(&(*t)->dir, r);
        }
    }
}

void pesquisaBin(TreeBin **t, TreeBin **auxBin, Record r) {

    if (*t == NULL) {
        return;
    }

    if ((*t)->reg.key > r.key) {
        pesquisaBin(&(*t)->esq, auxBin, r);
        return;
    }
    
    if ((*t)->reg.key < r.key) {
        pesquisaBin(&(*t)->dir, auxBin, r);
        return;
    }

    *auxBin = *t;

    if (*auxBin != NULL) {}

}

int isInTree(TreeBin *t, Record r) {

    if (t == NULL) {
        return 0;
    }

    return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}

void antecessor(TreeBin **t, TreeBin *aux) {

    if ((*t)->dir != NULL) {
        antecessor(&(*t)->dir, aux);
        return;
    }

    aux->reg = (*t)->reg;
    aux = *t;
    *t = (*t)->esq;
    free(aux);
}

void removeTree(TreeBin **t, Record r) {
    TreeBin *aux;

    if (*t == NULL) {
        return;
    }

    if (r.key < (*t)->reg.key) {
        removeTree(&(*t)->esq, r);
        return;
    }
    if (r.key > (*t)->reg.key) {
        removeTree(&(*t)->dir, r);
        return;
    }

    if ((*t)->dir == NULL) {
        aux = *t;
        *t = (*t)->esq;
        free(aux);
        return;
    }

    if ((*t)->esq != NULL) {
        antecessor(&(*t)->esq, *t);
        return;
    }

    aux = *t;
    *t = (*t)->dir;
    free(aux);
}

void treeSizeBin(TreeBin *t, int *cont) {
    if (!(t == NULL)) {
        (*cont)++;
        treeSizeBin(t->esq, cont);
        treeSizeBin(t->dir, cont);
    }
}

// void central(TreeBin *t) {
//     if (!(t == NULL)) {
//         central(t->esq);
//         printf("%.4f ", t->reg.key);
//         central(t->dir);
//     }
// }

// void posordem(TreeBin *t) {
//     if (!(t == NULL)) {
//         posordem(t->esq);
//         posordem(t->dir);
//         printf("%.4f ", t->reg.key);
//     }
// }

void widthPath(TreeBin *T) {
	queue<TreeBin*> tempFila;
	TreeBin *temp;
	int tempCont=1,cont=0;
	tempFila.push(T);
	while (!(tempFila.empty())) {
		cont = 0;
		for (int i = 0; i < tempCont; i++){
			temp =tempFila.front();
            cout << temp->reg.key << " - ";
			//printf("%f, ",temp->reg.key);
			tempFila.pop();
			if (temp->esq) {
				tempFila.push(temp->esq);
				cont++;
			}
			if (temp->dir) {
				tempFila.push(temp->dir);
				cont++;
			}
		}
		printf("\n");
		tempCont = cont;
	}
}