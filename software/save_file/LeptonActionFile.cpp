#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include "LeptonActionFile.h"

LeptonActionFile::LeptonActionFile()
{
}

LeptonActionFile::LeptonActionFile(int w, int h)
{
	create(w, h);
}

LeptonActionFile::~LeptonActionFile() {
}

void LeptonActionFile::create(int w, int h)
{
}

void LeptonActionFile::save()
{
	char *filename = "set_your_filename";
	save(filename);
}

void LeptonActionFile::save(char *filename)
{
}

void LeptonActionFile::setPixel(int col, int row, int colorR, int colorG, int colorB)
{
}
