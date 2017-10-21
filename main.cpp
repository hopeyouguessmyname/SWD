#include <iostream>
#include <cstddef>

double szereg_czas[] = {10.4, 10, 9.81, 9.98, 10.1, 11.67, 12.03, 11.9, 7 };

size_t getSizeOfTab(double*);
void display_tab(double*);
void display_tab_proc(double*);

//Przyrosty absolutne
void get_P_At_0(double*, double*);
void get_P_At_Atminus1(double*, double*);
//Przyrosty wzgl�dne - zwane wska�nikami tempa
void get_P_Wt_0(double*, double*);
void get_P_Wt_Wtminus1(double*, double*);
//Indeksy - zwane wska�nikami dynamiki
void get_i_t_0(double*, double*); // bazuj�ce na sta�ej podstawie por�wna�
void get_i_t_0_proc(double*, double*);
void get_i_t_tminus1(double*, double*); // bazuj�ce na zmiennej podstawie por�wna�
void get_i_t_tminus1_proc(double*, double*);
//�rednie:
void get_avrg_ruch_zw(double*, double*); // �rednia zwyk�a okresowa
void get_avrg_ruch_scentr(double*, double*); // �rednia ruchoma scentrowana

int main()
{
  display_tab(szereg_czas);



  double* przyrosty_At_0=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_P_At_0(szereg_czas, przyrosty_At_0);
  display_tab(przyrosty_At_0);

  double* przyrosty_At_Atminus1=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_P_At_Atminus1(szereg_czas, przyrosty_At_Atminus1);
  display_tab(przyrosty_At_Atminus1);



  // wska�niki tempa:
  double* przyrosty_Wt_0=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_P_Wt_0(szereg_czas, przyrosty_Wt_0);
  display_tab(przyrosty_Wt_0);

  double* przyrosty_Wt_Wtminus1=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_P_Wt_Wtminus1(szereg_czas, przyrosty_Wt_Wtminus1);
  display_tab(przyrosty_Wt_Wtminus1);



  // wska�niki dynamiki:
  double* indeksy_t_0=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_i_t_0(szereg_czas, indeksy_t_0);
  display_tab(indeksy_t_0);

  // warto�ci procentowe:
  double* indeksy_t_0_proc=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_i_t_0_proc(szereg_czas, indeksy_t_0_proc);
  display_tab_proc(indeksy_t_0_proc);

  double* indeksy_t_tminus1=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_i_t_tminus1(szereg_czas, indeksy_t_tminus1);
  display_tab(indeksy_t_tminus1);

  // warto�ci procentowe:
  double* indeksy_t_tminus1_proc=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_i_t_tminus1_proc(szereg_czas, indeksy_t_tminus1_proc);
  display_tab_proc(indeksy_t_tminus1_proc);



  // �rednie:
  double* avrg_ruch_zw=new double[(getSizeOfTab(szereg_czas)+1)-2];
  get_avrg_ruch_zw(szereg_czas, avrg_ruch_zw);
  display_tab(avrg_ruch_zw);

  double* avrg_ruch_scentr=new double[(getSizeOfTab(szereg_czas)+1)-4];
  get_avrg_ruch_scentr(szereg_czas, avrg_ruch_scentr);
  display_tab(avrg_ruch_scentr);


  return 0;
}

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
  std::cout << "Przyrosty absolutne �a�cuchowe: ";
  for(size_t i=1; i<getSizeOfTab(tab_in);i++)
    tab_out[i-1]=tab_in[i]-tab_in[i-1];
}

void get_P_Wt_0(double* tab_in, double* tab_out)
{
  std::cout << "Przyrosty wzgl�dne jednopodstawowe: ";
  for(size_t i=1; i<getSizeOfTab(tab_in);i++)
    tab_out[i-1]=(tab_in[i]-tab_in[0])/tab_in[0];
}

void get_P_Wt_Wtminus1(double* tab_in, double* tab_out)
{
  std::cout << "Przyrosty wzgl�dne �a�cuchowe: ";
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
  std::cout << "indeksy �a�cuchowe: ";
  for(size_t i=1; i<getSizeOfTab(tab_in);i++)
    tab_out[i-1]=tab_in[i]/tab_in[i-1];
}

void get_i_t_tminus1_proc(double* tab_in, double* tab_out)
{
  std::cout << "indeksy �a�cuchowe (w procentach): ";
  for(size_t i=1; i<getSizeOfTab(tab_in);i++)
    tab_out[i-1]=((tab_in[i]/tab_in[i-1])-1)*100;
}

void get_avrg_ruch_zw(double* tab_in, double* tab_out) // nieparzysta liczba wyraz�w szeregu czasowego
{
  std::cout << "�rednia ruchoma zyk�a: ";// << std::endl;
  for(size_t i=1; i<(getSizeOfTab(tab_in)-1);i++)
    tab_out[i-1]=(tab_in[i-1]+tab_in[i]+tab_in[i+1])/3;
}

void get_avrg_ruch_scentr(double* tab_in, double* tab_out)
{
  std::cout << "�rednia ruchoma scentrowana: "; // parzysta liczba wyraz�w szeregu czasowego
  for(size_t i=2; i<(getSizeOfTab(tab_in)-2);i++)
    tab_out[i-2]=((tab_in[i-2]/2)+tab_in[i-1]+tab_in[i]+tab_in[i+1]+(tab_in[i+2]/2))/4;
}
