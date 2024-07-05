import os
from PIL import Image

def resize_all_pngs(input_folder, output_folder, new_size):
    # Create the output folder if it doesn't exist
    os.makedirs(output_folder, exist_ok=True)

    # Loop through all files in the input folder
    for filename in os.listdir(input_folder):
        if filename.endswith(".png"):
            input_file = os.path.join(input_folder, filename)
            output_file = os.path.join(output_folder, filename)
            resize_png(input_file, output_file, new_size)

def resize_png(input_file, output_file, new_size):
    image = Image.open(input_file)
    resized_image = image.resize(new_size, resample=Image.BICUBIC)
    resized_image.save(output_file)

# Example usage
input_folder = "/home/fsilva-p/42-Common-Core/so_long/xpmtopng/input"
output_folder = "/home/fsilva-p/42-Common-Core/so_long/xpmtopng/output"
new_size = (16, 16)

resize_all_pngs(input_folder, output_folder, new_size)

