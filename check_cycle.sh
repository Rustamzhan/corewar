#!/bin/bash

player=(champs/Bazou.cor champs/Eraser.cor champs/lapsang.cor champs/echo.cor\
champs/Horace.cor champs/Izi_Miaou.cor  champs/Hidden.cor\
champs/katchup.cor champs/Kitty_Miaou.cor champs/fast.cor\
champs/le_pet_de_nonne.cor champs/lou_forktologue.cor \
champs/master_of_puppets.cor  \
champs/pai_mu_tan.cor champs/sencha.cor \
champs/tchupka.cor champs/TheHarvester.cor )

for player1 in ${player[@]}; do
for player2 in ${player[@]}; do
for player3 in ${player[@]}; do
for player4 in ${player[@]}; do
echo -n "$player1 vs $player2 vs $player3 vs $player4"
./corewar $player1 $player2 $player3 $player4 > my_var
./corewar $player1 $player2 $player3 $player4 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
echo -e "\033[31m ✖ \033[0m"
echo "$a"
cat 1
break
fi
echo -e "\033[32m ✓ \033[0m"
done
done
done
echo -e "__________________________________________________\n"
done

