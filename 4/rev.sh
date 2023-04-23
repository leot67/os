echo -n "enter number"
read n
s=0
while [ $n -gt 0 ]
do 
 rem=`expr $n % 10`
 s=`expr $s \* 10 + $rem`
 n=`expr $n / 10`
done
echo "$s "






