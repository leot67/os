echo -n "Enter letter : "
read ab 
case $ab in a|e|i|o|u) echo "vowel";; 
*) echo "constant"
esac
