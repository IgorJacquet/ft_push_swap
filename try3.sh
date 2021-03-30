printf "Programme checker - Gestion des erreurs\n"
printf "#######################################\n"

printf "\n- Lancez checker avec des paramètres non numériques. Le programme doit afficher \"Error\".\n"
printf "test 1 ./checker un 2 3 4 5 : "
printf "" | ./checker un 2 3 4 5
printf "test 2 ./checker un deux troi quarte cinq : "
printf "" | ./checker un deux troi quarte cinq


printf "\n- Lancez checker avec 2 fois le même paramètre numérique. Le programme doit afficher \"Error\".\n"
printf "test 1 ./checker 0 0 : "
printf "" | ./checker 0 0
printf "test 2 ./checker 0 1 2 3 4 5 0 : "
printf "" | ./checker 0 1 2 3 4 5 0
printf "test 3 ./checker 0 1 2 0 3 4 0 : "
printf "" | ./checker 0 1 2 0 3 4 0

printf "\n- Lancez checker avec uniquement des paramètres numériques dont l'un plus grand que MAXINT. Le programme doit afficher \"Error\".\n"
printf "test 1 ./checker 2147483647 (INTMAX doit afficher OK): "
printf "" | ./checker 2147483647
printf "test 2 ./checker 2147483648 : "
printf "" | ./checker 2147483648
printf "test 3 ./checker 99999999999999999999999999999999999999999 : "
printf "" | ./checker 99999999999999999999999999999999999999999
printf "test 4 ./checker -2147483648 (INTMIN doit afficher OK): "
printf "" | ./checker -2147483648
printf "test 5 ./checker -2147483649 : "
printf "" | ./checker -2147483649
printf "test 6 ./checker -99999999999999999999999999999999999999999 : "
printf "" | ./checker -99999999999999999999999999999999999999999

printf "\n- Lancez checker sans aucun paramètre. Le programme doit rendre la main et ne rien afficher.\n"
printf "test 1 ./checker : "
printf "" | ./checker

printf "\n- Lancez checker avec des paramètres valides, puis au moment d'entrer les insctructions à exécuter, entrez des instructions qui n'existent pas. Le programme doit afficher \"Error\".\n"
printf 'test 1 printf \"ba\\n\" | ./checker 0 1 2 3 4 5: '
printf "ba\n" | ./checker 0 1 2 3 4 5
printf 'test 2 printf \"s\\n\" | ./checker 0 1 2 3 4 5: '
printf "s\n" | ./checker 0 1 2 3 4 5
printf 'test 3 printf \"a\\n\" | ./checker 0 1 2 3 4 5: '
printf "a\n" | ./checker 0 1 2 3 4 5
printf 'test 4 printf \"rrrr\\n\" | ./checker 0 1 2 3 4 5: '
printf "rrrr\n" | ./checker 0 1 2 3 4 5
printf 'test 5 printf \"sa\" | ./checker 1 0 2 3 4 5: '
printf "sa" | ./checker 1 0 2 3 4 5

printf "\n- Lancez checker avec des paramètres valides, puis au moment d'entrer les insctructions à exécuter, entrez des instructions valides, mais précédez les et terminez les avec un ou plusieurs espaces. Le programme doit afficher \"Error\".\n"
printf 'test 1 printf \" sa\\n\" | ./checker 1 0 2 3 4 5 : '
printf " sa\n" | ./checker 0 1 2 3 4 5
printf 'test 2 printf \"sa\\n \" | ./checker 1 0 2 3 4 5 : '
printf "sa\n " | ./checker 0 1 2 3 4 5
printf 'test 3 printf \" sa\\n \" | ./checker 1 0 2 3 4 5 : '
printf " sa\n " | ./checker 0 1 2 3 4 5



printf "\n\nProgramme checker - Tests faux\n"
printf "#######################################\n"

