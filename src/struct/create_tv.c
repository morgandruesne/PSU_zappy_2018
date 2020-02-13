/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** create_tv
*/

#include "../../include/server.h"

struct timeval create_tv(void)
{
    struct timeval tv;

    tv.tv_sec = 1;
    tv.tv_usec = 1000;
    return (tv);
}