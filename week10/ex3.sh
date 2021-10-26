if [[ ! -f _ex3.txt ]];then
	echo Egor Dmitriev 3 >> _ex3.txt
fi
chmod -111 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod +707 _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g=u _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo 660 means rw-rw--- >> ex3.txt
echo 775 means rwxrwxr-x >> ex3.txt
echo 777 means rwxrwxrwx >> ex3.txt