printf "\n- Lancez checker avec la commande \"$>./checker 0 9 1 8 2 7 3 6 4 5\" puis entrez les instructions suivantes avec un formatage valide : [sa, pb, rrr]. Le programme checker doit afficher \"KO\".\n"
printf 'test 1 printf \"sa\\npb\\nrrr\\n\" | ./checker 0 9 1 8 2 7 3 6 4 5 : '
printf "sa\npb\nrrr\n" | ./checker 0 9 1 8 2 7 3 6 4 5

printf "\n- Lancez checker avec une liste de paramètres valides de votre choix, puis entrez les instructions de votre choix avec un formatage valide, mais qui ne permettent pas de trier les entiers. Le programme checker doit afficher \"KO\". Vous devez en particulier vérifier avec ce test que le programme checker n'a pas été programmé pour répondre correctement uniquement aux tests de ce barème. Vous êtes encouragés à répéter ce test avec plusieurs variantes avant de le valider.\n"
export ARG=`ruby -e "puts (-10..10).to_a.shuffle.join(' ')"`
printf "test 1 ./checker $ARG : \n"
printf "with sa\\n"
printf "sa\n" | ./checker $ARG
printf "with sb\\n"
printf "sb\n" | ./checker $ARG
printf "with ss\\n"
printf "ss\n" | ./checker $ARG
printf "with ra\\n"
printf "ra\n" | ./checker $ARG
printf "with rb\\n"
printf "rb\n" | ./checker $ARG
printf "with rr\\n"
printf "rr\n" | ./checker $ARG
printf "with rra\\n"
printf "rra\n" | ./checker $ARG
printf "with rrb\\n"
printf "rrb\n" | ./checker $ARG
printf "with rrr\\n"
printf "rrr\n" | ./checker $ARG
printf "with pa\\n"
printf "pa\n" | ./checker $ARG
printf "with pb\\n"
printf "pb\n" | ./checker $ARG




printf "\n\nProgramme checker - Tests vrais\n"
printf "#######################################\n"

printf "\n- Lancez checker avec la commande \"$>./checker 0 1 2\" puis appuyez sur ctrl+d sans entrer d'instructions. Le programme checker doit afficher \"OK\".\n"
printf 'test 1 printf \"\" | ./checker 0 1 2 : '
printf "" | ./checker 0 1 2

printf "\n- Lancez checker avec la commande \"$>./checker 0 9 1 8 2\" puis entrez les instructions suivantes avec un formatage valide : [pb, ra, pb, ra, sa, ra, pa, pa]. Le programme checker doit afficher \"OK\".\n"
printf 'test 1 printf \"pb\\nra\\npb\\nra\\nsa\\nra\\npa\\npa\\n\" | ./checker 0 9 1 8 2 : '
printf "pb\nra\npb\nra\nsa\nra\npa\npa\n" | ./checker 0 9 1 8 2

printf "\n- Lancez checker avec une liste de paramètres valides de votre choix, puis entrez les instructions de votre choix avec un formatage valide qui permettent de trier les entiers. Le programme checker doit afficher \"OK\". Vous devez en particulier vérifier avec ce test que le programme checker n'a pas été programmé pour répondre correctement uniquement aux tests de ce barème. Vous êtes encouragés à répéter ce test avec plusieurs variantes avant de le valider.\n"
printf "test 1\n"
printf 'with sa\\n in ./checker 2 1 3 : '
printf "sa\n" | ./checker 2 1
printf 'with ra\\n in ./checker 3 1 2 : '
printf "ra\n" | ./checker 3 1 2
printf 'with rra\\n in ./checker 2 3 1 : '
printf "rra\n" | ./checker 2 3 1
printf 'with pb\\npb\\nrr\\npa\\npa\\n in ./checker 2 1 4 3 : '
printf "pb\npb\nrr\npa\npa\n" | ./checker 2 1 4 3



sleep 10


printf "\n\nPush_swap - Test identité\n"
printf "#######################################\n"

