import os
from PIL import Image
import argparse


def save_as_ppm_p3(image_path, output_path):
    with Image.open(image_path) as img:
        img = img.convert('RGB')
        width, height = img.size
        pixels = list(img.getdata())

        with open(output_path, 'w') as f:
            f.write("P3\n")
            f.write(f"{width} {height}\n")
            f.write("255\n")
            for i in range(height):
                row = pixels[i * width:(i + 1) * width]
                for r, g, b in row:
                    f.write(f"{r} {g} {b} ")
                f.write("\n")



def convert_folder_to_ppm_p3(input_folder, output_folder):
    os.makedirs(output_folder, exist_ok=True)
    for filename in os.listdir(input_folder):
        if filename.lower().endswith(('.jpg', '.jpeg', '.png')):
            input_path = os.path.join(input_folder, filename)
            output_name = os.path.splitext(filename)[0] + '.ppm'
            output_path = os.path.join(output_folder, output_name)
            save_as_ppm_p3(input_path, output_path)
            print(f"Saved: {output_path}")



def main():
    parser = argparse.ArgumentParser(description="Convert images in a folder to PPM (P3 format)")
    parser.add_argument("input_folder", help="Path to the folder containing input images (JPG/PNG)")
    parser.add_argument("output_folder", help="Path to the folder where PPM images will be saved")

    args = parser.parse_args()

    convert_folder_to_ppm_p3(args.input_folder, args.output_folder)

if __name__ == "__main__":
    main()
