#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <linux/limits.h>
#include <png.h>
#include <png++/png.hpp>

#include "LeptonActionFilePng.h"

LeptonActionFilePng::LeptonActionFilePng()
{
}

LeptonActionFilePng::LeptonActionFilePng(int w, int h)
{
	create(w, h);
}

LeptonActionFilePng::~LeptonActionFilePng() {
}

void LeptonActionFilePng::create(int w, int h)
{
	image_png.resize(w, h);
}

void LeptonActionFilePng::save()
{
	char filename[PATH_MAX];

	//
	const char *dir = getenv("LEPTON_DATA_DIR");
	if (dir == NULL) {
		dir = ".";
	}

	//
	struct timeval tv;
	gettimeofday(&tv, NULL);
	struct tm *now = localtime(&tv.tv_sec);
	sprintf(filename, "%s/lepton-%04d%02d%02d-%02d%02d%02d.%03d.png", dir, now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec, (int)(tv.tv_usec/1000));
	save(filename);
}

void LeptonActionFilePng::save(char *filename)
{
	image_png.write(filename);
}

void LeptonActionFilePng::setPixel(int col, int row, int colorR, int colorG, int colorB)
{
	image_png[row][col] = png::rgb_pixel(colorR, colorG, colorB);
}
