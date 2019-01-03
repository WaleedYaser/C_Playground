#include "w_stdio.h"

#include <fcntl.h>
#include <stdlib.h>

FILE _iob[OPEN_MAX] = {
	{ 0, (char *) 0, (char *) 0, _READ, 0 },
	{ 0, (char *) 0, (char *) 0, _WRITE, 1 },
	{ 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};

/* fopen: open file, return file ptr */
FILE *fopen(char *name, char *mode)
{
	int fd;
	FILE *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if ((fp-> flags & (_READ | _WRITE)) == 0)
			break;			/* found free slot */
	if (fp >= _iob + OPEN_MAX)
		return NULL;		/* no free slot */

	if (*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0L, 2);
	} else
		fd = open(name, O_RDONLY, 0);
	if (fd == -1)
		return NULL;

	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flags = (*mode == 'r') ? _READ : _WRITE;

	return fp;
}

/* _fillbuf: allocate and fill input buffer */
int _fillbuf(FILE *fp)
{
	int bufsize;

	if ((fp->flags & (_READ | _WRITE | _ERR)) != _READ)
		return EOF;
	bufsize = (fp->flags & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL)		/* no buffer yer */
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flags |= _EOF;
		else
			fp->flags |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}

int _flushbuf(int c, FILE *fp)
{
	int bufsize;

	if ((fp->flags & (_READ | _WRITE | _ERR)) != _WRITE)
		return EOF;
	bufsize = (fp->flags & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL)
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = bufsize - 1;
	if (c != EOF) 
		*fp->ptr++ = c;

	write(fp->fd, fp->base, (int) (fp->ptr - fp->base));

	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
			fp->flags |= _EOF;
		else
			fp->flags |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}
