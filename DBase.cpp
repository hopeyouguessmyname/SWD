/*
 * DBase.cpp
 *
 *  Created on: 23.10.2017
 *      Author: 168625
 */
#include <stdio.h>

#include "functions.h"
#include "DBase.h"


DBase::DBase()
{
  zErrMsg=0;

  if(sqlite3_open("swd.db", &db))
     printf("Can't open database: %s\n", sqlite3_errmsg(db));
  else
     printf("Opened database successfully\n");
}

DBase::~DBase()
{
  sqlite3_close(db);
}

void DBase::createTable()
{
  sprintf(sql,"CREATE TABLE stock("
      "name TEXT NOT NULL,"
      "date DATE NOT NULL,"
      "price DECIMAL);");

    if(sqlite3_exec(db, sql, callback, 0, &zErrMsg))
    {
      printf("SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    }
    else
      printf("Table created successfully\n");
}

void DBase::createTable(TABLE_NAME Name)
{
  sprintf(sql,"CREATE TABLE %s("
      "name TEXT NOT NULL,"
      "date DATE NOT NULL,"
      "price DECIMAL);", Name);

    if(sqlite3_exec(db, sql, callback, 0, &zErrMsg))
    {
      printf("SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    }
    else
      printf("Table created successfully\n");
}

void DBase::insertIntoTable()
{
  sprintf(sql, "INSERT INTO stock (name,date,price) "
        "VALUES ('BZWBK', '19-10-2017', 362.00 );"
        "INSERT INTO stock (name,date,price) "
        "VALUES ('BZWBK', '18-10-2017', 361.50 );"
        "INSERT INTO stock (name,date,price) "
        "VALUES ('BZWBK', '17-10-2017', 361.50 );"
        "INSERT INTO stock (name,date,price) "
        "VALUES ('BZWBK', '16-10-2017', 362.00 );");

  if(sqlite3_exec(db, sql, callback, 0, &zErrMsg))
  {
     printf("SQL error: %s\n", zErrMsg);
     sqlite3_free(zErrMsg);
  }
  else
     printf("Records created successfully\n");
}

void DBase::insertIntoTable(TABLE_NAME Name, DATE Date, double Price)
{

  sprintf(sql, "INSERT INTO stock(name,date,price) "
                "VALUES ('%s','%s',%f);", Name, Date, Price);

  if(sqlite3_exec(db, sql, callback, 0, &zErrMsg))
  {
     printf("SQL error: %s\n", zErrMsg);
     sqlite3_free(zErrMsg);
  }
  else
     printf("Records created successfully\n");
}


