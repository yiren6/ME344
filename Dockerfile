FROM ubuntu:20.04
ENV LANG C.UTF-8
RUN ln -fs /usr/share/zoneinfo/UTC /etc/localtime
RUN DEBIAN_FRONTEND=noninteractive apt update && apt install -y \
	apt-utils \
	python3 \
	pkg-config \
	python3-pip \
	git \
	build-essential \
	python3-numpy \
	python3-scipy \
	python3-mpi4py \
	swig \
	libopenmpi-dev \
	openmpi-bin \
	ccache \
	vim

COPY SU2 /usr/local/SU2
COPY ESP121 /usr/local/ESP
COPY tetgen /usr/local/tetgen
COPY install.sh /install.sh
COPY testCase /usr/local/testCase
COPY runsim.sh /runsim.sh

RUN ["echo","Hello"]
RUN ["chmod","+x","/install.sh"]
RUN ["chmod","+x","/runsim.sh"]

ENV PATH=/usr/local/ESP/EngSketchPad/bin:/usr/local/SU2/bin:/usr/local/tetgen:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
ENV PYTHONPATH=/usr/lib/python3.8:/usr/local/SU2/bin:/usr/local/ESP/EngSketchPad/pyESP
ENV SU2_RUN=/usr/local/SU2/bin
ENV SU2_HOME=/usr/local/SU2
ENV TETGEN=/usr/local/tetgen
ENV ESP_ARCH=LINUX64
ENV ESP_ROOT=/usr/local/ESP/EngSketchPad
ENV CASROOT=/usr/local/ESP/OpenCASCADE-7.4.1
ENV CASARCH=Linux
ENV CASREV=7.4
ENV PYTHONINC=/usr/include/python3.8
ENV PYTHONLIB="-L/usr/lib/python3.8/config-3.8-x86_64-linux-gnu -lpython3.8"
ENV EFCOMP=gfortran
ENV LD_LIBRARY_PATH=/usr/local/ESP/OpenCASCADE-7.4.1/Linux/lib:/usr/local/ESP/EngSketchPad/lib
ENV UDUNITS2_XML_PATH=/usr/local/ESP/EngSketchPad/src/CAPS/udunits/udunits2.xml
ENV CAPS_GLYPH=/usr/local/ESP/EngSketchPad/src/CAPS/aim/pointwise/glyph


RUN ["chmod", "+x","/install.sh"] 
RUN ["/install.sh"]


ENTRYPOINT [ "/bin/bash", "-l", "-c" ]


#RUN ["source","/.bashrc"]
#RUN ["chmod", "+x","/install.sh"] remove 

