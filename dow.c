#include <stdio.h>

int dow(int, int, int);

static char *days[] = { "sat", "sun", "mon", "tue", "wed", "thu", "fri" };

int main(int argc, char **argv)
{
	if (argc != 4) {
		fprintf(stderr, "usage: %s year month day\n", *argv);
		return 22;
	}
	int y, m, d, n;
	n = sscanf(*(argv + 1), "%d", &y);
	if (n != 1) {
		fprintf(stderr, "dow: invalid year\n");
		return 22;
	}
	n = sscanf(*(argv + 2), "%d", &m);
	if (n != 1) {
		fprintf(stderr, "dow: invalid month\n");
		return 22;
	}
	n = sscanf(*(argv + 3), "%d", &d);
	if (n != 1) {
		fprintf(stderr, "dow: invalid day\n");
		return 22;
	}
	printf("%s\n", days[dow(y, n, d)]);
	return 0;
}

static const int months[] = { 1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6 };

int dow(int y, int m, int d)
{
	int yr = y % 100;
	int yr4 = yr / 4;
	int yr4d = yr4 + d;
	int yr4dm = yr4d + months[m - 1];
	int isleap = y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
	if (isleap && m <= 2 ) yr4dm--;
	if ((y / 100) % 4 == 0) yr4dm += 6;
	if ((y / 100) % 4 == 1) yr4dm += 2;
	if ((y / 100) % 4 == 2) yr4dm += 4;
	yr4dm += yr;
	return yr4dm % 7;
}
