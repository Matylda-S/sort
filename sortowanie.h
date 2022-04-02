#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <math.h>
template<typename typ>
void quicksort(typ tab[], int poczatek, int ilosc_elem);
template<typename typ>
void scalanie(typ tab[],int poczatek, int ilosc_elem);
template<typename typ>
void introsort(typ tab[],int poczatek, int ilosc_elem,int Max);
template<typename typ>
void kopcowanie(typ *tab,int poczatek, int ilosc_elem);