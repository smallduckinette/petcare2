#pragma once

#include "StrongId.h"

class TextureDiscriminator;
class EntityDiscriminator;
class StyleDiscriminator;

using TextureID = StrongId<TextureDiscriminator, int>;
using EntityID = StrongId<EntityDiscriminator, int>;
using StyleID = StrongId<EntityDiscriminator, std::string>;

const StyleID normalStyle("normal");
const StyleID selectedStyle("selected");
