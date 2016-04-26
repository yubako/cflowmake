#!/bin/bash

for f in dots/*.dot; do
    echo "## $f"
    dot -Tpng -o ${f}.png $f
done

