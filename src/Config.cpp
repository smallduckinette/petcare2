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

  auto birdTexture = textureIdGenerator.generate();
  auto catTexture = textureIdGenerator.generate();
  auto dogTexture = textureIdGenerator.generate();
  auto duckTexture = textureIdGenerator.generate();
  auto turtleTexture = textureIdGenerator.generate();

  auto frameTexture = textureIdGenerator.generate();
  auto frameSelTexture = textureIdGenerator.generate();

  auto birdStuffEntity = entityIdGenerator.generate();
  auto catStuffEntity = entityIdGenerator.generate();
  auto dogStuffEntity = entityIdGenerator.generate();
  auto duckStuffEntity = entityIdGenerator.generate();
  auto turtleStuffEntity = entityIdGenerator.generate();
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
      Texture{birdTexture, "resources/bird.png"},
      Texture{catTexture, "resources/cat.png"},
      Texture{dogTexture, "resources/dog.png"},
      Texture{duckTexture, "resources/duck.png"},
      Texture{turtleTexture, "resources/turtle.png"},
      Texture{frameTexture, "resources/frame.png"},
      Texture{frameSelTexture, "resources/frame_sel.png"},
    },
                {
                  Entity{birdEntity, birdTexture, styles},
                  Entity{catEntity, catTexture, styles},
                  Entity{dogEntity, dogTexture, styles},
                  Entity{duckEntity, duckTexture, styles},
                  Entity{turtleEntity, turtleTexture, styles}
                },
                {
                  Entity{birdStuffEntity, birdStuffTexture, styles},
                  Entity{catStuffEntity, catStuffTexture, styles},
                  Entity{dogStuffEntity, dogStuffTexture, styles},
                  Entity{duckStuffEntity, duckStuffTexture, styles},
                  Entity{turtleStuffEntity, turtleStuffTexture, styles}
                },
                {
                  Sound{birdStuffEntity, "resources/do.wav"},
                  Sound{catStuffEntity, "resources/re.wav"},
                  Sound{dogStuffEntity, "resources/mi.wav"},
                  Sound{duckStuffEntity, "resources/fa.wav"},
                  Sound{turtleStuffEntity, "resources/sol.wav"}
                }
  };
}
