#include "../include/texture.h"
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
    max_size = width * height * channel_count;
  } else {
    printf("Failed to load: %s\n", path);
  }
}
Texture::~Texture() { stbi_image_free(data); }

bool Texture::Read(const char* path) {
  data = stbi_load(path, &width, &height, &channel_count, 0);
  return data != NULL;
}

bool Texture::Write(const char* path) {
  ImageFormat format = GetFileType(path);
  int output;
  switch (format) {
    case PNG:
      output =
          stbi_write_png(path, width, height, channel_count, &data, max_size);
      break;
    case JPG:
      output =
          stbi_write_jpg(path, width, height, channel_count, &data, max_size);
      break;
  }
  if (output == 0) {
    printf("Error in saving texture to %s\n", path);
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