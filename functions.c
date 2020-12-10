/*
    Project 3
    ENEE150 Fall 2020
    Joseph M Krzyzek
*/

#include "bank.h"

/*****************************/
/*** FUNCTION DECLARATIONS ***/
/*****************************/
void new_bank( pbank *head_bank )
{
  // Create a new bank structure
  pbank new = ( pbank )malloc( sizeof( bank ) );
  /* Declare variables */
  int i, zip, length = 0;
  char *temp, c;
  float balance = 0;

  for(i = 0; i < 4; i++)
  {
    /* Grab the information */
    temp = (char *) malloc(sizeof(char));
    temp[0] = '\0';
    while( (c = getc(stdin) ) != '\n' )
    {
      temp[length++] = c;
      temp = (char *)realloc(temp, strlen(temp)+1);
    }
    temp[length] = '\0';
    switch(i)
    {
        case 0:
          //Malloc the exact size of bank_name
          new->bank_name = (char *)malloc(sizeof(char)*(strlen(temp)+1));
          strcpy( new->bank_name, temp);
          break;
        case 1:
          new->address = (char *)malloc(sizeof(char)*(strlen(temp)+1));
          strcpy( new->address, temp);
          break;
        case 2:
          new->city = (char *)malloc(sizeof(char)*(strlen(temp)+1));
          strcpy( new->city, temp);
          break;
        case 3:
          new->state = (char *)malloc(sizeof(char)*(strlen(temp)+1));
          strcpy( new->state, temp);
          break;
    }
    // Reset and clear variables
    length = 0;
    free(temp);
  }
  // Grab and declare the rest of the information
  scanf("%d\n", &zip);
  new->zip = zip;
  new->holdings = 0;
  // Head insert
  new->next = *head_bank;
  *head_bank = new;
}
void print_bank( pbank *head_bank )
{
  pbank cur = *head_bank;
  char *temp, c;
  int length = 0;
  /* Grab the information */
  temp = (char *) malloc(sizeof(char));
  temp[0] = '\0';
  while( (c = getc(stdin) ) != '\n' )
  {
    temp[length++] = c;
    temp = (char *)realloc(temp, strlen(temp)+1);
  }
  temp[length] = '\0';

  while ( cur )
  {
    if( strcmp(cur->bank_name, temp) == 0 )
    {
      printf("***\nBank:  %s\n", cur->bank_name);
      printf("Address:  %s, %s, %s  %d\n", cur->address, cur->city, cur->state, cur->zip);
      printf("Holdings:  $%.2f\n", cur->holdings);
    }
    cur = cur->next;
  }
}
void new_account( paccount *head_account )
{
  //Create a new account structure
  paccount new = ( paccount )malloc( sizeof( account ) );
  //Declare variables
  int i, length = 0;
  char *temp, c;
  int zip, account;
  float balance = 0;

  for(i = 0; i < 8; i++)
  {
    temp = (char *)malloc(sizeof(char));
    temp[0] = '\0';
    while((c = getc(stdin)) != '\n'){
      temp[length++] = c;
      temp = (char *)realloc(temp, strlen(temp)+1);
    }
    temp[length] = '\0';
    switch(i)
    {
        case 0:
          //Malloc the exact size
          new->lname = (char *)malloc(sizeof(char)*(strlen(temp)+1));
          strcpy( new->lname, temp);
          break;
        case 1:
          //Malloc the exact size
          new->fname = (char *)malloc(sizeof(char)*(strlen(temp)+1));
          strcpy( new->fname, temp);
          break;
        case 2:
          new->address = (char *)malloc(sizeof(char)*(strlen(temp)+1));
          strcpy( new->address, temp);
          break;
        case 3:
          new->city = (char *)malloc(sizeof(char)*(strlen(temp)+1));
          strcpy( new->city, temp);
          break;
        case 4:
          new->state = (char *)malloc(sizeof(char)*(strlen(temp)+1));
          strcpy( new->state, temp);
          break;
        case 5:
          zip = atoi(temp);
          new->zip = zip;
          break;
        case 6:
          new->bank = (char *)malloc(sizeof(char)*(strlen(temp)+1));
          strcpy( new->bank, temp);
          break;
        case 7:
          account = atoi(temp);
          new->acc_num = account;
          break;
    }
    length = 0;
    free(temp);
  }
  new->balance = 0;
  // Head insert
  new->next = *head_account;
  *head_account = new;
}
void print_account( paccount *head_account )
{
  paccount cur = *head_account;
  char *temp, c;
  int length = 0, acc_num;

  temp = (char *)malloc(sizeof(char));
  temp[0] = '\0';
  while((c = getc(stdin)) != '\n'){
    temp[length++] = c;
    temp = (char *)realloc(temp, strlen(temp)+1);
  }
  temp[length] = '\0';
  acc_num = atoi(temp);
  while ( cur )
  {
    if( cur->acc_num == acc_num )
    {
      printf("***\nName:  %s, %s\n", cur->lname, cur->fname);
      printf("Bank:  %s\n", cur->bank);
      printf("Account Number:  %d\n", cur->acc_num);
      printf("Address:  %s, %s, %s  %d\n", cur->address, cur->city, cur->state, cur->zip);
      printf("Balance:  $%.2f\n", cur->balance);
    }
    cur = cur->next;
  }
}
void deposit( paccount *head_account, pbank *head_bank )
{
  paccount thisa;
  thisa = *head_account;
  pbank thisb;
  thisb = *head_bank;

  char *temp, c;
  int length = 0, i = 0, account;
  float deposit;
  while( i < 2 )
  {
    temp = (char *)malloc(sizeof(char));
    temp[0] = '\0';
    while((c = getc(stdin)) != '\n')
    {
      temp[length++] = c;
      temp = (char *)realloc(temp, strlen(temp)+1);
    }
    temp[length] = '\0';
    if( i == 0)
    {
      account = atoi(temp);
      free(temp);
      length = 0;
    }
    if( i == 1 )
    {
      deposit = atof(temp);
      free(temp);
      length = 0;
    }
    i++;
  }
  while ( thisa )
  {
    if( thisa->acc_num == account )
    {
      thisa->balance += deposit;
      temp = (char *)malloc(sizeof(char)*(strlen(thisa->bank)+1));
      strcpy(temp, thisa->bank);
    }
    thisa = thisa->next;
  }
  while( thisb )
  {
    if(strcmp(thisb->bank_name, temp) == 0)
    {
      thisb->holdings += deposit;
    }
    thisb = thisb->next;
  }
  free(temp);
}
void withdrawal(  paccount *head_account, pbank *head_bank )
{
  paccount thisa = *head_account;
  pbank thisb = *head_bank;

  char *temp, c;
  int length = 0, i = 0, account;
  float withdrawal;
  while( i < 2 )
  {
    temp = (char *)malloc(sizeof(char));
    temp[0] = '\0';
    while((c = getc(stdin)) != '\n'){
      temp[length++] = c;
      temp = (char *)realloc(temp, strlen(temp)+1);
    }
    temp[length] = '\0';

    if( i == 0)
    {
      account = atoi(temp);
      free(temp);
      length = 0;
    }
    if( i == 1 )
    {
      withdrawal = atof(temp);
      free(temp);
      length = 0;
    }
    i++;
  }
  while ( thisa )
  {
    if( thisa->acc_num == account )
    {
      thisa->balance -= withdrawal;
      temp = (char *)malloc(sizeof(char)*(strlen(thisa->bank)+1));
      strcpy(temp, thisa->bank);
    }
    thisa = thisa->next;
  }
  while( thisb )
  {
    if(strcmp(thisb->bank_name, temp) == 0)
    {
      thisb->holdings -= withdrawal;
    }
    thisb = thisb->next;
  }
  free(temp);
}
void close_account( paccount *head_account, pbank *head_bank )
{
  paccount cur_a, prev_a = NULL;
  cur_a = *head_account;
  pbank cur_b = *head_bank;

  char *temp, c;
  int length = 0, account;
  float balance;

  /* Grab the account number */
  temp = (char *)malloc(sizeof(char));
  temp[0] = '\0';
  while((c = getc(stdin)) != '\n')
  {
    temp[length++] = c;
    temp = (char *)realloc(temp, strlen(temp)+1);
  }
  temp[length] = '\0';
  account = atoi(temp);
  free(temp);
  /* Check the list */
  while( cur_a )
  {
    if( cur_a->acc_num == account )
    {
      /* Check for head deletion */
      if( cur_a == *head_account )
      {
        free(cur_a->lname);
        free(cur_a->fname);
        free(cur_a->address);
        free(cur_a->city);
        free(cur_a->state);
        balance = cur_a->balance;
        temp = (char *)malloc(sizeof(char)*(strlen(cur_a->bank)+1));
        strcpy(temp, cur_a->bank);
        free(cur_a->bank);
        // First element
				*head_account = cur_a->next;
        free(cur_a);
				break;
      }
      else
      {
        free(cur_a->lname);
        free(cur_a->fname);
        free(cur_a->address);
        free(cur_a->city);
        free(cur_a->state);
        balance = cur_a->balance;
        temp = (char *)malloc(sizeof(char)*(strlen(cur_a->bank)+1));
        strcpy(temp, cur_a->bank);
        free(cur_a->bank);

        // Some other element
        prev_a->next = cur_a->next;
        free(cur_a);
				break;
      }
    }
    prev_a = cur_a;
    cur_a = cur_a->next;
  }
  /* Now remove the balance from the bank */
  while( cur_b )
  {
    if(strcmp(cur_b->bank_name, temp) == 0)
    {
      cur_b->holdings -= balance;
    }
    cur_b = cur_b->next;
  }
}
