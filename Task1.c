#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define COUNT 10

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

int (*getComparator(int n))(const void *, const void *);

typedef int (*comparef_t)(const void *, const void *);

comparef_t compfunc[] = {compModelASC, compModelDESC, compSpeedASC, compSpeedDESC, compPriceASC, compPriceDESC};

int main()
{
    srand(time(NULL));
    int opt;
    Car cars[COUNT];

    for (int i = 0; i < COUNT; i++)
    {
        randomName(cars[i].model);
        cars[i].maxSpeed = randint(100, 300);
        cars[i].price = randReal(1000.0, 100000.0);
    }

    scanf("%d", &opt);
    qsort(cars, COUNT, sizeof(cars[0]), compfunc[opt]);
    for (int i = 0; i < COUNT; i++)
    {
        print(cars + i);
    }

    return 0;
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

char *randomName(char *name)
{
    unsigned index = 0;
    name[index++] = randint('A', 'Z');
    int n = randint(4, 10);
    for (int i = 0; i < n; i++)
    {
        name[index++] = randint('a', 'z');
    }
    name[index] = '\0';
    return name;
}

void print(const Car *c)
{
    printf("Title: %21s ", c->model);
    printf("Author: %3u ", c->maxSpeed);
    printf("Price: %4.2lf\n", c->price);
}

int compModelASC(const void *cp1, const void *cp2)
{
    Car *c1 = (Car *)cp1;
    Car *c2 = (Car *)cp2;
    return strcmp(c1->model, c2->model);
}

int compTitleDESC(const void *cp1, const void *cp2)
{
    Car *c1 = (Car *)cp1;
    Car *c2 = (Car *)cp2;
    return strcmp(c2->model, c1->model);
}

u_int8_t compPagesASC(const void *cp1, const void *cp2)
{
    Car *c1 = (Car *)cp1;
    Car *c2 = (Car *)cp2;
    return c1->maxSpeed - c2->maxSpeed;
}

u_int8_t compPagesDESC(const void *cp1, const void *cp2)
{
    Car *c1 = (Car *)cp1;
    Car *c2 = (Car *)cp2;
    return c2->maxSpeed - c1->maxSpeed;
}

int compPriceASC(const void *cp1, const void *cp2)
{
    Car *c1 = (Car *)cp1;
    Car *c2 = (Car *)cp2;
    if (fabs(c1->price - c2->price) < 0.0001)
    {
        return 0;
    }
    else if (c1->price > c2->price)
    {
        return 1;
    }
    return -1;
}

int compPriceDESC(const void *cp1, const void *cp2)
{
    Car *c1 = (Car *)cp1;
    Car *c2 = (Car *)cp2;
    if (fabs(c1->price - c2->price) < 0.0001)
    {
        return 0;
    }
    else if (c1->price < c2->price)
    {
        return 1;
    }
    return -1;
}

int (*getComparator(int n))(const void *cp1, const void *cp2)
{
    if (n >= 1 && n <= 6)
    {
        return compfunc[n];
    }
    return NULL;
}