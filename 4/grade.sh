read -p"Enter Mark : " a

if [ $a -ge 91 ] 
then
	echo "O grade"
elif [ $a -ge 81 ] 
then
	echo "A grade"
elif [ $a -ge 71 ] 
then
	echo "B grade"
elif [ $a -ge 61 ] 
then
	echo "C grade"
else 
	echo "fail"
fi


