echo -n "Enter two numbers : " 
read a b
echo -n "1.add 2.sub .3.mul .4.div "
read option
case $option in
	1) c=`expr $a + $b` 
	echo "$c";;
	2) c=`expr $a - $b` 
	echo "$c";;
	3) c=`expr $a \* $b` 
	echo "$c";;
	4) c=`expr $a / $b` 
	echo "$c";;
	*) echo "Invalid option" 
esac



