#!/bin/sh

DSC=http://archive.ubuntu.com/ubuntu/pool/universe/s/swig/swig_4.4.0-1.dsc
ORIG=http://archive.ubuntu.com/ubuntu/pool/universe/s/swig/swig_4.4.0.orig.tar.gz
DEB_PATCH=http://archive.ubuntu.com/ubuntu/pool/universe/s/swig/swig_4.4.0-1.debian.tar.xz

save_path=$(pwd)
mkdir -p build/swig-4.4
cd build/swig-4.4

curl -O -s $DSC || echo "Failed to download dsc package"
curl -O -s $ORIG
curl -O -s $DEB_PATCH

cd "$save_path"
tar -cvf swig-4.4_ubuntu_src.tar -C build swig-4.4
