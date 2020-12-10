/*
    Project 3
    ENEE150 Fall 2020
    Joseph M Krzyzek
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bank_ {
  char *bank_name;
  char *address;
  char *city;
  char *state;
  int zip;
  float holdings;
  struct bank_ *next;
} bank, *pbank;

typedef struct account_ {
  char *lname;
  char *fname;
  char *address;
  char *city;
  char *state;
  int zip;
  char *bank;
  int acc_num;
  float balance;
  struct account_ *next;
} account, *paccount;


/***************************/
/*** FUNCTION PROTOTYPES ***/
/***************************/
void new_bank( pbank * );
void print_bank( pbank * );
void new_account( paccount * );
void print_account( paccount * );
void deposit( paccount * , pbank * );
void withdrawal( paccount * , pbank * );
void close_account( paccount *, pbank * );
