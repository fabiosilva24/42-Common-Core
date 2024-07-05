#!/bin/bash

input_dir="/home/fsilva-p/2/42-Common-Core/so_long/xpmtopng/input"
output_dir="/home/fsilva-p/2/42-Common-Core/so_long/xpmtopng/output"

mkdir -p "$output_dir"

for file in "$input_dir"/*.png; do
	filename=$(basename "$file" .png)


	output_file="$output_dir/$filename.xpm"

	convert "$file" "$output_file"
done

echo "Conversion done!"
