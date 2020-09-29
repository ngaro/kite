#This can (and should) be rewritten to be smaller and faster,
#but it's good for a v0.1 (because it works)
FROM ubuntu:20.04
RUN apt-get update && apt-get -y install cmake g++ git \
python3-distutils python3-numpy python3-dev \
libhdf5-dev libeigen3-dev
WORKDIR /root
RUN git clone https://github.com/ngaro/kite.git && cd kite && \
git checkout fixbrokenbuild && cmake . && make all
