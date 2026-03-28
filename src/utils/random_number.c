#include "random_number.h"

#include <stdlib.h>

int GetRandomNumber(int min, int max){
    int number = rand() % (max - min + 1) + min; 
    
    return number;
}