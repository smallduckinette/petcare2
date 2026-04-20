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

  auto frameTexture = textureIdGenerator.generate();
  auto frameSelTexture = textureIdGenerator.generate();

  auto birdEntity = entityIdGenerator.generate();
  auto catEntity = entityIdGenerator.generate();
  auto dogEntity = entityIdGenerator.generate();
  auto duckEntity = entityIdGenerator.generate();
  auto turtleEntity = entityIdGenerator.generate();

  std::map<StyleID, TextureID> styles = {{normalStyle, frameTexture},
                                             {selectedStyle, frameSelTexture}};

  return Config{{
      Texture{birdStuffTexture, "resources/bird_stuff.png"},
      Texture{catStuffTexture, "resources/cat_stuff.png"},
      Texture{dogStuffTexture, "resources/dog_stuff.png"},
      Texture{duckStuffTexture, "resources/duck_stuff.png"},
      Texture{turtleStuffTexture, "resources/turtle_stuff.png"},
      Texture{frameTexture, "resources/frame.png"},
      Texture{frameSelTexture, "resources/frame_sel.png"},
    },
                {
                  Entity{birdEntity, birdStuffTexture, styles},
                  Entity{catEntity, catStuffTexture, styles},
                  Entity{dogEntity, dogStuffTexture, styles},
                  Entity{duckEntity, duckStuffTexture, styles},
                  Entity{turtleEntity, turtleStuffTexture, styles}
                }};
}
