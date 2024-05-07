#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

enum BaseColor {
  Black,
  Red,
  Green,
  Yellow,
  Blue,
  Magenta,
  Cyan,
  White,
};
typedef uint8_t BaseColor;

enum ColorTag {
  Dark,
  Bright,
  Ansi,
};
typedef uint8_t ColorTag;

enum KeyType {
  None,
  Char,
  Enter,
  Escape,
  Backspace,
  Tab,
  Left,
  Right,
  Up,
  Down,
  Insert,
  Delete,
  Home,
  End,
  PageUp,
  PageDown,
  F0,
  F1,
  F2,
  F3,
  F4,
  F5,
  F6,
  F7,
  F8,
  F9,
  F10,
  F11,
  F12,
  Resize,
};
typedef uint16_t KeyType;

typedef struct KeyModifiers {
  bool shift;
  bool control;
  bool alt;
} KeyModifiers;

typedef struct Key {
  KeyType key_type;
  uint8_t code[4];
  struct KeyModifiers modifiers;
} Key;

typedef struct Vec2 {
  unsigned int x;
  unsigned int y;
} Vec2;

typedef struct Effect {
  bool highlight;
  bool underline;
  bool reverse;
  bool blink;
  bool dim;
  bool bold;
  bool italic;
} Effect;

typedef union ColorData {
  BaseColor dark;
  BaseColor bright;
  uint8_t ansi;
} ColorData;

typedef struct Color {
  ColorTag tag;
  union ColorData data;
} Color;

typedef struct ColorPair {
  struct Color fg;
  struct Color bg;
} ColorPair;

void crossterm_init(void);

void crossterm_deinit(void);

void crossterm_clear(void);

struct Key crossterm_poll_event(void);

void crossterm_refresh(void);

void crossterm_print_at(struct Vec2 pos, const uint8_t *str, unsigned int n);

struct Vec2 crossterm_window_size(void);

void crossterm_enable_effect(struct Effect effect);

void crossterm_disable_effect(struct Effect effect);

void crossterm_use_color(struct ColorPair color);
