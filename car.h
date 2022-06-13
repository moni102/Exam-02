#include <math.h>

typedef struct Car
{
    char model[21];
    u_int8_t maxSpeed;
    double price;
} Car;

int randint(int, int);
double randReal(double, double);
char *randomName(char *);
void print(const Car *);

int compModelASC(const void *, const void *);
int compModelDESC(const void *, const void *);
int compSpeedASC(const void *, const void *);
int compSpeedDESC(const void *, const void *);
int compPriceASC(const void *, const void *);
int compPriceDESC(const void *, const void *);

typedef int (*comparef_t)(const void *, const void *);