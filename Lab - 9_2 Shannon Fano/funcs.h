struct pTable{
char c;
int count;
float prob;
char code[30];
int index;
};

typedef struct pTable pTab;

void shannonFano(pTab *table,int size, char *fname);
