#include "Config.h"


config::Config config::makeConfig()
{
  StrongIdGenerator<TextureID> textureIdGenerator;
  StrongIdGenerator<EntityID> entityIdGenerator;

  auto birdStuffTexture = textureIdGenerator.generate();
  auto catStuffTexture = textureIdGenerator.generate();
  auto dogStuffTexture = textureIdGenerator.generate();
  auto duckStuffTexture = textureIdGenerator.generate();
  auto turtleStuffTexture = textureIdGenerator.generate();

  auto birdEntity = entityIdGenerator.generate();
  auto catEntity = entityIdGenerator.generate();
  auto dogEntity = entityIdGenerator.generate();
  auto duckEntity = entityIdGenerator.generate();
  auto turtleEntity = entityIdGenerator.generate();

  return Config{{
      Texture{birdStuffTexture, "resources/bird_stuff.png"},
      Texture{catStuffTexture, "resources/cat_stuff.png"},
      Texture{dogStuffTexture, "resources/dog_stuff.png"},
      Texture{duckStuffTexture, "resources/duck_stuff.png"},
      Texture{turtleStuffTexture, "resources/turtle_stuff.png"}
    },
                {
                  Entity{birdEntity, birdStuffTexture},
                  Entity{catEntity, catStuffTexture},
                  Entity{dogEntity, dogStuffTexture},
                  Entity{duckEntity, duckStuffTexture},
                  Entity{turtleEntity, turtleStuffTexture}
                }};
}
