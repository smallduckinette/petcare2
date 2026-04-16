#pragma once

#include "StrongId.h"

class TextureDiscriminator;

using TextureID = StrongId<TextureDiscriminator, int>;

namespace tex
{
  const TextureID BIRD(1);
  const TextureID BIRD_STUFF(2);
  const TextureID CAT(3);
  const TextureID CAT_STUFF(4);
  const TextureID DOG(5);
  const TextureID DOG_STUFF(6);
  const TextureID DUCK(7);
  const TextureID DUCK_STUFF(8);
  const TextureID TURTLE(9);
  const TextureID TURTLE_STUFF(10);
}
