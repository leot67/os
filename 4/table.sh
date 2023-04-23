read -p "Enter table : " a
for x in 1 2 3 4 5 6 7 8 9 10 
do
p=`expr $x \* $a`
echo "$p"
sleep 1
done

