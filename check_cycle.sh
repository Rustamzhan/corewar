#!/bin/bash

player=(champs/Bazou.cor champs/echo.cor champs/Eraser.cor \
champs/fast.cor champs/ForgottenOne.cor champs/Hidden.cor \
champs/Horace.cor champs/Izi_Miaou.cor champs/kamelkaze.cor \
champs/katchup.cor champs/Kitty_Miaou.cor champs/lapsang.cor \
champs/le_pet_de_nonne.cor champs/lou_forktologue.cor \
champs/master_of_puppets.cor champs/O-Maley_Miaou.cor \
champs/pai_mu_tan.cor champs/sencha.cor champs/Stargate0_1.cor \
champs/tchupka.cor champs/TheHarvester.cor champs/wave.cor)

for player1 in ${player[@]}; do
for ((a = 0; a < 10000; a++ ))
do
./corewar -dump $a $player1 > my_var
./corewar_ex -d $a $player1 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
echo "$a"
cat 1
break
fi
done
echo "__________________________________________________\n"
echo "\n\n\n"
done

