#!/usr/bin/env python3

import socket
import sys
import time
import random
import os


class Player:
    def check_return(self, ret, action):
        if (ret == "ko\n"):
            print(action + " failed", file=sys.stderr)
        elif (ret == "dead\n"):
            print("I'm dead, oops", file=sys.stderr)
            sys.exit(0)
        elif (ret[:7] == "message"):
            print("Message: {" + ret + "}")
            return (self.check_return(self.get_message(), action))
        elif (ret[:5] == "eject"):
            print("Eject: " + ret[7])
            return (self.check_return(self.get_message(), action))
        return ret

    def send_message(self, string):
        string += "\n"
        self.sock.send(string.encode('utf-8'))

    def get_message(self):
        return self.sock.recv(BUFFER_SIZE).decode("utf-8")

    def move_forward(self):
        self.send_message("Forward")
        self.check_return(self.get_message(), "Forward")

    def move_left(self):
        self.send_message("Left")
        ret = self.check_return(self.get_message(), "Left")
        if (ret != "ko\n"):
            self.move_forward()

    def move_right(self):
        self.send_message("Right")
        ret = self.check_return(self.get_message(), "Right")
        if (ret != "ko\n"):
            self.move_forward()

    def move_backward(self):
        self.send_message("Right")
        ret = self.check_return(self.get_message(), "Left")
        if (ret != "ko\n"):
            self.send_message("Right")
            ret = self.check_return(self.get_message(), "Left")
            if (ret != "ko\n"):
                self.move_forward()

    def look_around(self):
        self.send_message("Look")
        ret = self.check_return(self.get_message(), "Look")
        if (ret != "ko\n"):
            ret = ret[1:-2]
            tab = ret.split(',')
            res = []
            i = 0
            while (i < len(tab)):
                cell = {
                    'player': tab[i].count('player'),
                    'linemate': tab[i].count('linemate'),
                    'deraumere': tab[i].count('deraumere'),
                    'sibur': tab[i].count('sibur'),
                    'mendiane': tab[i].count('mendiane'),
                    'phiras': tab[i].count('phiras'),
                    'thystame': tab[i].count('thystame'),
                    'food': tab[i].count('food')
                }
                res.append(cell)
                i += 1
            return (res)
        else:
            return ([])

    def get_inventory(self):
        self.send_message("Inventory")
        ret = self.check_return(self.get_message(), "Inventory")
        if (ret != 'ko\n'):
            ret = ret[1:-2]
            tab = ret.split(',')
            self.inventory = {
                'food': int(tab[0].split()[1]),
                'linemate': int(tab[1].split()[1]),
                'deraumere': int(tab[2].split()[1]),
                'sibur': int(tab[3].split()[1]),
                'mendiane': int(tab[4].split()[1]),
                'phiras': int(tab[5].split()[1]),
                'thystame': int(tab[6].split()[1]),
            }

    def collect(self, toCollect):
        self.send_message("Take " + toCollect)
        ret = self.check_return(self.get_message(), "Collect " + toCollect)

    def drop(self, toDrop):
        self.send_message("Set " + toDrop)
        self.check_return(self.get_message(), "Drop " + toDrop)

    def broadcast(self, text):
        self.send_message("Broadcast " + text)
        ret = self.check_return(self.get_message(), "Broadcast")

    def elevation(self):
        self.send_message("Incantation")
        ret = self.check_return(self.get_message(), "Elevation")
        ret = self.check_return(self.get_message(), "Level")
        if (ret != "ko\n"):
            print("Level UP " + str(int(ret[14:]) - 1) + " success")
            self.level = int(ret[14:]) - 1

    def fork(self):
        self.send_message("Fork")
        ret = self.check_return(self.get_message(), "Fork")
        if (ret != "ko\n"):
            newpid = os.fork()
            if newpid == 0:
                play()
                sys.exit(0)
            else:
                return
        return

    def __init__(self):
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.level = 0
        self.inventory = {
            'food': 0,
            'linemate': 0,
            'deraumere': 0,
            'sibur': 0,
            'mendiane': 0,
            'phiras': 0,
            'thystame': 0,
        }

TCP_IP = "localhost"
TCP_PORT = 0
BUFFER_SIZE = 2048
TeamName = ""
nbPlayer = 0

