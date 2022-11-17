#include "../PerlinNoise.hpp"
#include "MyGenerator.h"
#include <iostream>
// do not use this one to your assignment. this is my sample generator
std::vector<Color32> MyGenerator::Generate(int sideSize,
                                                       float displacement) {
  std::vector<Color32> colors;
  //   create your own function for noise generation
  siv::BasicPerlinNoise<float> noise;
  noise.reseed(1337);
  for (int l = 0; l < sideSize; l++) {
    for (int c = 0; c < sideSize; c++) {
      float rgb =
          ((1 + noise.octave3D(c / 50.0, l / 50.0, displacement, 2))/2) * 255;
      float nx =
          2 * (float)c / (float(sideSize) - 1);
      float ny =
          2 * (float)l / (float(sideSize) - 1);
      float d = 1 - (1 - (nx * nx) * (1 - (ny * ny)));

      rgb += ((1 - d) * 255) / 2;

      if (rgb < 20) 
          colors.emplace_back(0, 0, 255);
      else if (rgb < 100)
        colors.emplace_back(0, 100, 0);
      else if (rgb < 200)
        colors.emplace_back(87, 65, 47);
      else
        colors.emplace_back(255, 255, 255);
    }
  }
  std::cout << colors.size() << std::endl;
  return colors;
}
std::string MyGenerator::GetName() { return "My Generator"; }
