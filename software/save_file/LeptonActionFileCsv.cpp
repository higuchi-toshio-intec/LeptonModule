#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <linux/limits.h>

#include "LeptonActionFileCsv.h"

LeptonActionFileCsv::LeptonActionFileCsv()
{
}

LeptonActionFileCsv::LeptonActionFileCsv(int w, int h)
{
	create(w, h);
}

LeptonActionFileCsv::~LeptonActionFileCsv() {
	if (image_csv != NULL) {
		free(image_csv);
	}
}

void LeptonActionFileCsv::create(int w, int h)
{
	if (image_csv != NULL) {
		free(image_csv);
	}
	image_csv = (uint16_t *)malloc(sizeof(uint16_t) * w * h);
	image_width = w;
	image_height = h;
}

void LeptonActionFileCsv::save()
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
	sprintf(filename, "%s/lepton-%04d%02d%02d-%02d%02d%02d.%03d.csv", dir, now->tm_year + 1900, now->tm_mon + 1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec, (int)(tv.tv_usec/1000));
	save(filename);
}

void LeptonActionFileCsv::save(char *filename)
{
	uint16_t valMin = UINT16_MAX;
	uint16_t valMax = 0;
	for (int row = 0; row < image_height; row++) {
		for (int col = 0; col < image_width; col++) {
			uint16_t val = *(image_csv + row * image_width + col);
			if (val < valMin) {
				valMin = val;
			}
			if (valMax < val) {
				valMax = val;
			}
		}
	}

	//
	FILE *fh = fopen(filename, "w");
	for (int row = 0; row < image_height; row++) {
		for (int col = 0; col < image_width; col++) {
			uint16_t val = *(image_csv + row * image_width + col);
			fprintf(fh, "%d ", val);
			if (col != image_width - 1) {
				fprintf(fh, ",");
			}
		}
		fprintf(fh, "\n");
	}
	fclose(fh);
}

void LeptonActionFileCsv::setRawValue(int col, int row, uint16_t val)
{
	*(image_csv + row * image_width + col) = val;
}
