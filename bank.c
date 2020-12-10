/*
    Project 3
    ENEE150 Fall 2020
    Joseph M Krzyzek
*/

#include "bank.h"

int main( void )
{

  pbank head_bank = NULL;
  paccount head_account = NULL;
  int id = 0;

  while( id != 1 )
  {
    scanf("%d\n", &id);
    switch( id )
    {
      case 1 :
        break;
      case 2 :
        new_bank( &head_bank );
        break;
      case 3 :
        print_bank( &head_bank );
        break;
      case 4 :
        new_account( &head_account );
        break;
      case 5 :
        print_account( &head_account );
        break;
      case 6 :
        deposit( &head_account, &head_bank );
        break;
      case 7 :
        withdrawal( &head_account, &head_bank );
        break;
      case 8 :
        close_account( &head_account, &head_bank );
        break;
      default :
         id = 1;
         break;
    }
  }
  return(0);
}
