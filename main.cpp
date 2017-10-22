#include "functions.h"

#include <sqlite3.h>
#include <stdio.h>

double szereg_czas[] = {10.4, 10, 9.81, 9.98, 10.1, 11.67, 12.03, 11.9, 7 };

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
   int i;
   for(i = 0; i<argc; i++)
   {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main()
{
  sqlite3 *db;
  int rc;
  char *zErrMsg = 0;
  char* sql;

  rc = sqlite3_open("swd.db", &db);

  if( rc )
  {
     printf("Can't open database: %s\n", sqlite3_errmsg(db));
     return(0);
  }
  else
  {
     printf("Opened database successfully\n");
  }

  /* Create SQL statement */
  sql = "CREATE TABLE stock("  \
        "name           TEXT    NOT NULL," \
        "date           DATE    NOT NULL," \
        "price          DECIMAL);";

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

  if( rc != SQLITE_OK )
  {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }
  else
  {
    fprintf(stdout, "Table created successfully\n");
  }

   /* Create SQL statement */
   sql = "INSERT INTO stock (name,date,price) "  \
         "VALUES ('BZWBK', '19-10-2017', 362.00 );"  \
         "INSERT INTO stock (name,date,price) "  \
         "VALUES ('BZWBK', '18-10-2017', 361.50 );"  \
         "INSERT INTO stock (name,date,price) "  \
         "VALUES ('BZWBK', '17-10-2017', 361.50 );"  \
         "INSERT INTO stock (name,date,price) "  \
         "VALUES ('BZWBK', '16-10-2017', 362.00 );";


   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

   if( rc != SQLITE_OK )
   {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   else
   {
      fprintf(stdout, "Records created successfully\n");
   }

  sqlite3_close(db);




//  display_tab(szereg_czas);
//
//  double* przyrosty_At_0=new double[(getSizeOfTab(szereg_czas)+1)-1];
//  get_P_At_0(szereg_czas, przyrosty_At_0);
//  display_tab(przyrosty_At_0);
//
//  double* przyrosty_At_Atminus1=new double[(getSizeOfTab(szereg_czas)+1)-1];
//  get_P_At_Atminus1(szereg_czas, przyrosty_At_Atminus1);
//  display_tab(przyrosty_At_Atminus1);
//
//  // wskaŸniki tempa:
//  double* przyrosty_Wt_0=new double[(getSizeOfTab(szereg_czas)+1)-1];
//  get_P_Wt_0(szereg_czas, przyrosty_Wt_0);
//  display_tab(przyrosty_Wt_0);
//
//  double* przyrosty_Wt_Wtminus1=new double[(getSizeOfTab(szereg_czas)+1)-1];
//  get_P_Wt_Wtminus1(szereg_czas, przyrosty_Wt_Wtminus1);
//  display_tab(przyrosty_Wt_Wtminus1);
//
//  // wskaŸniki dynamiki:
//  double* indeksy_t_0=new double[(getSizeOfTab(szereg_czas)+1)-1];
//  get_i_t_0(szereg_czas, indeksy_t_0);
//  display_tab(indeksy_t_0);
//
//  // wartoœci procentowe:
//  double* indeksy_t_0_proc=new double[(getSizeOfTab(szereg_czas)+1)-1];
//  get_i_t_0_proc(szereg_czas, indeksy_t_0_proc);
//  display_tab_proc(indeksy_t_0_proc);
//
//  double* indeksy_t_tminus1=new double[(getSizeOfTab(szereg_czas)+1)-1];
//  get_i_t_tminus1(szereg_czas, indeksy_t_tminus1);
//  display_tab(indeksy_t_tminus1);
//
//  // wartoœci procentowe:
//  double* indeksy_t_tminus1_proc=new double[(getSizeOfTab(szereg_czas)+1)-1];
//  get_i_t_tminus1_proc(szereg_czas, indeksy_t_tminus1_proc);
//  display_tab_proc(indeksy_t_tminus1_proc);
//
//  // œrednie:
//  double* avrg_ruch_zw=new double[(getSizeOfTab(szereg_czas)+1)-2];
//  get_avrg_ruch_zw(szereg_czas, avrg_ruch_zw);
//  display_tab(avrg_ruch_zw);
//
//  double* avrg_ruch_scentr=new double[(getSizeOfTab(szereg_czas)+1)-4];
//  get_avrg_ruch_scentr(szereg_czas, avrg_ruch_scentr);
//  display_tab(avrg_ruch_scentr);

  return 0;
}
