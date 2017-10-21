#include "functions.h"

#include <iostream>


size_t getSizeOfTab(double* tab)
{
  size_t tabSize = 0;
  while(tab[tabSize]!='\0')
    tabSize++;
  return tabSize;
}

void display_tab(double* tab)
{
  for(size_t i=0; i<getSizeOfTab(tab); i++)
    std::cout << tab[i] << " ";
  std::cout << std::endl;
}

void display_tab_proc(double* tab)
{
  for(size_t i=0; i<getSizeOfTab(tab); i++)
    std::cout << tab[i] << "% ";
  std::cout << std::endl;
}

void get_P_At_0(double* tab_in, double* tab_out)
{
  std::cout << "Przyrosty absolutne jednopodstawowe: ";
  for(size_t i=1; i<getSizeOfTab(tab_in);i++)
    tab_out[i-1]=tab_in[i]-tab_in[0];
}

void get_P_At_Atminus1(double* tab_in, double* tab_out)
{
  std::cout << "Przyrosty absolutne ³añcuchowe: ";
  for(size_t i=1; i<getSizeOfTab(tab_in);i++)
    tab_out[i-1]=tab_in[i]-tab_in[i-1];
}

void get_P_Wt_0(double* tab_in, double* tab_out)
{
  std::cout << "Przyrosty wzglêdne jednopodstawowe: ";
  for(size_t i=1; i<getSizeOfTab(tab_in);i++)
    tab_out[i-1]=(tab_in[i]-tab_in[0])/tab_in[0];
}

void get_P_Wt_Wtminus1(double* tab_in, double* tab_out)
{
  std::cout << "Przyrosty wzglêdne ³añcuchowe: ";
  for(size_t i=1; i<getSizeOfTab(tab_in);i++)
    tab_out[i-1]=(tab_in[i]-tab_in[i-1])/tab_in[i-1];
}

void get_i_t_0(double* tab_in, double* tab_out)
{
  std::cout << "indeksy jednopodstawowe: ";
  for(size_t i=1; i<getSizeOfTab(tab_in);i++)
    tab_out[i-1]=tab_in[i]/tab_in[0];
}

void get_i_t_0_proc(double* tab_in, double* tab_out)
{
  std::cout << "indeksy jednopodstawowe (w procentach): ";
  for(size_t i=1; i<getSizeOfTab(tab_in);i++)
    tab_out[i-1]=((tab_in[i]/tab_in[0])-1)*100;
}

void get_i_t_tminus1(double* tab_in, double* tab_out)
{
  std::cout << "indeksy ³añcuchowe: ";
  for(size_t i=1; i<getSizeOfTab(tab_in);i++)
    tab_out[i-1]=tab_in[i]/tab_in[i-1];
}

void get_i_t_tminus1_proc(double* tab_in, double* tab_out)
{
  std::cout << "indeksy ³añcuchowe (w procentach): ";
  for(size_t i=1; i<getSizeOfTab(tab_in);i++)
    tab_out[i-1]=((tab_in[i]/tab_in[i-1])-1)*100;
}

void get_avrg_ruch_zw(double* tab_in, double* tab_out) // nieparzysta liczba wyrazów szeregu czasowego
{
  std::cout << "œrednia ruchoma zyk³a: ";// << std::endl;
  for(size_t i=1; i<(getSizeOfTab(tab_in)-1);i++)
    tab_out[i-1]=(tab_in[i-1]+tab_in[i]+tab_in[i+1])/3;
}

void get_avrg_ruch_scentr(double* tab_in, double* tab_out)
{
  std::cout << "œrednia ruchoma scentrowana: "; // parzysta liczba wyrazów szeregu czasowego
  for(size_t i=2; i<(getSizeOfTab(tab_in)-2);i++)
    tab_out[i-2]=((tab_in[i-2]/2)+tab_in[i-1]+tab_in[i]+tab_in[i+1]+(tab_in[i+2]/2))/4;
}
