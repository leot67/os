read -p "Enter three numbers with space : " a b c
if [ $a -gt $b -a $a -gt $c ]
then 
	echo " A is big "
elif [ $b -gt $c ]
then 
	echo "B is big"
else 
	echo "C is big"
fi

