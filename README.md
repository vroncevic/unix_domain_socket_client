# Unix Domain Socket Client (Bash command)

The README is used to introduce the tool and provide instructions on
how to install the tool, any machine dependencies it may have (for
example C compilers and installed libraries) and any other information
that should be provided before the tool is installed.

### INSTALLATION

To install this tool type the following:

```
$cat INSTALL
```

and follow instructions.

### DEPENDENCIES

This tool requires these other modules and libraries:

```
Standard ANSI libraries
```

### USAGE

```
#!/bin/bash

uds -s /tmp/notify.sck -m "Send notification"
STATUS=$?

if [[ $STATUS -eq 0 ]]; then
	# notify user
else
	# notify user
fi

exit 0
```

### COPYRIGHT AND LICENCE

Copyright (C) 2019 by https://vroncevic.github.io/unix_domain_socket_client

This tool is free software; you can redistribute it and/or modify it.

:sparkles:

