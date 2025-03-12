#!/bin/sh

DSC=http://archive.ubuntu.com/ubuntu/pool/universe/s/swig/swig_4.3.0-0ubuntu2.dsc
ORIG=http://archive.ubuntu.com/ubuntu/pool/universe/s/swig/swig_4.3.0.orig.tar.gz
DEB_PATCH=http://archive.ubuntu.com/ubuntu/pool/universe/s/swig/swig_4.3.0-0ubuntu2.debian.tar.xz

save_path=$(pwd)
mkdir -p build/swig4.3
cd build/swig4.3

curl -O -s $DSC
curl -O -s $ORIG
curl -O -s $DEB_PATCH

cd "$save_path"
tar -cvf swig4.3_ubuntu_src.tar -C build swig4.3
