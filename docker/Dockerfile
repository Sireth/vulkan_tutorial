FROM ubuntu:24.04

ARG PASSWORD
ARG KEY
ARG PATH_TO_KEYS

RUN apt-get update && apt-get install -y --no-install-recommends


RUN apt-get update && apt-get install -y openssh-server
RUN mkdir /var/run/sshd
RUN echo 'root:${PASSWORD}' | chpasswd
RUN sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -i 's/#PermitRootLogin yes/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -i 's/#PasswordAuthentication yes/PasswordAuthentication yes/' /etc/ssh/sshd_config
RUN sed -i 's/#PubkeyAuthentication yes/PubkeyAuthentication yes/' /etc/ssh/sshd_config
RUN sed -i 's/#PermitUserEnvironment no/PermitUserEnvironment yes/' /etc/ssh/sshd_config

# SSH login fix. Otherwise user is kicked off after login
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

ENV NOTVISIBLE "in users profile"
RUN echo "export VISIBLE=now" >> /etc/profile

EXPOSE 22

COPY ${PATH_TO_KEYS}/${KEY} /root/.ssh/${KEY}

COPY ${PATH_TO_KEYS}/${KEY}.pub /root/.ssh/authorized_keys
RUN chmod 600 /root/.ssh/authorized_keys

RUN apt-get update && apt-get install -y \
    gcc \
    g++ \
    ninja-build \
    cmake \
    rsync

RUN apt-get install -y valgrind

RUN apt install -y  \
    vulkan-tools \
    libvulkan-dev \
    vulkan-utility-libraries-dev \
    spirv-tools \
    vulkan-validationlayers

RUN apt install -y \
    libglfw3-dev \
    libglm-dev \
    glslc

RUN apt install -y \
    libxxf86vm-dev \
    libxi-dev

RUN env > /root/.ssh/environment

COPY ./docker/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh


ENTRYPOINT ["/entrypoint.sh"]