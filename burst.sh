export px4="%"

file="/home/mbw29/burst.sh"

if ! [ "$1" == "" ]; then

split=$1

echo $split

else 

split=500
echo $split
fi


while [IFS= read -r line] && [count < split]
do
count + = 1;
echo "$line"
write file.txt $line;
done <"$file"
