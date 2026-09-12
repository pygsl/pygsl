#!/bin/sh

DSC=https://archive.ubuntu.com/ubuntu/pool/universe/s/swig/swig_4.5.0-3.dsc
ORIG=https://archive.ubuntu.com/ubuntu/pool/universe/s/swig/swig_4.5.0.orig.tar.gz
DEB_PATH=https://archive.ubuntu.com/ubuntu/pool/universe/s/swig/swig_4.5.0-3.debian.tar.xz

save_path=$(pwd)
mkdir -p build/swig-4.5
cd build/swig-4.5

curl -O -s $DSC || echo "Failed to download dsc package"
curl -O -s $ORIG
curl -O -s $DEB_PATCH

cd "$save_path"
tar -cvf swig-4.5_ubuntu_src.tar -C build swig-4.5
