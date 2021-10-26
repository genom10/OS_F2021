if [[ ! -f ../week1/file.txt ]];then
	mkdir ../week1
	echo Egor Dmitriev 2 >> ../week1/file.txt
fi
link ../week1/file.txt _ex2.txt
inodenumber=$(ls -i _ex2.txt | awk '{print $1;}')
find . -inum $inodenumber >> ex2.txt
find . -inum $inodenumber -exec rm {} \; >> ex2.txt
