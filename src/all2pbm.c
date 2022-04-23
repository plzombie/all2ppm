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

#include <stdlib.h>
#include <wchar.h>

#define STB_IMAGE_IMPLEMENTATION
#include "third_party/stb_image.h"

#if defined(_WIN32)
#define A2P_USE_WCHAR
#endif

#ifdef A2P_USE_WCHAR
int wmain(int argc, wchar_t** argv)
#else
int main(int argc, char** argv)
#endif
{
 	FILE *f_in = 0, *f_out = 0;
	int sizex, sizey, channels;
	unsigned char *buffer = 0;

	if(argc < 3) {
		wprintf(L"\tall2ppm input.* output.ppm\n\n");
		return 0;
	}

#ifdef A2P_USE_WCHAR
	f_in = _wfopen(argv[1], L"rb");
	f_out = _wfopen(argv[2], L"wb");
#else
	f_in = fopen(argv[1], "rb");
	f_out = fopen(argv[2], "wb");
#endif
	if(!f_in || !f_out) {
		wprintf(L"Can't open files\n");
		goto EXIT;
	}

	buffer = stbi_load_from_file(f_in, &sizex, &sizey, &channels, 1);
	if(!buffer) {
		wprintf(L"Can't open file\n");
		goto EXIT;
	}

	if(!pbmSave(sizex, sizey, buffer, f_out)) {
		wprintf(L"Can't save file\n");
		goto EXIT;
	}

EXIT:
	if(f_in) fclose(f_in);
	if(f_out) fclose(f_out);
	if(buffer) free(buffer);

        return 0;
}
