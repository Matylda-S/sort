#include "sortowanie.hh"
#include <chrono>
#include <fstream>
#define DataType int
using namespace std;
template<typename typ>
void sprawdzenie(typ tab[],int ilosc_elem){
    for(int i=0;i<ilosc_elem-1;i++){
        if(tab[i]>tab[i+1]){
            cout<<"Tabela nie jest posortowana";
            cin.get();
            exit(1);
        }
    }
}
template<typename typ>
void sortuj_procent(typ tab[],int ilosc_elem,float procent){
    int a=ilosc_elem*procent/100;
    sort(tab,tab+a);
}
template<typename typ>
void sortuj_odwrotnie(typ tab[],int koniec){
    sort(tab,tab+koniec+1);
    for(int i=0;i<=koniec/2;i++){
        swap(tab[i],tab[koniec-i]);
    }
}
template<typename typ>
typ *utworz_tabele(int ilosc_elem){
    return new typ[ilosc_elem];
}
template<typename typ>
void usun_tabele(typ tab[]){
    delete[] tab;
}
template<typename typ>
void wyswietl(typ tab[],int ilosc_elem){
       for(int i=0;i<ilosc_elem;i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}
template<typename typ>
void zapelnij_losowo(typ tab[],int ilosc_elem){
    //time(0);
    srand(time(NULL)*getpt());
    for(int i=0;i<ilosc_elem;i++){
        tab[i]=rand()%100000;
        
    }
}
template<typename typ>
double czas_scalania(typ tab[],int poczatek,int ilosc_elem){
  auto t_start=chrono::high_resolution_clock::now();
    scalanie(tab,poczatek,ilosc_elem);
    auto t_end=chrono::high_resolution_clock::now();  
    return chrono::duration<double>(t_end-t_start).count();
}
template<typename typ>
double czas_quicksort(typ tab[],int poczatek,int ilosc_elem){
  auto t_start=chrono::high_resolution_clock::now();
    quicksort(tab,poczatek,ilosc_elem-1);
    auto t_end=chrono::high_resolution_clock::now();  
    return chrono::duration<double>(t_end-t_start).count();
}
template<typename typ>
double czas_intersort(typ tab[],int poczatek,int ilosc_elem){
  auto t_start=chrono::high_resolution_clock::now();
  int Max=2*log2(ilosc_elem);
    introsort(tab,poczatek,ilosc_elem,Max);
    auto t_end=chrono::high_resolution_clock::now();  
    return chrono::duration<double>(t_end-t_start).count();
}
template<typename typ>
double czas_kopcowania(typ tab[],int poczatek,int ilosc_elem){
  auto t_start=chrono::high_resolution_clock::now();
    kopcowanie(tab,poczatek,ilosc_elem);
    auto t_end=chrono::high_resolution_clock::now();  
    return chrono::duration<double>(t_end-t_start).count();
}
int main(){
    //ofstream plik("Wyniki.txt");
    int ilosc_tablic;
    //cout<<"Wprowadz ilość tablic: ";
    //cin>>ilosc_tablic;
    int ilosc_elem=1000000;
    //for(int i=0;i<ilosc_tablic;i++){
    DataType *tab=utworz_tabele<DataType>(ilosc_elem);
    DataType *tab_2=utworz_tabele<DataType>(ilosc_elem);
    DataType *tab_3=utworz_tabele<DataType>(ilosc_elem);
    //int *tab=new int [ilosc_elem];
    int poczatek=0;
    float a,b,c;
    zapelnij_losowo<DataType>(tab, ilosc_elem);
    //float procent=25;
    //sortuj_odwrotnie<DataType>(tab,ilosc_elem-1);
    //wyswietl(tab,ilosc_elem);
    a=czas_scalania(tab,poczatek,ilosc_elem);
    cout<<"czas scalania "<<a<<endl;
    sprawdzenie(tab,ilosc_elem);
    usun_tabele(tab);
    zapelnij_losowo<DataType>(tab_2, ilosc_elem);
b=czas_quicksort(tab_2,poczatek,ilosc_elem);
    cout<<"czas quicksort "<<b<<endl;
    sprawdzenie(tab_2,ilosc_elem);
    usun_tabele(tab_2);
    zapelnij_losowo<DataType>(tab_3, ilosc_elem);
    c=czas_kopcowania(tab_3,poczatek,ilosc_elem);
    cout<<"czas kopcowania "<<c<<endl;
    sprawdzenie(tab_3,ilosc_elem);
    usun_tabele(tab_3);
    
    //wyswietl(tab,ilosc_elem);
    
}