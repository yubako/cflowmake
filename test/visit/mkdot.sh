#!/bin/bash

for f in *.dot; do
    dot -Tpng -o ${f}.png $f
done

