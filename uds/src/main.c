/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2017 Vladimir Roncevic <elektron.ronca@gmail.com>
 *
 * uds is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * uds is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "uds.h"
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

static const char *program_name;

static const struct option long_options[] = {
	{"socket", 0, NULL, 's'},
	{"message", 0, NULL, 'm'},
	{"help", 0, NULL, 'h'},
	{"version", 0, NULL, 'V'},
	{0, 0, 0, 0}
};

int main(int argc, char *argv[]) {
	int fd, opt, index;
	char *socket_path = NULL;
	char *message = NULL;
	struct sockaddr_un addr;

	program_name = argv[0];
	while((opt = getopt_long(argc, argv, "h:v:s:m:", long_options, &index)) != EOF) {
		switch(opt) {
			case 's':
				socket_path = optarg;
				break;
			case 'm':
				message = optarg;
				break;
			case 'h':
				UDS_USAGE(program_name);
				exit(0);
				break;
			case 'V':
				UDS_VERSION(program_name);
				exit(0);
				break;
			default:
				UDS_USAGE(program_name);
				exit(-1);
				break;
		}
	}
	if(check_socket(socket_path) == -1) {
		exit(-1);
	}
	if((fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		exit(-1);
	}
	memset(&addr, 0, sizeof(addr));
	addr.sun_family = AF_UNIX;
	if(*socket_path == '\0') {
		*addr.sun_path = '\0';
		strncpy(addr.sun_path + 1, socket_path + 1, sizeof(addr.sun_path) - 2);
	} else {
		strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);
	}
	if(connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
		exit(-1);
	}
	write(fd, message, strlen(message));
	return (0);
}

