#include <cstddef>


size_t getSizeOfTab(double*);
void display_tab(double*);
void display_tab_proc(double*);

//Przyrosty absolutne
void get_P_At_0(double*, double*);
void get_P_At_Atminus1(double*, double*);
//Przyrosty wzglêdne - zwane wskaŸnikami tempa
void get_P_Wt_0(double*, double*);
void get_P_Wt_Wtminus1(double*, double*);
//Indeksy - zwane wskaŸnikami dynamiki
void get_i_t_0(double*, double*); // bazuj¹ce na sta³ej podstawie porównañ
void get_i_t_0_proc(double*, double*);
void get_i_t_tminus1(double*, double*); // bazuj¹ce na zmiennej podstawie porównañ
void get_i_t_tminus1_proc(double*, double*);
//Œrednie:
void get_avrg_ruch_zw(double*, double*); // œrednia zwyk³a okresowa
void get_avrg_ruch_scentr(double*, double*); // œrednia ruchoma scentrowana
