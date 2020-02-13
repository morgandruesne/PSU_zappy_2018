/*
** EPITECH PROJECT, 2018
** NWP_client_ftp
** File description:
** include/client.h
*/


#ifndef CLIENT_H_
    #define CLIENT_H_

    #include <sys/ioctl.h>
    #include <net/if.h>
    #include <errno.h>
    #include <netdb.h>
    #include <netinet/in.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <ifaddrs.h>
    #include <stdio.h>
    #include <sys/time.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <sys/select.h>
    #include <fcntl.h>
    #include <string>
    #include <iostream>
    #include <pthread.h>
    #include <thread>
    #include <future>
    #include <vector>

    typedef struct control_s {
        int socket_fd;
        int socket_serv;
        int socket_data;
        char *ip;
        struct sockaddr_in addr;
        std::vector<std::string> tbl;
    } control_t;

    void *server_read(control_t *control);

#endif
