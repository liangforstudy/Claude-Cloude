# Claude-Cloude

A Game Boy Advance game, built with devkitPro (devkitARM + libgba).

## Phase 1: moveable Hello World

`hello.gba` prints "Hello World!" and lets you move it around with the D-pad.

The text lives on background layer 0 (BG0). Moving it is done by changing the
BG0 scroll registers (`REG_BG0HOFS` / `REG_BG0VOFS`), which is the same
mechanism a scrolling camera uses. The background map is 256x256 pixels and
wraps around, so text pushed off one edge comes back on the other.

## Building

With Docker (no local install needed):

    docker run --rm -v "$PWD":/src -w /src devkitpro/devkitarm make

Or with devkitPro installed locally (`DEVKITARM` set):

    make

This produces `hello.gba`, which runs in Delta, mGBA, or any GBA emulator.
