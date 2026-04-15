#pragma once

#include <functional>
#include <vector>


template<typename... ARGS>
class Signal
{
public:
  void emit(ARGS&& ...args)
  {
    if (!_fire)
    {
      _fire = true;
      for(auto && callback : _callbacks)
      {
        callback(args...);
      }
    }
  }

  void reset()
  {
    _fire = false;
  }

  void connect(std::function<void(ARGS&& ...)> f)
  {
    _callbacks.push_back(f);
  }

  template<typename C, typename F>
  void connect(C * obj, F f)
  {
    _callbacks.push_back([obj, f](ARGS&& ...args){ (obj->*f)(args...); });
  }

private:
  std::vector<std::function<void(ARGS&& ...)> > _callbacks;
  bool _fire = false;
};
