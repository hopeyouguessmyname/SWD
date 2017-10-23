/*
 * DBase.h
 *
 *  Created on: 23.10.2017
 *      Author: 168625
 */

#ifndef DBASE_H_
#define DBASE_H_

#include <sqlite3.h>

typedef char TABLE_NAME[20+1];
typedef char DATE[8+1];

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

class DBase
{
    sqlite3 *db;
    char *zErrMsg;
    char sql[256];

  public:
    DBase();
    ~DBase();
    void createTable();
    void createTable(TABLE_NAME);
    void insertIntoTable();
    void insertIntoTable(TABLE_NAME, DATE, double);
};

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

#endif /* DBASE_H_ */
