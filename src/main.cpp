#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <new>
#include <string>
#include <vector>

#include "../include/core.h"
#include "../include/texture.h"

int main(int argc, char* args[]) {
  // Texture tex("/home/luke/Desktop/xnips_hat.png");
  // tex.Save("/home/luke/Desktop/new_xnips_hat.png");
  // Texture copy = tex;
  // for (int i = 0; i < copy.width * copy.channel_count; i++) {
  //   copy.data[i] = 255;
  // }
  // copy.Save("/home/luke/Desktop/copy_xnips_hat.png");
  // Texture blank(64, 64, 3);
  // for (int i = 0; i < 64 * 64; i++) {
  //  blank.data[i] = 0;
  //}
  // blank.Save("/home/luke/Desktop/blank.png");

  // Start

  // std::cout << argc << std::endl;
  // if (argc != 4) {
  //   printf("Three inputs are required!\n");
  //   return 1;
  // }

  printf("Input_1: %s\n", "/home/luke/Desktop/Dirt.png");
  printf("Input_2: %s\n", "/home/luke/Desktop/Stone.png");
  printf("Mask: %s\n", "/home/luke/Desktop/mask.png");
  printf("Inputs accepted.\n");

  Texture tex_1("/home/luke/Desktop/Dirt.png");
  Texture tex_o(160, 256, 3);
  // Texture tex_2("/home/luke/Desktop/Stone.png");
  // Texture tex_m("/home/luke/Desktop/mask.png");
  // Texture tex_o(tex_m.width, tex_m.height, tex_m.channel_count);
  printf("Textures Loaded.\n");

  std::vector<std::vector<Colour3>> colourData = tex_1.GetColourData();
  for (int x = 0; x < tex_1.width; x++) {
    for (int y = 0; y < tex_1.height; y++) {
      colourData[x][y].r = 255;
    }
  }
  tex_1.SetColourData(colourData);
  tex_1.Save("/home/luke/Desktop/Dirt3.png");

  return 0;
}
