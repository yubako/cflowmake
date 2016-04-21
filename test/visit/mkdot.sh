#!/bin/bash

for f in dots/*.dot; do
    dot -Tpng -o ${f}.png $f
done

