#ifndef FANCYCONSOLE_ANSI_H
#define FANCYCONSOLE_ANSI_H

#include <string>
#include <cstdint>

#define ANSI_OCTAL_CONTROL_SEQUENCE 0

namespace ANSI
{
  // Control Sequence Indicator
#if ANSI_OCTAL_CONTROL_SEQUENCE
  const std::string csi = "\033[";
#else
  const std::string csi = "\x1b[";
#endif

  const std::string reset = csi + "0m";

  const std::string black_text = csi + "30m";
  const std::string red_text = csi + "31m";
  const std::string green_text = csi + "32m";
  const std::string darkyellow_text = csi + "33m";
  const std::string blue_text = csi + "34m";
  const std::string purple_text = csi + "35m";

  const std::string brightred_text = csi + "91m";
  const std::string lime_text = csi + "92m";
  const std::string yellow_text = csi + "93m";
  const std::string skyblue_text = csi + "94m";
  const std::string lightpurple_text = csi + "95m";
  const std::string cyan_text = csi + "96m";
  const std::string white_text = csi + "97m";

  const std::string black_back = csi + "40m";
  const std::string red_back = csi + "41m";
  const std::string green_back = csi + "42m";
  const std::string darkyellow_back = csi + "43m";
  const std::string blue_back = csi + "44m";
  const std::string purple_back = csi + "45m";

  const std::string brightred_back = csi + "101m";
  const std::string lime_back = csi + "102m";
  const std::string yellow_back = csi + "103m";
  const std::string skyblue_back = csi + "104m";
  const std::string lightpurple_back = csi + "105m";
  const std::string cyan_back = csi + "106m";
  const std::string white_back = csi + "107m";

  const std::string bold = csi + "1m";
  const std::string dim = csi + "2m";
  const std::string underline = csi + "4m";
  const std::string slow_blink = csi + "5m";
  const std::string fast_blink = csi + "6m";
  const std::string invert = csi + "7m";
  const std::string strikethrough = csi + "9m";

  const std::string normal_intensity = csi + "22m";
  const std::string no_underline = csi + "24m";
  const std::string no_blink = csi + "25m";
  const std::string no_strikethrough = csi + "29m";

  const std::string default_text_color = csi + "39m";
  const std::string default_back_color = csi + "49m";

  std::string TextRGB(const uint8_t r, const uint8_t g, const uint8_t b)
  {
    return csi + "38;2;" + std::to_string(r) + ";" + std::to_string(g)
        + ";" + std::to_string(b) + "m";
  }

  // 8-bit colors
  std::string TextRGB(const uint8_t index)
  {
    return csi + "38;5;" + std::to_string(index) + "m";
  }

  std::string BackRGB(const uint8_t r, const uint8_t g, const uint8_t b)
  {
    return csi + "48;2;" + std::to_string(r) + ";" + std::to_string(g)
        + ";" + std::to_string(b) + "m";
  }

  // 8-bit colors
  std::string BackRGB(const uint8_t index)
  {
    return csi + "48;5;" + std::to_string(index) + "m";
  }

  std::string CursorUp(const uint16_t n)
  {
    return csi + std::to_string(n) + 'A';
  }

  std::string CursorDown(const uint16_t n)
  {
    return csi + std::to_string(n) + 'B';
  }

  std::string CursorRight(const uint16_t n)
  {
    return csi + std::to_string(n) + 'C';
  }

  std::string CursorLeft(const uint16_t n)
  {
    return csi + std::to_string(n) + 'D';
  }

  // Coordinates are 1-indexed. (1,1) is top left.
  std::string MoveCursor(const unsigned int n, const unsigned int m)
  {
    return csi + std::to_string(n) + ';' + std::to_string(m) + 'H';
  }

  /*
  0 - clear from cursor to end of screen
  1 - clear from cursoe to beginning of screen
  2 - clear entire screen
  3 - clear entire screen and delete all lines in scrollback buffer
  */
  std::string EraseInDisplay(const uint8_t n)
  {
    return csi + std::to_string(n) + 'J';
  }

  /*
  0 - clear from cursor to end of line
  1 - clear from cursoe to beginning of line
  2 - clear entire line
  */
  std::string EraseInLine(const uint8_t n)
  {
    return csi + std::to_string(n) + 'K';
  }

  std::string ScrollUp(const unsigned int n)
  {
    return csi + std::to_string(n) + 'S';
  }

  std::string ScrollDown(const unsigned int n)
  {
    return csi + std::to_string(n) + 'T';
  }

  // Can be numbers 1 through 9.
  //! This function does not appear to do anything on linux terminal. Perhaps fonts need to be added somewhere.
  std::string AlternativeFont(const uint8_t n)
  {
    return csi + std::to_string(n+10) + 'm';
  }

} // namespace ANSI

#endif