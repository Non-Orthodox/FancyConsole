#ifndef FANCYCONSOLE_PROGRESSBAR_H
#define FANCYCONSOLE_PROGRESSBAR_H

#include <iostream>
#include <cmath>

#include "unicode.hpp"

class ProgressBar
{
public:
  ProgressBar(const unsigned int denominator)
    : denominator_{denominator}, length_{40}, progress_{0}
  {
    if (go_below_) std::cout << '\n';
    Update();
  }
  ProgressBar(const unsigned int denominator, uint16_t terminal_size)
    : denominator_{denominator}, length_{terminal_size}, progress_{0}
  {
    if (go_below_) std::cout << '\n';
    Update();
  }

  void SetColors(const std::string ansi_code)
  {
    bar_colors_ = ansi_code;
    Update();
  }

  void Update() const
  {
    if (go_below_) std::cout << ANSI::CursorUp(1);

    int filled_bars;
    int bar_fragments;
    if (progress_ >= denominator_) {
      filled_bars = length_;
      bar_fragments = 0;
    } else {
      double bars = (progress_ / static_cast<double>(denominator_)) * length_;
      filled_bars = static_cast<int>(bars);
      if (filled_bars < 0) filled_bars = 0;
      bar_fragments = static_cast<int>(fmod(bars,1.0)*8.0);
    }

    std::cout << '\r' + bar_colors_;
    for (uint16_t i = 1; i <= length_; i++) {
      if (i <= filled_bars) { std::cout << "\u2588"; } 
      else if (i == (filled_bars + 1)) { std::cout << Unicode::LowerBlock(bar_fragments); }
      else { std::cout << " "; }
    }

    if (show_percentage_) {
      std::cout << ANSI::reset + " ";
      if (progress_ >= denominator_) {
        std::cout << "100%      \n";
      } else {
        std::cout << static_cast<double>(progress_) / static_cast<double>(denominator_) * 100.0 << "%";
      }
    }
    if (go_below_) std::cout << ANSI::CursorDown(1) << '\r';
    std::cout.flush();
  }

  void operator++(int arg)
  {
    progress_++;
    Update();
  }

  void SetProgress(const uint16_t progress)
  {
    progress_ = progress;
    Update();
  }

private:
  unsigned int denominator_;
  uint16_t length_;
  unsigned int progress_;
  bool show_percentage_ = true;
  bool go_below_ = true;
  std::string bar_colors_;
};

#endif