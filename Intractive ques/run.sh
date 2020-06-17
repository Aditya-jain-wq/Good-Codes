n=5
while [ $n -gt 0 ]
do
	python3 interactive_runner.py python3 judge.py -- ./covidsmpl
	n=`expr $n - 1`
	echo $n
done
echo "done it 100 times"