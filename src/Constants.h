#pragma once

#include "StrongId.h"

class TextureDiscriminator;
class EntityDiscriminator;

using TextureID = StrongId<TextureDiscriminator, int>;
using EntityID = StrongId<EntityDiscriminator, int>;
