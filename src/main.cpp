#include <cstddef>
#include <cstdio>
#include <iostream>
#include <new>

#include "../include/core.h"
#include "../include/texture.h"

int main(int argc, char* args[]) {
  char* path;
  std::cin >> path;
  Texture* tex = new Texture(path);
  int* width = &tex->width;
  std::cout << *width << std::endl;
  return 0;
}