printf "\n- Lancez \"$>./push_swap 42\". Le programme affiché doit être vide (0 instructions).\n"
printf "test 1 ./push_swap 42 : "
./push_swap 42
printf "\n"

printf "\n- Lancez \"$>./push_swap 0 1 2 3\". Le programme affiché doit être vide (0 instructions).\n"
printf "test 1 ./push_swap 0 1 2 3 : "
./push_swap 0 1 2 3
printf "\n"

printf "\n- Lancez \"$>./push_swap 0 1 2 3 4 5 6 7 8 9\". Le programme affiché doit être vide (0 instructions).\n"
printf "test 1 ./push_swap 0 1 2 3 4 5 6 7 8 9 : "
./push_swap 0 1 2 3 4 5 6 7 8 9
printf "\n"

sleep 10




printf "\n\nPush_swap - Version simple\n"
printf "#######################################\n"

printf "\n- Lancez \"\$>ARG=\"2 1 0\"; ./push_swap \$ARG | ./checker \$ARG\". Vérifiez que le programme checker affiche OK que la taille du programme calculé par le programme push_swap est de 2 OU 3 instructions. Sinon le test est échoué.\n"
printf "test 1 ARG=\"1 2 3\" && ./push_swap \$ARG && ./push_swap \$ARG | ./checker \$ARG:\n"
ARG="1 2 3" && ./push_swap $ARG && ./push_swap $ARG | ./checker $ARG
printf "\n"
printf "test 2 ARG=\"1 3 2\" && ./push_swap \$ARG && ./push_swap \$ARG | ./checker \$ARG:\n"
ARG="1 3 2" && ./push_swap $ARG && ./push_swap $ARG | ./checker $ARG
printf "\n"
printf "test 3 ARG=\"2 1 3\" && ./push_swap \$ARG && ./push_swap \$ARG | ./checker \$ARG:\n"
ARG="2 1 3" && ./push_swap $ARG && ./push_swap $ARG | ./checker $ARG
printf "\n"
printf "test 4 ARG=\"2 3 1\" && ./push_swap \$ARG && ./push_swap \$ARG | ./checker \$ARG:\n"
ARG="2 3 1" && ./push_swap $ARG && ./push_swap $ARG | ./checker $ARG
printf "\n"
printf "test 5 ARG=\"3 1 2\" && ./push_swap \$ARG && ./push_swap \$ARG | ./checker \$ARG:\n"
ARG="3 1 2" && ./push_swap $ARG && ./push_swap $ARG | ./checker $ARG
printf "\n"
printf "test 6 ARG=\"3 2 1\" && ./push_swap \$ARG && ./push_swap \$ARG | ./checker \$ARG:\n"
ARG="3 2 1" && ./push_swap $ARG && ./push_swap $ARG | ./checker $ARG
printf "\n"





printf "\n\nVersion toute aussi simple\n"
printf "#######################################\n"

