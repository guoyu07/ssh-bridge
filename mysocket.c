#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include "mysocket.h"
#include "mylog.h"

int myread(int fd, uint8_t *buf, size_t len)
{
	int rc;

redo:
	rc = read(fd, buf, len);
	if (rc < 0)
	{
		if (errno == EINTR)
		{
			goto redo;
		}
		else
		{
			myerr("read: %s\n", strerror(errno));
		}
	}
	return rc;
}

int mywrite(int fd, uint8_t *buf, size_t len)
{
	int rc;
	int wrote;
	int remain = len;

	while (remain)
	{
		rc = write(fd, buf, remain);
		if (rc < 0)
		{
			if (errno == EINTR)
			{
				continue;
			}
			else if (errno == EPIPE)
			{
				myerr("\nEPIPE\n\n");
				return -1;
			}
			else
			{
				myerr("write: %s\n", strerror(errno));
				return -1;
			}
		}
		wrote += rc;
		remain -= rc;
	}
	return len;
}

