### Column-major raw exporter for Maxim's bmp2tile

This is a DLL plugin exporter for Maxim's [bmp2tile](https://github.com/maxim-zhao/bmp2tile) to exports *uncompressed* (raw) tilemaps in column-major order (a.k.a. 'transposed') instead of the standard row-major order.
It's mostly useful for horizontal-only scrolling backgrounds, since you need to update a column at the time.

To compile the DLL on Windows:
```
gcc -Wall -c gfxcomp_column_major_raw.c
gcc -shared -o gfxcomp_column_major_raw.dll gfxcomp_column_major_raw.o
```

To (cross) compile the DLL on Linux:
```
i686-w64-mingw32-gcc -Wall -c gfxcomp_column_major_raw.c
i686-w64-mingw32-gcc -shared -o gfxcomp_column_major_raw.dll gfxcomp_column_major_raw.o
```
(to install mingw32 on Linux: `sudo apt-get install mingw-w64`)