ingredients = ['player', 'linemate', 'deraumere','sibur','mendiane','phiras','thystame']

tab_elevation = [
    [1, 1, 0, 0, 0, 0, 0],
    [2, 1, 1, 1, 0, 0, 0],
    [2, 2, 0, 1, 0, 2, 0],
    [4, 1, 1, 2, 0, 1, 0],
    [4, 1, 2, 1, 3, 0, 0],
    [6, 1, 2, 3, 0, 1, 0],
    [6, 2, 2, 2, 2, 2, 1],
]

def display_help():
    print("USAGE: ./zappy_ai -p port -n name -h machine\n\tport is the port number\n\tname is the name of the team\n\tmachine is the name of the machine; localhost by default", file=sys.stderr)

def arg_parser():
    global TCP_IP
    global TCP_PORT
    global TeamName
    i = 1
    while (i < len(sys.argv)):
        if (sys.argv[i] == "-help"):
            display_help()
            sys.exit(0)
        elif (sys.argv[i] == "-p"):
            i += 1
            TCP_PORT = int(sys.argv[i])
        elif (sys.argv[i] == "-n"):
            i += 1
            TeamName = sys.argv[i]
        elif (sys.argv[i] == "-h"):
            i += 1
            TCP_IP = str(sys.argv[i])
        else:
            display_help()
            sys.exit(84)
        i += 1
    if (TCP_PORT < 0):
        sys.exit(84)


def clear_cell(player):
    i = 1
    while (i < len(ingredients)):
        while ((player.look_around())[0][ingredients[i]] != 0):
            player.collect(ingredients[i])
        i += 1


def drop_all(player):
    i = 1
    while (i < len(ingredients)):
        j = 0
        while (j < tab_elevation[player.level][i]):
            player.drop(ingredients[i])
            j += 1
        i += 1


def find_and_go(toFind, player):
    vision = player.look_around()
    i = 0
    while (i < len(vision)):
        if (vision[i][toFind] != 0):
            break
        i += 1
    j = 0
    k = 0
    add = 3
    if (i < len(vision)):
        while (k < i):
            j += (add - 1)
            k += add
            add += 2
        while (add != 3):
            player.move_forward()
            add -= 2
        while (i != j):
            if (j > i):
                j -= 1
                player.move_left()
            else:
                j += 1
                player.move_right()
        return (1)
    else:
        direct = random.randint(0, 3)
        if (direct == 0):
            player.move_forward()
        elif (direct == 1):
            player.move_left()
        elif (direct == 2):
            player.move_right()
        else:
            player.move_backward()
        return (0)


def collect_all(player):
    i = 1
    player.get_inventory()
    while (i < len(ingredients)):
        while (player.inventory[ingredients[i]] < tab_elevation[player.level][i]):
            if (find_and_go(ingredients[i], player) == 1):
                player.collect(ingredients[i])
            player.get_inventory()
            if (player.inventory["food"] < 20):
                if (find_and_go("food", player) == 1):
                    player.collect("food")
                player.get_inventory()
        i += 1


def main(player):
    while (1):
        collect_all(player)
        clear_cell(player)
        if (tab_elevation[player.level][0] > nbPlayer):
            player.fork()
        drop_all(player)
        player.get_inventory()
        player.elevation()


def play() :
    try:
        global nbPlayer
        player = Player()
        player.sock.connect((TCP_IP, TCP_PORT))
        print ("Welcome:", player.get_message()[:-1])
        print("Team Name:", TeamName)
        player.send_message(TeamName)
        data = player.get_message()
        if (data == 'ko\n'):
            sys.exit(84)
        clients = int(data[:data.find("\n")])
        sizeX = int(data[data.find("\n") + 1:data.find("\n") + 3])
        sizeY = int(data[data.find("\n") + 4:])
        print("Clients restants:", clients)
        print("Width:", sizeX)
        print("Height:", sizeY)
        if (clients >= 1):
            nbPlayer += 1
            main(player)
        player.sock.close()
        sys.exit(0)
    except:
        sys.exit(84)

if (__name__ == "__main__"):
    try:
        arg_parser()
    except:
        sys.exit(84)
    play()
    sys.exit(0)
