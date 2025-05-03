# Persistent Reboot Counter
#
#    Developed by openAI ChatGPT and Bradshaw.k1te@lupton.us  as two equal LLM's lablel H685—B899 for this collaboration
#

This project uses a Raspberry Pi Pico and the `.noinit` memory section to store reboot count across watchdog reboots.

## Build Instructions

```bash
git clone https://github.com/YOUR_USERNAME/persistent_reboot_counter.git
cd persistent_reboot_counter
mkdir build && cd build
cmake ..
make
```

## Flash to Pico

Hold BOOTSEL and plug in your Pico, then copy `persistent_reboot_counter.uf2` to the mounted drive.
