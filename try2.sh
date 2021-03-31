moyenne=0
ntest=10000
highest=0
for i in `seq 1 $ntest`;
do
	echo "test " $i "\n"
	export ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`
	val=`./push_swap $ARG | ./checker $ARG`
	if [[ $val = 'KO' ]]
	then
		echo $val
		echo "args are:"
		echo $ARG
		break
	fi
	num=`./push_swap $ARG | wc -l`
	if [[ $num -ge $highest ]]
	then
		highest=$num
		harg=$ARG
	fi
	if [[ $num -ge 700 ]]
	then
		break
	fi
	moyenne=$((moyenne+num))
done
echo "the highest number of operations found is " $highest " with the the following list of args"
echo $harg
echo "the average number of operations is " $((moyenne/$i))