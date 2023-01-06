# all2ppm

A library and a bunch of programs to save netpbm files.

## Programs

### all2pam

Save anything (using [stb_image][]) to *PAM* (P7) format.

### all2pbm

Save anything (using [stb_image][]) to *PBM* (P4) format.

### all2ppm

Save anything (using [stb_image][]) to *PPM* (P5 or P6) format.

## Library

### ppm saver

Can be 1 (grayscale) or 3 (rgb) channels.

``` c
bool ppmSave(unsigned int sizex, unsigned int sizey, unsigned int channels, unsigned char *buf, FILE *f);
```

### pam saver

Can be 1 (grayscale), 2 (grayscale+alpha), 3 (rbg) or 4 (rgba) channels.

``` c
bool pamSave(unsigned int sizex, unsigned int sizey, unsigned int channels, unsigned char *buf, FILE *f);
```

### pbm saver

``` c
bool pbmSave(unsigned int sizex, unsigned int sizey, unsigned char *buf, FILE *f);
```

[stb_image]: https://github.com/nothings/stb/blob/master/stb_image.h
