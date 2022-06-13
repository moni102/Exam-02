#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "car.c"
#include "car.h"

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