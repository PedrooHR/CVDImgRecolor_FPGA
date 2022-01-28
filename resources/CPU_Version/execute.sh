#!/bin/bash

rm -rf results
mkdir results
rm svimg.jpg
rm results.log
rm temp_result.log

for id in {1..17}; do
    echo "testeimg${id}.jpg" >> results.log
    for i in {1..10}; do
        { time ./main imgs/testeimg${id}.jpg ; } 2> temp_result.log
        cat temp_result.log | grep 'fault'
        if [ $? -eq 0 ]; then
            echo "error" >> results.log
        else
            cat temp_result.log | grep 'real' >> results.log
        fi
    done
    mv svimg.jpg results/testeimg${id}_a.jpg
done

