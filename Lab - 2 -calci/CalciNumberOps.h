struct Nums{
  int digit;
  struct Nums *next;
 };

struct number{
 int base;
 int length;
 struct Nums *head;
};

typedef struct number Number;
typedef struct Nums nums;

Number createCalciNumber(char *number_format);
 Number calciConvert(Number n,int to_base);
Number sum(Number a, Number b);
Number minus(Number a, Number b) ;
void printNumber(Number n); 
