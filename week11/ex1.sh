#!/usr/bin/bash

fsname='newDisc'

#!/usr/bin/bash

fallocate -l 50M $fsname.img
sudo losetup -f $fsname.img
mkfs.ext4 $fsname.img
mkdir $fsname
sudo mount $fsname.img $fsname
