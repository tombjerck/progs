#include <iostream>
#include <string>
#include <cmath>

using namespace std;

float calc_dpi(float size, float w, float h);

int main(int argc, char **argv)
{
	string progname (argv[0]);
	string usage = "Usage: " + progname + " <size in inches> <resolution in pixels>\n"
		+ "Example: " + progname + " 14 1920x1080";

	if (argc != 3) {
		cerr << usage << endl;
	}

	string size = argv[1];
	string resolution = argv[2]; // Ex. 1920x1080

	size_t idx;
	float s = stof(size);
	float w = stof(resolution, &idx);
	float h = stof(resolution.substr(idx + 1));

	float dpi = calc_dpi(s, w, h);

	cout << "Dpi: " << dpi << endl;
}

float calc_dpi(float size, float w, float h)
{
	/* First find the length in inches of the with of the screen.
	 * Then return the number of horizontal pixels divided by this
	 * number. */

	float h_i = size / sqrt(1 + pow(h/w, 2));

	return w / h_i;
}
