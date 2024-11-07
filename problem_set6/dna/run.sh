#!/bin/bash

#This script runs the python program for all the sequences 
# Loop through all .txt files in the sequences folder
for file in sequences/*.txt
do
    # Run the Python program with each file
    python dna.py databases/large.csv "$file"
done
