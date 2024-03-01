#!/bin/bash

# Define the command to execute
command_to_execute="python verifier.py"

# Define the initial file numbers
file_num1=721
file_num2=797

# Define the number of iterations for the loop
num_iterations=77  # You can change this number as needed

# Loop through the iterations
for ((i=1; i<=$num_iterations; i++)); do
    # Execute the command with the current file numbers
    $command_to_execute "./inputs/input_group$file_num1.txt" "./outputs/output_from_769_to_$file_num2.txt"
    
    # Increment file numbers for the next iteration
    ((file_num1++))
    ((file_num2++))
done
