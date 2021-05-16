#include <iostream>

int main() {
	const int width = 256;
	const int height = 256;

	std::cout << "P3\n" << width << " " << height << "\n255\n";

	for (int j = height - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < width; ++i) {
			auto r = double(i) / (width - 1);
			auto g = double(j) / (height - 1);
			auto b = 0.25;

			int ir = static_cast<int>(255.99 * r);
			int ig = static_cast<int>(255.99 * g);
			int ib = static_cast<int>(255.99 * b);
			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
	std::cerr << "\nDone.\n";
}
