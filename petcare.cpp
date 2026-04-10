#include <memory>
#include <fmt/core.h>

#include <SDL.h>

int main()
{
  fmt::print("Starting Petcare\n");

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    throw std::runtime_error(fmt::format("Failed to init video: {}", SDL_GetError()));
  }

  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window(
      SDL_CreateWindow("Petcare", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN),
      SDL_DestroyWindow);

  if (!window)
  {
    throw std::runtime_error(fmt::format("Failed to create window: {}", SDL_GetError()));
  }

  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer(
      SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED),
      SDL_DestroyRenderer);

  if (!renderer)
  {
    throw std::runtime_error(fmt::format("Failed to create renderer: {}", SDL_GetError()));
  }

  bool running = true;
  while (running)
  {
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
        running = false;
      }
    }

    SDL_RenderClear(renderer.get());
    SDL_RenderPresent(renderer.get());
  }

  fmt::print("Closing\n");

  return 0;
}
