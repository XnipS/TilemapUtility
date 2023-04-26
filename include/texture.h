#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>

enum ImageFormat { PNG, JPG };

struct Colour3 {
  uint8_t r = 0;
  uint8_t b = 0;
  uint8_t g = 0;
};
struct Colour4 {
  int r = 0;
  int b = 0;
  int g = 0;
  int a = 0;
};

class Texture {
 public:
  Texture(const char* path);
  Texture(int w, int h, int chan);
  ~Texture();
  void Save(const char* path);
  const char* location;
  int width;
  int height;
  uint8_t* data = NULL;
  int channel_count;
  std::vector<std::vector<Colour3>> GetColourData();
  void SetColourData(std::vector<std::vector<Colour3>>);

 private:
  size_t max_size;

  bool Read(const char* path);
  bool Write(const char* path);
  ImageFormat GetFileType(const char* path);
};