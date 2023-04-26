#include <cstdio>

#include "../include/core.h"
#include "../include/texture.h"

int main(int argc, char* args[]) {
  if (argc != 5) {
    printf("This requires 4 arguments (in_1, in_2, mask, out)\n");
    return 1;
  }

  printf("Input_1: %s\n", "/home/luke/Desktop/Dirt.png");
  printf("Input_2: %s\n", "/home/luke/Desktop/Stone.png");
  printf("Mask: %s\n", "/home/luke/Desktop/mask.png");
  printf("Inputs accepted.\n");
#if (Debug)
  Texture tex_1("/home/luke/Desktop/Stone.png");
  Texture tex_2("/home/luke/Desktop/Dirt.png");
  Texture tex_m("/home/luke/Desktop/mask2.png");
#else
  Texture tex_1(args[1]);
  Texture tex_2(args[2]);
  Texture tex_m(args[3]);
#endif
  Texture tex_o(tex_m.width, tex_m.height, tex_m.channel_count);
  printf("Textures Loaded.\n");

  std::vector<std::vector<Colour3>> dat_1 = tex_1.GetColourData();
  std::vector<std::vector<Colour3>> dat_2 = tex_2.GetColourData();
  std::vector<std::vector<Colour3>> dat_m = tex_m.GetColourData();
  std::vector<std::vector<Colour3>> dat_o = tex_o.GetColourData();

  int val_x = 0;
  int val_y = 0;
  for (int x = 0; x < tex_m.width; x++) {
    for (int y = 0; y < tex_m.height; y++) {
      if (dat_m[x][y].r == 0) {
        dat_o[x][y] = dat_1[val_x][val_y];

      } else {
        dat_o[x][y] = dat_2[val_x][val_y];
      }
      val_y++;
      if (val_y == tex_1.height) {
        val_y = 0;
      }
    }
    val_x++;
    if (val_x == tex_1.width) {
      val_x = 0;
    }
  }
  printf("Manipulated.\n");
  tex_o.SetColourData(dat_o);
  if (Debug) {
    tex_o.Save("/home/luke/Desktop/Output.png");
  } else {
    tex_o.Save(args[4]);
  }
  printf("Done!.\n");
  return 0;
}