printf "\n- Lancez \"\$>ARG=\"1 5 2 4 3\"; ./push_swap \$ARG | ./checker \$ARG\". Vérifiez que le programme checker affiche OK et que la taille du programme calculé par le programme push_swap est de 12 instructions au maximum. Sinon le test est échoué. Kudos pour la personne évaluée si la taille programme est de 8 instructions.\n"
printf "test 1 ARG=\"1 5 2 4 3\" && ./push_swap \$ARG && ./push_swap \$ARG | ./checker \$ARG:\n"
ARG="1 5 2 4 3" && ./push_swap $ARG && ./push_swap $ARG | ./checker $ARG
printf "\n"
sleep 10
printf "\n- Lancez \"\$>ARG=\"<5 params au choix>\"; ./push_swap \$ARG | ./checker \$ARG\" en remplacant le placeholder par 5 valeurs valides de votre choix. Vérifiez que le programme checker affiche OK et que la taille du programme calculé par le programme push_swap est de 12 instructions au maximum. Sinon le test est échoué. Vous devez en particulier vérifier avec ce test que le programme push_swap n'a pas été programmé pour répondre correctement uniquement aux tests de ce barème. Vous êtes encouragés à répéter ce test avec plusieurs variantes avant de le valider.\n"
moyenne=0
highest=0
for i in `seq 50`;
do
	printf "test %d\n" $i
	export ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`
	val=`./push_swap $ARG | ./checker $ARG`
	if [[ $val != 'OK' ]]
	then
		printf "%s with the the following list of args :\n" $val
		echo $ARG
		break
	fi
	num=`./push_swap $ARG | wc -l`
	if [[ $num -ge $highest ]]
	then
		highest=$num
		harg=$ARG
	fi
	moyenne=$((moyenne+num))
done
printf "the highest number of operations found is %d with the the following list of args :\n" $highest
echo $harg
printf "the average number of operations is %d\n" $((moyenne/$i))




printf "\n\nPush_swap - Version Intermédiaire\n"
printf "#######################################\n"

printf "\n- Lancez \"\$>ARG=\"<100 params au choix>\"; ./push_swap \$ARG | ./checker \$ARG\" en remplacant le placeholder par 100 valeurs valides de votre choix. Vérifiez que le programme checker affiche OK et mettez des points en fonction du nombre d'instructions effectuées:\n\
- Moins de 700: 5\n\
- Moins de 900: 4\n\
- Moins de 1100: 3\n\
- Moins de 1300: 2\n\
- Moins de 1500: 1\n\
Vous devez en particulier vérifier avec ce test que le programme push_swap n'a pas été programmé pour répondre correctement uniquement aux tests de ce barème. Vous êtes encouragés à répéter ce test avec plusieurs variantes avant de le valider.\n"
moyenne=0
highest=0
for i in `seq 1 250`;
do
	printf "test %d\n" $i
	export ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
	val=`./push_swap $ARG | ./checker $ARG`
	if [[ $val != 'OK' ]]
	then
		printf "%s with the the following list of args :\n" $val
		echo $ARG
		break
	fi
	num=`./push_swap $ARG | wc -l`
	if [[ $num -ge $highest ]]
	then
		highest=$num
		harg=$ARG
	fi
	moyenne=$((moyenne+num))
done
printf "the highest number of operations found is %d with the the following list of args :\n" $highest
echo $harg
printf "the average number of operations is %d\n" $((moyenne/$i))





printf "\n\nPush_swap - Version avancée\n"
printf "#######################################\n"

printf "\n- Lancez \"\$>ARG=\"<500 params au choix>\"; ./push_swap \$ARG | ./checker \$ARG\" en remplacant le placeholder par 500 valeurs valides de votre choix (on vous appelle pas Jean(ne)-Michel(le) Script pour rien). Vérifiez que le programme checker affiche OK et mettez des points en fonction du nombre d'instructions effectuées:\n\
- Moins de 5500: 5\n\
- Moins de 7000: 4\n\
- Moins de 8500: 3\n\
- Moins de 10000: 2\n\
- Moins de 11500: 1\n\
Vous devez en particulier vérifier avec ce test que le programme push_swap n'a pas été programmé pour répondre correctement uniquement aux tests de ce barème. Vous êtes encouragés à répéter ce test avec plusieurs variantes avant de le valider.\n"
moyenne=0
highest=0
for i in `seq 1 1000`;
do
	printf "test %d\n" $i
	export ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
	val=`./push_swap $ARG | ./checker $ARG`
	if [[ $val != 'OK' ]]
	then
		printf "%s with the the following list of args :\n" $val
		echo $ARG
		break
	fi
	num=`./push_swap $ARG | wc -l`
	if [[ $num -ge $highest ]]
	then
		highest=$num
		harg=$ARG
	fi
	moyenne=$((moyenne+num))
done
printf "the highest number of operations found is %d with the the following list of args :\n" $highest
echo $harg
printf "the average number of operations is %d\n" $((moyenne/$i))