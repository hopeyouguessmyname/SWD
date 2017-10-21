#include "functions.h"


double szereg_czas[] = {10.4, 10, 9.81, 9.98, 10.1, 11.67, 12.03, 11.9, 7 };


int main()
{
  display_tab(szereg_czas);

  double* przyrosty_At_0=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_P_At_0(szereg_czas, przyrosty_At_0);
  display_tab(przyrosty_At_0);

  double* przyrosty_At_Atminus1=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_P_At_Atminus1(szereg_czas, przyrosty_At_Atminus1);
  display_tab(przyrosty_At_Atminus1);

  // wskaüniki tempa:
  double* przyrosty_Wt_0=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_P_Wt_0(szereg_czas, przyrosty_Wt_0);
  display_tab(przyrosty_Wt_0);

  double* przyrosty_Wt_Wtminus1=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_P_Wt_Wtminus1(szereg_czas, przyrosty_Wt_Wtminus1);
  display_tab(przyrosty_Wt_Wtminus1);

  // wskaüniki dynamiki:
  double* indeksy_t_0=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_i_t_0(szereg_czas, indeksy_t_0);
  display_tab(indeksy_t_0);

  // wartoúci procentowe:
  double* indeksy_t_0_proc=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_i_t_0_proc(szereg_czas, indeksy_t_0_proc);
  display_tab_proc(indeksy_t_0_proc);

  double* indeksy_t_tminus1=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_i_t_tminus1(szereg_czas, indeksy_t_tminus1);
  display_tab(indeksy_t_tminus1);

  // wartoúci procentowe:
  double* indeksy_t_tminus1_proc=new double[(getSizeOfTab(szereg_czas)+1)-1];
  get_i_t_tminus1_proc(szereg_czas, indeksy_t_tminus1_proc);
  display_tab_proc(indeksy_t_tminus1_proc);

  // úrednie:
  double* avrg_ruch_zw=new double[(getSizeOfTab(szereg_czas)+1)-2];
  get_avrg_ruch_zw(szereg_czas, avrg_ruch_zw);
  display_tab(avrg_ruch_zw);

  double* avrg_ruch_scentr=new double[(getSizeOfTab(szereg_czas)+1)-4];
  get_avrg_ruch_scentr(szereg_czas, avrg_ruch_scentr);
  display_tab(avrg_ruch_scentr);

  return 0;
}
