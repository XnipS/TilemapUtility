#pragma once
#include <cstddef>
#include <cstdint>

enum ImageFormat { PNG, JPG };

class Texture {
 public:
  Texture(const char* path);
  ~Texture();
  // Get Pixel
  // Set Pixel
  int width;

 private:
  uint8_t* data = NULL;
  size_t max_size;

  int height;
  int channel_count;

  bool Read(const char* path);
  bool Write(const char* path);
  ImageFormat GetFileType(const char* path);
};