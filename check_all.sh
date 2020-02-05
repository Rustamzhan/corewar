#!/bin/bash

player1=champs/Bazou.cor
player2=champs/echo.cor
player3=champs/Eraser.cor
player4=champs/fast.cor
player5=champs/ForgottenOne.cor
player6=champs/Hidden.cor
player7=champs/Horace.cor
player8=champs/Izi_Miao.cor
player9=champs/kamelkaze.cor
player10=champs/katchup.cor
player11=champs/Kitty_Miaou.cor
player12=champs/lapsang.cor
player13=champs/le_pet_de_nonne.cor
player14=champs/lou_forktologue.cor
player15=champs/master_of_puppets.cor
player16=champs/O-Maley_Miaou.cor
player17=champs/pai_mu_tan.cor
player18=champs/sencha.cor
player19=champs/Stargate0_1.cor
player20=champs/tchupka.cor
player21=champs/TheHarvester.cor
player22=champs/wave.cor

./corewar $player1 $player2 > my_var
./corewar_ex $player1 $player2 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player2 $player3 > my_var
./corewar_ex $player2 $player3 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player3 $player4 > my_var
./corewar_ex $player3 $player4 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player4 $player5 > my_var
./corewar_ex $player4 $player5 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player5 $player6 > my_var
./corewar_ex $player5 $player6 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
echo "$a"
cat 1
break
fi

./corewar $player6 $player7 > my_var
./corewar_ex $player6 $player7 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
echo "$a"
cat 1
break
fi

./corewar $player7 $player8 > my_var
./corewar_ex $player7 $player8 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player8 $player9 > my_var
./corewar_ex $player8 $player9 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player9 $player10 > my_var
./corewar_ex $player9 $player10 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player10 $player11 > my_var
./corewar_ex $player10 $player11 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
echo "$a"
cat 1
break
fi

./corewar $player11 $player12 > my_var
./corewar_ex $player11 $player12 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player12 $player13 > my_var
./corewar_ex $player12 $player13 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player13 $player14 > my_var
./corewar_ex $player13 $player14 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player14 $player15 > my_var
./corewar_ex $player14 $player15 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player15 $player16 > my_var
./corewar_ex $player15 $player16 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player16 $player17 > my_var
./corewar_ex $player16 $player17 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player17 $player18 > my_var
./corewar_ex $player17 $player18 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi
done

./corewar $player18 $player19 > my_var
./corewar_ex $player18 $player19 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player119 $player20 > my_var
./corewar_ex $player19 $player20 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player20 $player21 > my_var
./corewar_ex $player20 $player21 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi

./corewar $player21 $player22 > my_var
./corewar_ex $player21 $player22 > example_var
diff my_var example_var > 1
if [ -s 1 ]
then
cat 1
break
fi
