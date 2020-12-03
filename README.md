# CPP-Tracer

## About
This tracer was the result of a two part assignment given during CMSC 435 at UMBC with Professor Marc Olano.

The program takes an NFF file, parses it, renders it, and outputs the resulting image as a PPM file. At present, the tracer only recognizes sphere primitives. The tracer's BRDF supports diffuse, specular, and reflective lighting.

## Build
```
cmake build
cd build && make
```

## Usage
`./trace input_nff <output_ppm>`