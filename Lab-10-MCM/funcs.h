struct rcTable{
int row;
int col;
};

typedef struct rcTable pTab;
int mcmBForce(pTab *table,int i,int size);
void mcmDP(pTab *table,int size);
void testCaseGenerator(int T);
void printSmin();