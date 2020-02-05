#!/bin/bash

player1=champs/Bazou.cor
player2=champs/lou_forktologue.cor
player3=champs/
player4=champs/

for (( a = 1; a < 10000; a++))
do
./corewar -dump $a $player2 > my_var
./corewar_ex -d $a $player2 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
echo "$a"
cat 1
break
fi
done
echo "my variant\n"
cat my_var
echo "\nexample variant\n"
cat example_var

