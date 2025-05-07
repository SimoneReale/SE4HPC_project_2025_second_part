import random
import os


def generate_random_ppm_images(output_dir, num_images, width, height):
    os.makedirs(output_dir, exist_ok=True)

    for i in range(num_images):
        filename = os.path.join(output_dir, f"random_image_{i+1}.ppm")
        with open(filename, "w") as f:
            f.write("P3\n")
            f.write(f"{width} {height}\n")
            f.write("255\n")

            for _ in range(height):
                row = []
                for _ in range(width):
                    r = random.randint(0, 255)
                    g = random.randint(0, 255)
                    b = random.randint(0, 255)
                    row.extend([str(r), str(g), str(b)])
                f.write(" ".join(row) + "\n")


generate_random_ppm_images(
    output_dir="random_images", num_images=5, width=100, height=100
)
