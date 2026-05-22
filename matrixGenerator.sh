#/bin/sh
set +B
var1="{"
var2="},"
set -B
var4=","
for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 1 2 3 4 5 6 7 8 9 1 5 4 5 6 7 8 9; do
		echo -n $var1 >> outFile.txt;
		for j in 1 2 3 4 5 6 7 8 9 10 11 12 11 10 9 8 7 6 5 4 3 2 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1 1 2 3 5 4 6 7 8 9; do
			var3=`echo $i*$j*$RANDOM*0.001 | bc`
			echo -n $var3 >> outFile.txt;
#			if [$j -ne $var5]; then
				echo -n $var4 >> outFile.txt;
#			fi
		done
		var5=`echo $i*$RANDOM*0.01 | bc`
		echo -n $var5 >> outFile.txt;
		echo $var2 >> outFile.txt;
done


