#!/usr/bin/bash

fsname='newDisc'

mkdir -p $fsname/bin
mkdir -p $fsname/lib64
mkdir -p $fsname/usr/lib
mkdir -p $fsname/usr/lib64
cp /bin/bash $fsname/bin
ldd /bin/bash | awk '{print $3}' | xargs -I {} cp -v {} $fsname{}
cp $fsname/usr/lib/* $fsname/lib
cp $fsname/usr/lib64/* $fsname/lib64
echo Egor > $fsname/file1
echo Dmitriev > $fsname/file2
gcc ex2.c -o ex2.out
cp ex2.out $fsname
sudo chroot $fsname /ex2.out > ex2.txt
./ex2.out >> ex2.txt
