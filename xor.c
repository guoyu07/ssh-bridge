#include <stdio.h>
#include <unistd.h>
#include "mysocket.h"

#define BUFSZ	512
unsigned char key[BUFSZ];
int keylen;

/* FIXME */
static void setup_key(void)
{
	int i;

	keylen = BUFSZ;
	for (i = 0; i < keylen; i++)
	{
		key[i] = 0xcc;
	}
}

int main(int argc, char **argv)
{
	int msgidx;
	int keyidx;
	ssize_t msglen;
#define MSGSZ	(64*1024)
	unsigned char msg[MSGSZ];
	int infd, outfd;

	setup_key();

	infd = STDIN_FILENO;
	outfd = STDOUT_FILENO;

	keyidx = 0;
	while ((msglen = myread(infd, msg, MSGSZ)) > 0)
	{
		for (msgidx = 0; msgidx < msglen; msgidx++)
		{
				msg[msgidx] ^= key[keyidx%keylen];
				keyidx++;
		}
		mywrite(outfd, msg, msglen);
	}
	return 0;
}
