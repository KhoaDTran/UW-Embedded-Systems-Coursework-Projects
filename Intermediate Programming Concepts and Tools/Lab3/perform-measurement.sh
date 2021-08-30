#Khoa Tran
#CSE 374 Homework 3
#Problem 2
#04/26/2020

if [ $# -lt 1 ]
then
   echo "Takes one argument: URL"
   exit 1
fi

ERROROUT=$(mktemp 2> /dev/null)

wget -t 1 -T 5 -o /dev/null -O "$ERROROUT" "$1" || { echo "0"; rm "$ERROROUT" 2> /dev/null; exit 2;}

wc -c < "$ERROROUT" || { echo "0"; rm "$ERROROUT" 2> /dev/null; exit 2;}

rm "$ERROROUT"

exit 0
