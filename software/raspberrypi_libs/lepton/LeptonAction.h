#ifndef TEXTLEPTONACTION
#define TEXTLEPTONACTION

class LeptonAction
{

public:
  LeptonAction();
  ~LeptonAction();

  virtual void setPixel(int, int, int, int, int);
  virtual void setRawValue(int, int, uint16_t);

private:

};

#endif
