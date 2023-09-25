#!/bin/bash

gcc graphicslib/framebuffer.c graphicslib/minimalistic_font.c main.c -Igraphicslib -o test
