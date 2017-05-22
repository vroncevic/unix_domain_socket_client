/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * uds.h
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
#ifndef __UDS_H
#define __UDS_H

#include <stdio.h>

#define VERSION "v0.1"

#define UDS_VERSION(PROGRAM_NAME) \
	fprintf(stdout, "%s version %s\n", PROGRAM_NAME, VERSION);

#define UDS_USAGE(PROGRAM_NAME) \
		fprintf( \
			stdout, \
			"%s version %s\n" \
			"Usage: %s [options]\n" \
			"  -s  --socket     Socket path\n" \
			"  -m  --message    Message to send\n" \
			"  -h  --help       Display this text\n" \
			"  -V  --version    Display version\n" \
			"Example:\n" \
			"%s -s socket_file -m hello\n", \
			PROGRAM_NAME, VERSION, PROGRAM_NAME, PROGRAM_NAME \
		);

int check_socket(char *socket_path);

#endif

