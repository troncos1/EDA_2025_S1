FROM ubuntu:22.04

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y tzdata
RUN apt-get install -y vim build-essential git cmake net-tools gdb clang
RUN apt-get install nano -y
RUN apt-get install git
RUN apt-get install make 
#RUN apt-get install libcurl4-gnutls-dev libexpat1-dev gettext \libz-dev libssl-dev
#RUN git clone git://git.kernel.org/pub/scm/git/git.git
# RUN apt-get install libreria

WORKDIR /work 
# COPY main.c . 
# RUN gcc main.c -o main
# RUN ./main 


# comandos:
# crear imagen a partir de un dockerfile
# docker build -t testj1 . 
# crear un container a partir de la imagen, con dirección específica 
# docker run --name ubuntu -v "C:\Users\jorge\OneDrive\Documentos\codes\vscode_docker-1:/work" -it testj1
# ejecutar el entorno se usa el nombre del container
# docker exec -it ubuntu bash