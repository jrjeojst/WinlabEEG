#ifndef EMOTIV_H
#define EMOTIV_H

/* Linux */
#include <linux/types.h>
#include <linux/input.h>
#include <linux/hidraw.h>

/* Unix */
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* C */
#include <stdio.h>
#include <string.h>
#include <errno.h>

/* Libudev */
#include <libudev.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

/* OpenSSL */

#include <openssl/aes.h>

//#define HIDIOCSFEATURE(len)    _IOC(_IOC_WRITE|_IOC_READ, 'H', 0x06, len)
//#define HIDIOCGFEATURE(len)    _IOC(_IOC_WRITE|_IOC_READ, 'H', 0x07, len)

class emotiv
{
	public:
		emotiv();
		emotiv(unsigned char *);
		unsigned char * readBuffer();
		void setKey(unsigned char *);
		unsigned char buffer[32];
	private:
		void decrypt(unsigned char *in, unsigned char *out);
		unsigned char * key;
		AES_KEY decryptKey;
		int filedescriptor;
		int res;
};

#endif
