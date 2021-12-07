FROM ubuntu:focal
LABEL maintainer="https://github.com/pygsl/pygsl"

ENV TERM=xterm \
    TZ=Europe/Berlin \
    DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential libtool automake autotools-dev \
    nano \
    swig \
    libgsl-dev \
    python3-dev \
    python3-ipython \
    python3-matplotlib \
    python3-numpy \
    python3-pip \
    python3-scipy \
    python3-setuptools \
    cmake wget git curl && \
    rm -rf /var/lib/apt/lists/* && \
    update-alternatives --install /usr/bin/python python /usr/bin/python3 10 && \
    update-alternatives --install /usr/bin/pip pip /usr/bin/pip3 10

RUN python3 -m pip install --upgrade pip setuptools wheel pytest
#RUN python3 -m pip install --index-url https://test.pypi.org/simple/ pygsl
RUN python3 -m pip install pygsl

# add user 'user'
RUN adduser --disabled-login --gecos 'USER' --home /home/user user && \
    chown user:user /home/user

# copy entrypoint to user home folder
COPY entrypoint.sh /home/user
RUN chown user:user /home/user/entrypoint.sh && \
    chmod +x /home/user/entrypoint.sh

WORKDIR /home/user
USER user
ENTRYPOINT ["/home/user/entrypoint.sh"]
