INDEX=$1
i=0
re='^[0-9]+$'
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'


if [ "$INDEX" -gt "0" ];
then
    INDEX="$(($INDEX-1))"
fi

if ! [[ $INDEX =~ $re ]] ; then
   echo "Please insert a valid number after bash ./tester.sh" >&2; exit 1
fi

rm output.txt

while [ $i -le 10 ]
do
	ARG=`ruby -e "puts (0..$INDEX).to_a.shuffle.join(' ')"`; echo $ARG >> output.txt ; ../a.out $ARG | ../checkers/checker_linux $ARG >> output.txt; ../a.out $ARG | wc -l >> output.txt
  ((i++))
done

cat ./output.txt | grep -q KO

empty="$?"

INDEX="$(($INDEX+1))"

if [[ $empty == *"1"* ]];
then
  echo -e "Sorting with $INDEX numbers${GREEN} PASSED!${NC}"
else
  echo -e "Sorting with $INDEX numbers${RED} FAILED! ${NC}"
fi



