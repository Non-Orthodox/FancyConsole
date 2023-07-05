#ifndef FANCYCONSOLE_UNICODE_H
#define FANCYCONSOLE_UNICODE_H

#include <string>
#include <cstdint>

namespace Unicode
{
  const std::string checkmark = "\u2713";

  // Expected inputs: 1 through 8
  std::string LowerBlock(uint8_t height)
  {
    switch(height)
    {
      case 0:
        return " ";
      case 1:
        return "\u2581";
      case 2:
        return "\u2582";
      case 3:
        return "\u2583";
      case 4:
        return "\u2584";
      case 5:
        return "\u2585";
      case 6:
        return "\u2586";
      case 7:
        return "\u2587";
      default:
        return "\u2588";
    }
  }

  std::string RightBlock(uint8_t width)
  {
    switch(width)
    {
      case 0:
        return " ";
      case 1:
        return "\u258F";
      case 2:
        return "\u258E";
      case 3:
        return "\u258D";
      case 4:
        return "\u258C";
      case 5:
        return "\u258B";
      case 6:
        return "\u258A";
      case 7:
        return "\u2589";
      default:
        return "\u2588";
    }
  }

}

#endif
