#!/bin/csh


gcc -o bank bank.c functions.c
for i in 1 2 3 4 5
do
  echo "*** test$i ***"
  xact_driver $i | bank >! bank$i.out
  diff bank$i.out test$i.out
  echo "\n\n\n"
done
