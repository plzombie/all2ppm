/*
BSD 2-Clause License

Copyright (c) 2021, Mikhail Morozov
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "../include/ppm_save.h"

#include <stdint.h>
#include <stdlib.h>

bool ppmSave(unsigned int sizex, unsigned int sizey, unsigned int channels, unsigned char *buf, FILE *f)
{
	size_t i, j, jmax, line_size;
	unsigned char *p;

	if(channels != 1 && channels != 3) return false;
	if(sizex == 0 || sizey == 0) return false;
	if(!buf || !f) return false;

	fprintf(f, (channels == 1)?"P5\n%u %u\n255\n":"P6\n%u %u\n255\n", sizex, sizey);

	if((SIZE_MAX / channels) >= sizex) {
		jmax = 1;
		line_size = (size_t)sizex * (size_t)channels;
	} else {
		jmax = channels;
		line_size = sizex;
	}
	p = buf;

	for(i = 0; i < sizey; i++)
		for(j = 0; j < jmax; j++) {
			fwrite(p, line_size, 1, f);
			p += line_size;
		}

	return true;
}

bool pbmSave(unsigned int sizex, unsigned int sizey, unsigned char *buf, FILE *f)
{
	unsigned char *filebuf, *p, b;
	size_t filesize, i, j;

	if(sizex == 0 || sizey == 0) return false;
	if(!buf || !f) return false;
	if((SIZE_MAX / sizey) <= sizex) return false;

	filesize = (size_t)sizex*(size_t)sizey/8;
	if(((size_t)sizex*(size_t)sizey)%8 > 0)
		filesize++;

	filebuf = malloc(filesize);
	if(!filebuf) return false;

	j = 0;
	b = 0;
	p = filebuf;
	for(i = 0; i < (size_t)sizex*(size_t)sizey; i++, j++) {
		if(j == 8) {
			j = 0;
			*(p++) = b;
			b = 0;
		}
		b |= 1<<j;
	}
	if(j == 8) *p = b;

	fprintf(f, "P4\n%u %u\n", sizex, sizey);

	free(filebuf);

 	return false;
}
