#include "../include/texture.h"

#include <cstddef>
#include <cstdint>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>

#include <cstdio>
#include <cstring>
#include <exception>
#include <iostream>

Texture::Texture(const char* path) {
  if (Read(path)) {
    printf("Loaded: %s\n", path);
    location = path;
    max_size = width * height * channel_count;
  } else {
    printf("Failed to load: %s\n", path);
  }
}
Texture::Texture(int w, int h, int chan) {
  max_size = w * h * chan;
  width = w;
  height = h;
  channel_count = chan;
  data = new uint8_t[max_size];
}
Texture::~Texture() {}  // stbi_image_free(data); }

std::vector<std::vector<Colour3>> Texture::GetColourData() {
  Colour3 c;
  c.r = 0;
  c.b = 0;
  c.g = 0;
  std::vector<std::vector<Colour3>> colourData(width,
                                               std::vector<Colour3>(height, c));
  int i = 0;
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      colourData[x][y].r = data[i];
      i++;
      colourData[x][y].b = data[i];
      i++;
      colourData[x][y].g = data[i];
      i++;
    }
  }
  return colourData;
}

void Texture::SetColourData(std::vector<std::vector<Colour3>> colData) {
  int i = 0;
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      data[i] = colData[x][y].r;
      i++;
      data[i] = colData[x][y].b;
      i++;
      data[i] = colData[x][y].g;
      i++;
    }
  }
}

void Texture::Save(const char* path) {
  if (Write(path)) {
    printf("Wrote image data to: %s\n", path);
  } else {
    printf("Error in saving texture to: %s\n", path);
  }
}

bool Texture::Read(const char* path) {
  data = stbi_load(path, &width, &height, &channel_count, 0);
  return data != NULL;
}

bool Texture::Write(const char* path) {
  // ImageFormat format = GetFileType(path);
  ImageFormat format = PNG;
  int output;
  switch (format) {
    case PNG:
      output = stbi_write_png(path, width, height, channel_count, data,
                              width * channel_count);
      break;
    case JPG:
      output = stbi_write_jpg(path, width, height, channel_count, data, 100);
      break;
  }
  return output != 0;
}

ImageFormat Texture::GetFileType(const char* path) {
  const char* extension = strrchr(path, '.');
  if (extension != nullptr) {
    if (strcmp(extension, ".png")) {
      return PNG;
    } else if (strcmp(extension, ".jpg")) {
      return JPG;
    }
  }
  printf("Error in finding extension, assuming PNG\n");
  return PNG;
}