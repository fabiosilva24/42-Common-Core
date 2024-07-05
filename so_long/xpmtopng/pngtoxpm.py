import os
from PIL import Image

def png_to_xpm(png_file, xpm_file, variable_name="image"):
    image = Image.open(png_file)
    width, height = image.size
    pixels = list(image.getdata())

    xpm_data = [
        f"/* XPM */",
        f"static char *{variable_name}[] = {{",
        f'"{width} {height} 2 1",',
        '"c c #000000",',
        '". c #ffffff",',
    ]

    for y in range(height):
        line = '"'
        for x in range(width):
            r, g, b, a = pixels[y * width + x]
            if r == g == b == 255:
                line += "."
            else:
                line += "c"
        line += '",'
        xpm_data.append(line)

    xpm_data.append("};")

    with open(xpm_file, "w") as f:
        f.write("\n".join(xpm_data))

def convert_all_pngs_to_xpm(input_folder, output_folder):
    # Create the output folder if it doesn't exist
    os.makedirs(output_folder, exist_ok=True)

    # Loop through all files in the input folder
    for filename in os.listdir(input_folder):
        if filename.endswith(".png"):
            input_file = os.path.join(input_folder, filename)
            output_file = os.path.join(output_folder, os.path.splitext(filename)[0] + ".xpm")
            png_to_xpm(input_file, output_file)

# Example usage
input_folder = "/home/fsilva-p/42-Common-Core/so_long/xpmtopng/input"
output_folder = "/home/fsilva-p/42-Common-Core/so_long/xpmtopng/output"

convert_all_pngs_to_xpm(input_folder, output_folder)

