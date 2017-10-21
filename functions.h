#include <cstddef>


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
