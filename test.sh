#!/bin/bash

top_file=src/pre_setup.c  # Replace this with the offending C or ASM file.
for file in $(tools/scaninc/scaninc -I include ${top_file}); do
  if ! [ -f "${file}" ]; then
    make "${file}" || echo ${file}
  fi
done