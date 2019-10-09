#ifndef TEXTLEPTONACTIONPNG
#define TEXTLEPTONACTIONPNG

#include <png++/png.hpp>

#include "LeptonAction.h"

class LeptonActionPng : public LeptonAction
{

public:
  LeptonActionPng();
  LeptonActionPng(int, int);
  ~LeptonActionPng();

  void create(int, int);
  void save();
  void save(char *);
  virtual void setPixel(int, int, int, int, int);

private:
  png::image < png::rgb_pixel > image_png;

};

#endif
