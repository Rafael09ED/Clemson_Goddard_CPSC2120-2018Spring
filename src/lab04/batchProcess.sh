for j in 4 6 8 10 15 20 25 30 40 50 60 70 80 90 100 125 150 175 200
do
	printf "$j \t"
done
printf "\n"

for i in 1 2 3 4 5
do
	for j in 4 6 8 10 15 20 25 30 40 50 60 70 80 90 100 125 150 175 200
	do

		OUT=$(java TimeSink $i $j)
		printf "${OUT} \t"
	done
	printf "\n"
done
	  