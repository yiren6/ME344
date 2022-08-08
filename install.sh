#!/bin/bash -l


# install SU2
cd /usr/local/SU2
./meson.py build -Dwith-mpi=enabled --prefix=/usr/local/SU2
cd /usr/local/SU2
./ninja -C build install

echo "-----------------------------"
echo "||| SU2 install completed! |||"
echo "-----------------------------"


# install tetgen

cd /usr/local/tetgen
make

echo "-------------------------------"
echo "|||tetgen install completed!|||"
echo "-------------------------------"



# config ESP

cd /usr/local/ESP/EngSketchPad/config
./makeEnv /usr/local/ESP/OpenCASCADE-7.4.1

# compile and install ESP
cd /usr/local/ESP/EngSketchPad/src
make


echo "-----------------------------"
echo "||| ESP install completed! |||"
echo "-----------------------------"

exit
