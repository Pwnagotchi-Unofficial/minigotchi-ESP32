/*
 * Minigotchi: An even smaller Pwnagotchi
 * Copyright (C) 2024 dj1ch
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * minigotchi.h: header files for minigotchi.cpp
 */

#ifndef MINIGOTCHI_H
#define MINIGOTCHI_H

#include "channel.h"
#include "config.h"
#include "deauth.h"
#include "display.h"
#include "frame.h"
#include "parasite.h"
#include "pwnagotchi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "freertos/event_groups.h"
#include <freertos/semphr.h>
#include <Arduino.h>
#include <WiFi.h>
#include <esp_wifi.h>

class Minigotchi {
public:
  static void boot();
  static void finish();
  static void info();
  static void version();
  static void mem();
  static void cpu();
  static void monStart();
  static void monStop();
  static void cycle();
  static void detect();
  static void deauth();
  static void advertise();
  static void loop();
  static void epoch();
  static int addEpoch();
  static int currentEpoch;
private:
  static SemaphoreHandle_t taskSemaphore;
  static void cycleTask(void* param);
  static void detectTask(void* param);
  static void deauthTask(void* param);
  static void advertiseTask(void* param);
};

#endif // MINIGOTCHI_H
